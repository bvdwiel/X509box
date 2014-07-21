#include "x509.hpp"

int main() {
X509* crypto;
crypto = new X509;
std::cout << crypto->generatePrivateKey(2048) << std::endl;
delete ( crypto );
return ( 0 );
}

