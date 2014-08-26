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
	pkcs12();
	~pkcs12();
	int addChainCertificate(std::string certificate);
	void removeChainCertificate(std::string thumbPrint);
	void addPrivateKey(std::string privateKey);
	void addCertificate(std::string certificate);
	void generateBundle();
	void saveBundleToFile(std::string fileName);
protected:
	std::vector<gnutls_datum_t*> certs;
	std::string certificate;
	gnutls_pkcs12_bag_t bag;
	gnutls_pkcs12_t pfx;
	gnutls_x509_privkey_t privateKey;

	std::string getThumbPrint(std::string* certificate);
};

#endif /*PKCS12_H*/
