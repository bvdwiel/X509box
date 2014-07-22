#include <QtWidgets>
#include <iostream>
#include <string>
#include "keydialog.hpp"
#include "x509.hpp"

keyDialog::keyDialog(QWidget* parent) : QDialog(parent) {
	label = new QLabel(tr("Key &size in bits:"));
	keySizeSelector = new QComboBox;
	label->setBuddy(keySizeSelector);
	keyResultArea = new QTextEdit;
	keyResultArea->setFontFamily("Courier");
	generateKeyButton = new QPushButton(tr("&Generate key"));
	quitButton = new QPushButton(tr("&Quit"));

	connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(generateKeyButton, SIGNAL(clicked()), this, SLOT(generateKey()));
	setWindowTitle(tr("Generate RSA private key"));

	QVBoxLayout* leftLayout = new QVBoxLayout;
	leftLayout->addWidget(keySizeSelector);
	leftLayout->addWidget(keyResultArea);

	QVBoxLayout* rightLayout = new QVBoxLayout;
	rightLayout->addWidget(generateKeyButton);
	rightLayout->addWidget(quitButton);

	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);
}

void keyDialog::generateKey() {
	X509* crypto = new X509;
	std::string pemKey;
	pemKey = crypto->generatePrivateKey();
	keyResultArea->setText(pemKey.c_str());
	delete crypto;
}
