#include <QtWidgets>
#include <iostream>
#include <string>
#include "maindialog.hpp"
#include "x509.hpp"

mainDialog::mainDialog(QWidget* parent) : QDialog(parent) {
	/* Labels */
	countryLabel = new QLabel(tr("Country:"));
	stateLabel = new QLabel(tr("State or province:"));
	localityLabel = new QLabel(tr("City or locality:"));
	organizationLabel = new QLabel(tr("Organization:"));
	organizationalUnitLabel = new QLabel(tr("Organizational unit:"));
	commonNameLabel = new QLabel(tr("Hostname or common name:"));
	keySizeLabel = new QLabel(tr("Key size in bits:"));
	keyLabel = new QLabel(tr("Your private key:"));
	csrLabel = new QLabel(tr("Your certificate signing request:"));

	/* Controls */
	countryField = new QLineEdit;
	stateField = new QLineEdit;
	localityField = new QLineEdit;
	organizationField = new QLineEdit;
	organizationalUnitField = new QLineEdit;
	commonNameField = new QLineEdit;
	keySizeSelector = new QComboBox;
	keyField = new QTextEdit;
	csrField = new QTextEdit;
	generateCsrButton = new QPushButton(tr("Generate CSR"));
	quitButton = new QPushButton(tr("Quit"));

	/* Set up controls and labels */
	keySizeSelector->addItem("1024");
	keySizeSelector->addItem("2048");
	keySizeSelector->addItem("3072");
	keySizeSelector->addItem("4096");
	keySizeSelector->addItem("8192");
	countryLabel->setBuddy(countryField);
	stateLabel->setBuddy(stateField);
	localityLabel->setBuddy(localityField);
	organizationLabel->setBuddy(organizationField);
	commonNameLabel->setBuddy(commonNameField);
	keySizeLabel->setBuddy(keySizeSelector);
	keyLabel->setBuddy(keyField);
	csrLabel->setBuddy(csrField);
	keyField->setFontFamily("Courier");
	keyField->setMinimumWidth(500);
	keyField->setMinimumHeight(450);
	keyField->setReadOnly(true);
	csrField->setFontFamily("Courier");
	csrField->setMinimumWidth(500);
	csrField->setMinimumHeight(450);
	csrField->setReadOnly(true);

	/* Group controls and labels into layouts*/
	QHBoxLayout* countryLayout = new QHBoxLayout;
	countryLayout->addWidget(countryLabel);
	countryLayout->addWidget(countryField);

	QHBoxLayout* stateLayout = new QHBoxLayout;
	stateLayout->addWidget(stateLabel);
	stateLayout->addWidget(stateField);

	QHBoxLayout* localityLayout = new QHBoxLayout;
	localityLayout->addWidget(localityLabel);
	localityLayout->addWidget(localityField);

	QHBoxLayout* organizationLayout = new QHBoxLayout;
	organizationLayout->addWidget(organizationLabel);
	organizationLayout->addWidget(organizationField);

	QHBoxLayout* organizationalUnitLayout = new QHBoxLayout;
	organizationalUnitLayout->addWidget(organizationalUnitLabel);
	organizationalUnitLayout->addWidget(organizationalUnitField);

	QHBoxLayout* commonNameLayout = new QHBoxLayout;
	commonNameLayout->addWidget(commonNameLabel);
	commonNameLayout->addWidget(commonNameField);

	QHBoxLayout* keySizeLayout = new QHBoxLayout;
	keySizeLayout->addWidget(keySizeLabel);
	keySizeLayout->addWidget(keySizeSelector);

	QVBoxLayout* metaFieldsLayout = new QVBoxLayout;
	metaFieldsLayout->addLayout(countryLayout);
	metaFieldsLayout->addLayout(stateLayout);
	metaFieldsLayout->addLayout(localityLayout);
	metaFieldsLayout->addLayout(organizationLayout);
	metaFieldsLayout->addLayout(organizationalUnitLayout);
	metaFieldsLayout->addLayout(commonNameLayout);
	metaFieldsLayout->addLayout(keySizeLayout);
	metaFieldsLayout->addStretch();

	QVBoxLayout* keyLayout = new QVBoxLayout;
	keyLayout->addWidget(keyLabel);
	keyLayout->addWidget(keyField);

	QVBoxLayout* privateKeyLayout = new QVBoxLayout;
	privateKeyLayout->addLayout(keyLayout);

	QHBoxLayout* buttonsLayout = new QHBoxLayout;
	buttonsLayout->addWidget(generateCsrButton);
	buttonsLayout->addWidget(quitButton);

	QVBoxLayout* csrLayout = new QVBoxLayout;
	csrLayout->addWidget(csrLabel);
	csrLayout->addWidget(csrField);
	csrLayout->addLayout(buttonsLayout);

	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->addLayout(metaFieldsLayout);
	mainLayout->addLayout(privateKeyLayout);
	mainLayout->addLayout(csrLayout);
	setLayout(mainLayout);

	connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(generateCsrButton, SIGNAL(clicked()), this, SLOT(generateKey()));
	//connect(keySizeSelector, SIGNAL(currentIndexChanged(int)), this, SLOT(generateKey()));
	setWindowTitle(tr("X509box"));
}

void mainDialog::generateKey() {
	X509* crypto = new X509;
	std::string pemKey;
	pemKey = crypto->generatePrivateKey(keySizeSelector->currentText().toInt());
	keyField->setText(pemKey.c_str());
	delete crypto;
}
