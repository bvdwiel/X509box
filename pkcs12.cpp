#include "pkcs12.hpp"

void pkcs12::addChainCertificate(std::string certificate) {
	this->chain.push_back(certificate);
}

void pkcs12::addPrivateKey(std::string privateKey) {
	this->privateKey = privateKey;
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
