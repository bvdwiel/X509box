#include "pkcs12.hpp"

pkcs12::pkcs12() {
	gnutls_pkcs12_init(&pfx);
	gnutls_pkcs12_bag_init(&bag);
}

pkcs12::~pkcs12() {
	gnutls_pkcs12_bag_deinit(bag);
	gnutls_pkcs12_deinit(pfx);
}

int pkcs12::addChainCertificate(std::string certificate) {
	int res = 0;
	gnutls_x509_crt_t cert;
	gnutls_x509_crt_init(&cert);
	gnutls_datum_t pemdata;

	//Load PEM certificate into GNUTLS data structures
	pemdata.size = certificate.size();
	pemdata.data = (unsigned char*)certificate.c_str();
	if ( gnutls_x509_crt_import(cert, &pemdata, GNUTLS_X509_FMT_PEM) != 0) {
		throw("FATAL: Failed to prepare certificate for inclusion in PFX");
	}

	//Stick the cert in the bag and clean up
	res = gnutls_pkcs12_bag_set_crt(bag, cert);
	if ( res < 0 ) {
		throw("FATAL: Failed to insert certificate into PFX.");
	}
	gnutls_x509_crt_deinit(cert);
	return(res);
}

void pkcs12::addPrivateKey(std::string privateKeyPEM) {
	//NOP: Convert PEM and store result as GNUTLS datatype
}

void pkcs12::addCertificate(std::string certificate) {
	this->certificate = certificate;
}

void generateBundle() {
	//NOP: Generate PKCS12 bundle here
}

void saveBundleToFile(std::string fileName) {
	//NOP: Save to file here
}

std::string pkcs12::exportBundle(const char* format) {
	std::string pemData;
	return(pemData);
}

std::string pkcs12::getThumbPrint(std::string* certificate) {
	return("NOP");
}
