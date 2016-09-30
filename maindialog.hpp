/**
 * X509box dialog for CSR generation
 **/

#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QtWidgets>
#include <iostream>
#include <string>
#include <QDialog>
#include "oid.hpp"
#include "x509.hpp"
#include "csrtab.hpp"
#include "datatab.hpp"
#include "keytab.hpp"
#include "abouttab.hpp"

class QComboBox;
class QLabel;
class QLineEdit;
class QTabWidget;
class QTextEdit;
class QPushButton;

class mainDialog : public QDialog {
	Q_OBJECT

public:
	mainDialog(QWidget* parent = 0);
	X509* crypto;
	OID* oid;
private slots:
private:
	QLabel* keyLabel;
	QTextEdit* keyField;
	QTabWidget* tabs;
	QPushButton* quitButton;
};

#endif /*MAINDIALOG_H*/
