#include "csrtab.hpp"

csrTab::csrTab (QWidget* parent) {
    /* Initialize controls */
	csrLabel = new QLabel(tr("Your certificate signing request (CSR):"));
	csrField = new QTextEdit();
	generateCsrButton = new QPushButton(tr("Generate CSR"));

	/* Configure controls */
    csrField->setFontFamily("Courier");
	csrField->setMinimumWidth(500);
	csrField->setMinimumHeight(450);
	csrField->setReadOnly(true);

	/* Arrange widgets into layouts */
    QVBoxLayout* keyLayout = new QVBoxLayout;
	keyLayout->addWidget(csrLabel);
	keyLayout->addWidget(csrField);
    keyLayout->addWidget(generateCsrButton);
    setLayout(keyLayout);
}
