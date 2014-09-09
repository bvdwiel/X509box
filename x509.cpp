#include "x509.hpp"

X509::X509() {
	gnutls_global_init();
	objectID = NULL;
	objectID = new OID;
}

X509::~X509() {
	gnutls_global_deinit();
	delete objectID;
}

void X509::debug() {
	std::cout << this->pemCSR << std::endl;
	std::cout << this->privateKey << std::endl;
}

std::string X509::generateCSR() {
	return ( this->generateCSR(this->objectID));
}

std::string X509::generateCSR(OID* oid) {
	if ( this->privateKey.size() == 0) {
		throw ( "Private key not present. Please generate it first." );
	}
	if ( this->privateKey.size() < 1674 ) { // 1674 is a magic number. PEM-encoded 2048-bit keys report back 1675 for .size().
		throw ( "FATAL ERROR: A private key must be at least 2048 bits in size." );
	}
	if ( oid == NULL ) {
		throw ( "FATAL ERROR: Your CSR's OID wasn't set at creation. This is a bug. Please alert author." );
	}
	std::string country = oid->getCountryName();
	unsigned char csrBuffer[16 * 1024];
	size_t csrBufferSize = sizeof(csrBuffer);
	gnutls_x509_crq_t CSR;
	gnutls_x509_privkey_t tempKey;
	gnutls_datum_t pemdata;
	pemdata.size = this->privateKey.size();
	pemdata.data = (unsigned char*)this->privateKey.c_str();

	if ( gnutls_x509_privkey_init(&tempKey) < 0 ) {
		throw( "FATAL ERROR: failed to init temporary privkey structure while generating CSR.");
	}
	if ( gnutls_x509_privkey_import2(tempKey, &pemdata, GNUTLS_X509_FMT_PEM, NULL, 0) < 0 ) {
		throw ( "FATAL ERROR: failed to import private key while generating CSR." );
	}
	if ( gnutls_x509_crq_init(&CSR) < 0) {
		throw ( "FATAL ERROR: failed to initialize CSR struct." );
	}
	/* CountryName is optional */
	if ( oid->getCountryName().size() > 0 ) {
		if ( gnutls_x509_crq_set_dn_by_oid(CSR, GNUTLS_OID_X520_COUNTRY_NAME, 0, oid->getCountryName().c_str(), oid->getCountryName().size()) < 0 ) {
			throw ( "FATAL ERROR: Failed to set CountryName attribute." );
		}
	}
	/* StateOrProvinceName is optional */
	if ( oid->getStateOrProvinceName().size() > 0 ) {
		if ( gnutls_x509_crq_set_dn_by_oid(CSR, GNUTLS_OID_X520_STATE_OR_PROVINCE_NAME, 0, oid->getStateOrProvinceName().c_str(), oid->getStateOrProvinceName().size()) != 0 ) {
			throw ( "FATAL ERROR: Failed to set StateOrProvinceName attribute." );
		}
	}
	/* LocalityName is optional */
	if ( oid->getLocalityName().size() > 0 ) {
		if ( gnutls_x509_crq_set_dn_by_oid(CSR, GNUTLS_OID_X520_LOCALITY_NAME, 0, oid->getLocalityName().c_str(), oid->getLocalityName().size()) < 0 ) {
			throw ( "FATAL ERROR: Failed to set LocalityName attribute." );
		}
	}
	/* OrganizationName is optional */
	if ( oid->getOrganizationName().size() > 0 ) {
		if ( gnutls_x509_crq_set_dn_by_oid(CSR, GNUTLS_OID_X520_ORGANIZATION_NAME, 0, oid->getOrganizationName().c_str(), oid->getOrganizationName().size()) < 0 ) {
			throw ( "FATAL ERROR: Failed to set OrganizationName attribute." );
		}
	}
	/* OrganizationalUnitName is optional */
	if ( oid->getOrganizationalUnitName().size() > 0 ) {
		if ( gnutls_x509_crq_set_dn_by_oid(CSR, GNUTLS_OID_X520_ORGANIZATIONAL_UNIT_NAME, 0, oid->getOrganizationalUnitName().c_str(), oid->getOrganizationalUnitName().size()) < 0 ) {
			throw ( "FATAL ERROR: Failed to set OrganizationalUnitName attribute." );
		}
	}
	/* CommonName is mandatory */
	if ( oid->getCommonName().size() <= 0 ) {
		throw( "FATAL ERROR: CSR cannot be generated without a CommonName." );
	}
	if ( gnutls_x509_crq_set_dn_by_oid(CSR, GNUTLS_OID_X520_COMMON_NAME, 0, oid->getCommonName().c_str(),oid->getCommonName().size()) < 0 ) {
		throw ( "FATAL ERROR: failed to set commonName attribute." );
	}
	if ( gnutls_x509_crq_set_version(CSR, 1) < 0 ) {
		throw ( "FATAL ERROR: failed to set CSR version." );
	}
	if ( gnutls_x509_crq_set_key(CSR, tempKey) < 0 ) {
		throw ( "FATAL ERROR: failed to associate private key with CSR." );
	}
	if ( gnutls_x509_crq_sign2(CSR, tempKey, GNUTLS_DIG_SHA256, 0) != 0 ) {
		throw ( "FATAL ERROR: failed to sign CSR." );
	}
	if ( gnutls_x509_crq_export(CSR, GNUTLS_X509_FMT_PEM, csrBuffer, &csrBufferSize) < 0 ) {
		throw ( "FATAL ERROR: failed to export CSR to PEM format." );
	}
	std::string pemCsrBuffer((const char*) csrBuffer);
	this->pemCSR = pemCsrBuffer;
	return pemCsrBuffer;
}

