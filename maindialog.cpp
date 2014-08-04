
#include "maindialog.hpp"

mainDialog::mainDialog(QWidget* parent) : QDialog(parent) {
	/* Tab container */
	tabs = new QTabWidget;
	tabs->addTab(new dataTab(parent), tr("Certificate data"));
	tabs->addTab(new keyTab(parent), tr("Private key"));
	tabs->addTab(new csrTab(parent), tr("Signing request"));
	tabs->addTab(new p12Tab(parent), tr("PFX generator"));

	/* Labels
	keyLabel = new QLabel(tr("Your private key:"));
	csrLabel = new QLabel(tr("Your certificate signing request:"));

	/* Controls

	keyField = new QTextEdit;
	csrField = new QTextEdit;
	generateCsrButton = new QPushButton(tr("Generate CSR"));
	quitButton = new QPushButton(tr("Quit"));

	/* Set up controls and labels


	keyLabel->setBuddy(keyField);
	csrLabel->setBuddy(csrField);


	QVBoxLayout* privateKeyLayout = new QVBoxLayout;
	privateKeyLayout->addLayout(keyLayout);

	QVBoxLayout* csrLayout = new QVBoxLayout;
	csrLayout->addWidget(csrLabel);
	csrLayout->addWidget(csrField);
	csrLayout->addLayout(buttonsLayout); */

	QVBoxLayout* mainLayout = new QVBoxLayout;
	//mainLayout->addLayout(metaFieldsLayout);
	//mainLayout->addLayout(privateKeyLayout);
	//mainLayout->addLayout(csrLayout);
	quitButton = new QPushButton(tr("Quit"));
	mainLayout->addWidget(tabs);
	mainLayout->addWidget(quitButton);
	setLayout(mainLayout);

	connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
	//connect(generateCsrButton, SIGNAL(clicked()), this, SLOT(generateKey()));
	//connect(keySizeSelector, SIGNAL(currentIndexChanged(int)), this, SLOT(generateKey()));
	//setWindowTitle(tr("X509box"));
}

void mainDialog::generateKey() {
	/* X509* crypto = new X509;
	std::string pemKey;
	pemKey = crypto->generatePrivateKey(keySizeSelector->currentText().toInt());
	keyField->setText(pemKey.c_str());
	delete crypto; */
}
