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
