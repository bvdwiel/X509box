/**
 * Private key
 **/

#ifndef PRIVKEY_H
#define PRIVKEY_H

#include <exception>
#include <gnutls/gnutls.h>
#include <gnutls/x509.h>
#include <gnutls/abstract.h>
#include <iostream>
#include <string>

class privkey {
public:
	privkey();
	~privkey();
	std::string getPem();
	void generate(int keySize);
	void generate(int keySize, std::string passPhrase);
	void encrypt(std::string passPhrase);
protected:
private:
	bool isEncrypted;
	std::string passPhrase;
	gnutls_x509_privkey_t keyData;
};

#endif /* PRIVKEY_H */
