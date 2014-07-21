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
	if ( this->privateKey.size() < 1024 ) {
		throw ( "FATAL ERROR: A CSR cannot exist without a valid private key. Generate one first." );
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
	gnutls_x509_crq_set_dn_by_oid(CSR, GNUTLS_OID_X520_COUNTRY_NAME, 0, oid->getCountryName().c_str(), oid->getCountryName().size());
	gnutls_x509_crq_set_dn_by_oid(CSR, GNUTLS_OID_X520_LOCALITY_NAME, 0, oid->getLocalityName().c_str(), oid->getLocalityName().size());
	gnutls_x509_crq_set_dn_by_oid(CSR, GNUTLS_OID_X520_COMMON_NAME, 0, "eleventyone.party.com",21);
	gnutls_x509_crq_set_version(CSR, 1);
	gnutls_x509_crq_set_key(CSR, tempKey);
	gnutls_x509_crq_sign2(CSR, tempKey, GNUTLS_DIG_SHA1, 0);
	gnutls_x509_crq_export(CSR, GNUTLS_X509_FMT_PEM, csrBuffer, &csrBufferSize);
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
	gnutls_x509_privkey_init(&myPrivateKey);
	gnutls_x509_privkey_generate(myPrivateKey, GNUTLS_PK_RSA, numBits, 0);
	gnutls_x509_privkey_export(myPrivateKey, GNUTLS_X509_FMT_PEM, buffer, &buffer_size);
	std::string pemBuffer((const char*) buffer);
	gnutls_x509_privkey_deinit(myPrivateKey);
	this->privateKey = pemBuffer;
	return pemBuffer;
}
