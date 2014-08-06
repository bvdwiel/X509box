#ifndef CSRTAB_H
#define CSRTAB_H

#include <exception>
#include <QtWidgets>
#include <QFileDialog>
#include "oid.hpp"
#include "x509.hpp"

class mainDialog;

class csrTab : public QWidget {
	Q_OBJECT
public:
	csrTab(mainDialog* parent);
private slots:
	void saveFile();
	void generateCsr();
private:
	QLabel* csrLabel;
	QTextEdit* csrField;
	QPushButton* generateCsrButton;
	QPushButton* saveCsrButton;
	OID* myOid;
	X509* myCrypto;
};

#endif /*CSRTAB*/
