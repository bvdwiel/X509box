#include "csrtab.hpp"
#include "maindialog.hpp"

csrTab::csrTab (mainDialog* parent) {
	/* Initialize controls */
	csrLabel = new QLabel(tr("Your certificate signing request (CSR):"));
	csrField = new QTextEdit();
	generateCsrButton = new QPushButton(tr("Generate CSR"));
	saveCsrButton = new QPushButton(tr("Save CSR"));

	/* Configure controls */
	csrField->setFontFamily("Courier");
	csrField->setMinimumWidth(500);
	csrField->setMinimumHeight(450);
	csrField->setReadOnly(true);
	saveCsrButton->setEnabled(false);

	/* Arrange widgets into layouts */
	QHBoxLayout* buttonsLayout = new QHBoxLayout;
	buttonsLayout->addWidget(generateCsrButton);
	buttonsLayout->addWidget(saveCsrButton);

	QVBoxLayout* csrLayout = new QVBoxLayout;
	csrLayout->addWidget(csrLabel);
	csrLayout->addWidget(csrField);
	csrLayout->addLayout(buttonsLayout);
	setLayout(csrLayout);

	/* Signal/slot collections */
	connect(saveCsrButton, SIGNAL(clicked()), this, SLOT(saveFile()));
	connect(generateCsrButton, SIGNAL(clicked()), this, SLOT(generateCsr()));

	myOid = parent->oid;
	myCrypto = parent->crypto;
}

void csrTab::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this,
         tr("Save Certificate Signing Request"), "",
         tr("Certificate Signing Request (*.txt);;All files (*)"));
    if (fileName.isEmpty()) {
        return;
    }
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Unable to open file"),
            file.errorString());
            return;
        }
        QTextStream out(&file);
        out << csrField->toPlainText();
    }
}

void csrTab::generateCsr() {
	myOid->debug();
	try {
	QString csrData = QString::fromUtf8(myCrypto->generateCSR(myOid).c_str());
	csrField->setText(csrData);
	saveCsrButton->setEnabled(true);}
	catch(const char* e) {
		QMessageBox::warning(this, tr("Error"), e);
	}
}
