#include "keytab.hpp"
#include "maindialog.hpp"

keyTab::keyTab(mainDialog* parent) {
	keyField = new QTextEdit();
	keyLabel = new QLabel(tr("Your private key:"));
	passPhraseLabel = new QLabel(tr("Passphrase to protect your key:"));
	passPhraseField = new QTextEdit();
	generateKeyButton = new QPushButton(tr("Generate key"));
	loadKeyButton = new QPushButton(tr("Load key"));
	saveKeyButton = new QPushButton(tr("Save key"));

	/* Configure controls */
	keyField->setFontFamily("Courier");
	keyField->setMinimumWidth(getKeyWidgetWidth(keyField));
	keyField->setMinimumHeight(450);
	keyField->setReadOnly(true);
	saveKeyButton->setEnabled(false);

	/* Arrange widgets into layouts */
	QHBoxLayout* buttonsLayout = new QHBoxLayout;
	buttonsLayout->addWidget(generateKeyButton);
	buttonsLayout->addWidget(loadKeyButton);
	buttonsLayout->addWidget(saveKeyButton);

	QVBoxLayout* keyLayout = new QVBoxLayout;
	keyLayout->addWidget(keyLabel);
	keyLayout->addWidget(keyField);
	keyLayout->addWidget(passPhraseLabel);
	keyLayout->addWidget(passPhraseField);
	keyLayout->addLayout(buttonsLayout);
	setLayout(keyLayout);

	/* Signal/slot collections */
	connect(generateKeyButton, SIGNAL(clicked()), this, SLOT(generateKey()));
	connect(loadKeyButton, SIGNAL(clicked()), this, SLOT(loadFile()));
	connect(saveKeyButton, SIGNAL(clicked()), this, SLOT(saveFile()));

	myCrypto = parent->crypto;
	myOid = parent->oid;
}

keyTab::~keyTab() {
	delete myCrypto;
	delete myOid;
}

int keyTab::getKeyWidgetWidth(QTextEdit* widget) {
    QFontMetrics m (widget->font());
    QChar c('W');
    int rowWidth = (m.width(c) * 40);
    return rowWidth;
}

void keyTab::loadFile() {
    try {
        QString fileName = QFileDialog::getOpenFileName(this,
	    tr("Load RSA private key"), "",
	    tr("RSA private key (*.txt);;All files (*)"));
        if ( fileName.isEmpty()) {
	    throw("You should select a file to load the private key from.");
        }
	else {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                throw("Unable to open file.");
            }
            QTextStream in(&file);
	    loadedKey = in.readAll();
            if ( myCrypto->validateRsaKey(loadedKey.toStdString()) == false ) {
		throw("The file you opened does not contain a valid key, or the key is encrypted. X509box does not support encrypted keys.");
            }
            myCrypto->setPrivateKey(loadedKey.toStdString());
            keyField->setText(loadedKey);
        }
    }
    catch(const char* e) {
	QMessageBox::warning(this, tr("Error"), e);
	return;
    }
}

void keyTab::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this,
         tr("Save RSA private key"), "",
         tr("RSA private key (*.txt);;All files (*)"));
    if (fileName.isEmpty()) {
        return;
    }
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(this, tr("Unable to open file"),
            file.errorString());
            return;
        }
        QTextStream out(&file);
        out << keyField->toPlainText();
    }
}

void keyTab::generateKey() {
	try {
		QString keyData = QString::fromUtf8(myCrypto->generatePrivateKey(myOid->getKeySize(),myOid->getPassPhrase()).c_str());
		keyField->setText(keyData);
		saveKeyButton->setEnabled(true);
	}
	catch(const char* e) {
		QMessageBox::critical(this, tr("Error"), e);
	}
}
