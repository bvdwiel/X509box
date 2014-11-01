
#include "maindialog.hpp"

mainDialog::mainDialog(QWidget* parent) : QDialog(parent) {
	crypto = new X509;
	oid = new OID;
	/* Tab container */
	tabs = new QTabWidget;
	tabs->addTab(new dataTab(this), tr("Certificate data"));
	tabs->addTab(new keyTab(this), tr("Private key"));
	tabs->addTab(new csrTab(this), tr("Signing request"));
	tabs->addTab(new p12Tab(this), tr("PFX generator"));
        tabs->addTab(new aboutTab(this), tr("About"));

	QVBoxLayout* mainLayout = new QVBoxLayout;
	quitButton = new QPushButton(tr("Quit"));
	mainLayout->addWidget(tabs);
	mainLayout->addWidget(quitButton);
	setLayout(mainLayout);

	connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
}