std::string X509::generatePrivateKey() {
	/* Generate a sane default of 2048 bits if you don't care */
	return(this->generatePrivateKey(2048));
}

std::string X509::generatePrivateKey(unsigned int numBits) {
	if (numBits < 1024) {
		throw("FATAL ERROR: Using insecure keylength < 1024 bits.");
	}
	gnutls_x509_privkey_t myPrivateKey;
	unsigned char buffer[10 * 1024];
	size_t buffer_size = sizeof(buffer);
	if ( gnutls_x509_privkey_init(&myPrivateKey) != 0 ) {
		throw ( "FATAL ERROR: failed to initialize the private key object." );
	}
	if ( gnutls_x509_privkey_generate(myPrivateKey, GNUTLS_PK_RSA, numBits, 0) != 0 ) {
		throw ( "FATAL ERROR: failed to generate the private key." );
	}
	if ( gnutls_x509_privkey_export(myPrivateKey, GNUTLS_X509_FMT_PEM, buffer, &buffer_size) != 0 ) {
		throw ( "FATAL ERROR: failed to export the private key to PEM format." );
	}
	std::string pemBuffer((const char*) buffer);
	gnutls_x509_privkey_deinit(myPrivateKey);
	this->privateKey = pemBuffer;
	return pemBuffer;
}

bool X509::validateRsaKey(std::string rsaKey) {
	int res;
	gnutls_x509_privkey_t myPrivateKey;
	gnutls_datum_t pem;
	size_t size;

	pem.data = (unsigned char*)rsaKey.c_str();
	pem.size = rsaKey.size();

	if ( gnutls_x509_privkey_init(&myPrivateKey) != 0 ) {
		throw ( "FATAL ERROR: failed to initialize the private key object. This is a bug. Please alert author." );
	}

	res = gnutls_x509_privkey_import ( myPrivateKey, &pem, GNUTLS_X509_FMT_PEM );
	gnutls_x509_privkey_deinit ( myPrivateKey );

	if ( res == 0 ) {
		return( true );
	}
	return ( false );
}
