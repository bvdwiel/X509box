#ifndef PKCS12_H
#define PKCS12_H

#include <gnutls/gnutls.h>
#include <gnutls/x509.h>
#include <gnutls/abstract.h>
#include <gnutls/pkcs12.h>
#include <exception>
#include <string>
#include <vector>

class pkcs12 {
public:
	void addChainCertificate(std::string certificate);
	void removeChainCertificate(std::string thumbPrint);
	void addPrivateKey(std::string privateKey);
	void addCertificate(std::string certificate);
	void generateBundle();
	void saveBundleToFile(std::string fileName);
protected:
	std::vector<std::string> chain;
	std::string privateKey;
	std::string certificate;

	std::string getThumbPrint(std::string* certificate);
};

#endif /*PKCS12_H*/
