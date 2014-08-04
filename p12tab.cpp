#include "p12tab.hpp"

p12Tab::p12Tab(QWidget* parent) {
    messageLabel = new QLabel(tr("PKCS12 not yet implemented in crypto class X509. Will be added in future revision."));
    QVBoxLayout* p12Layout = new QVBoxLayout;
	p12Layout->addWidget(messageLabel);
	setLayout(p12Layout);
}
