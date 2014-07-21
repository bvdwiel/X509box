#include "x509.hpp"
#include <exception>

int main() {
X509* crypto;
crypto = new X509;
try {
	crypto->generatePrivateKey();
	crypto->generateCSR();
	crypto->debug();
}
catch(const char* e) {
	std::cerr << e << std::endl;
	delete ( crypto );
	return ( 1 );
}
delete ( crypto );
return ( 0 );
}

