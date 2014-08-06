#include "keytab.hpp"
#include "maindialog.hpp"

keyTab::keyTab(mainDialog* parent) {
    keyField = new QTextEdit();
    keyLabel = new QLabel(tr("Your private key:"));
    generateKeyButton = new QPushButton(tr("Generate key"));
    saveKeyButton = new QPushButton(tr("Save key"));

    /* Configure controls */
	keyField->setFontFamily("Courier");
	keyField->setMinimumWidth(500);
	keyField->setMinimumHeight(450);
	keyField->setReadOnly(true);
	saveKeyButton->setEnabled(false);

    /* Arrange widgets into layouts */
    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(generateKeyButton);
    buttonsLayout->addWidget(saveKeyButton);

    QVBoxLayout* keyLayout = new QVBoxLayout;
	keyLayout->addWidget(keyLabel);
	keyLayout->addWidget(keyField);
    keyLayout->addLayout(buttonsLayout);
    setLayout(keyLayout);

    /* Signal/slot collections */
    connect(generateKeyButton, SIGNAL(clicked()), this, SLOT(generateKey()));
    connect(saveKeyButton, SIGNAL(clicked()), this, SLOT(saveFile()));

	myCrypto = parent->crypto;
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
    QString keyData = QString::fromUtf8(myCrypto->generatePrivateKey().c_str());
    keyField->setText(keyData);
    saveKeyButton->setEnabled(true);
}
