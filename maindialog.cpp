#include <QtWidgets>
#include <iostream>
#include <string>
#include "maindialog.hpp"
#include "x509.hpp"

mainDialog::mainDialog(QWidget* parent) : QDialog(parent) {
	label = new QLabel(tr("Key size in bits:"));
	instruction = new QLabel(tr("Copy all of the above text, save it to a plaintext file and guard it closely."));
	instruction->hide();
	keySizeSelector = new QComboBox;
	keySizeSelector->addItem("1024");
	keySizeSelector->addItem("2048");
	keySizeSelector->addItem("3072");
	keySizeSelector->addItem("4096");
	label->setBuddy(keySizeSelector);
	keyResultArea = new QTextEdit;
	keyResultArea->setFontFamily("Courier");
	keyResultArea->setMinimumWidth(500);
	keyResultArea->setMinimumHeight(450);
	keyResultArea->setReadOnly(true);
	generateKeyButton = new QPushButton(tr("&Generate key"));
	quitButton = new QPushButton(tr("&Close"));

	connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(generateKeyButton, SIGNAL(clicked()), this, SLOT(generateKey()));
	connect(keySizeSelector, SIGNAL(currentIndexChanged(int)), this, SLOT(generateKey()));
	setWindowTitle(tr("Generate RSA private key"));

	QHBoxLayout* topLeftLayout = new QHBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(keySizeSelector);

	QVBoxLayout* leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLeftLayout);
	leftLayout->addWidget(keyResultArea);
	leftLayout->addWidget(instruction);

	QVBoxLayout* rightLayout = new QVBoxLayout;
	rightLayout->addStretch();
	rightLayout->addWidget(generateKeyButton);
	rightLayout->addWidget(quitButton);

	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);
}

void mainDialog::generateKey() {
	X509* crypto = new X509;
	std::string pemKey;
	pemKey = crypto->generatePrivateKey(keySizeSelector->currentText().toInt());
	keyResultArea->setText(pemKey.c_str());
	instruction->show();
	delete crypto;
}