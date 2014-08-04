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
    QVBoxLayout* csrLayout = new QVBoxLayout;
	csrLayout->addWidget(csrLabel);
	csrLayout->addWidget(csrField);
    csrLayout->addWidget(generateCsrButton);
    setLayout(csrLayout);
}
