#include "pkcs12.hpp"

pkcs12::pkcs12() {
	gnutls_pkcs12_init(&pfx);
	gnutls_pkcs12_bag_init(&bag);
}

pkcs12::~pkcs12() {
	gnutls_pkcs12_bag_deinit(bag);
	gnutls_pkcs12_deinit(pfx);
}

void pkcs12::addChainCertificate(std::string certificate) {
	gnutls_x509_crt_t cert;
	gnutls_x509_crt_init(&cert);
	gnutls_datum_t pemdata;

	//Load PEM certificate into GNUTLS data structures
	pemdata.size = certificate.size();
	pemdata.data = (unsigned char*)certificate.c_str();
	gnutls_x509_crt_import(cert, &pemdata, GNUTLS_X509_FMT_PEM);

	//Stick the cert in the bag and clean up
	gnutls_pkcs12_bag_set_crt(bag, cert);
	gnutls_x509_crt_deinit(cert);
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

std::string pkcs12::getThumbPrint(std::string* certificate) {
	return("NOP");
}
