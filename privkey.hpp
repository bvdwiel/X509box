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
	privkey(int keySize);
	~privkey();
	std::string getPem();
	void generate(int keySize);
	void encrypt(std::string passPhrase);
protected:
private:
	bool isEncrypted;
	std::string passPhrase;
	std::string pemKey;
	gnutls_x509_privkey_t keyData;
};

#endif /* PRIVKEY_H */
