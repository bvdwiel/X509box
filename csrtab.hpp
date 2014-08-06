#ifndef CSRTAB_H
#define CSRTAB_H

#include <QtWidgets>
#include <QFileDialog>
#include "x509.hpp"

class mainDialog;

class csrTab : public QWidget {
	Q_OBJECT
public:
	csrTab(mainDialog* parent);
private slots:
    void saveFile();
private:
	QLabel* csrLabel;
	QTextEdit* csrField;
	QPushButton* generateCsrButton;
	QPushButton* saveCsrButton;
	X509* myCrypto;
};

#endif /*CSRTAB*/
