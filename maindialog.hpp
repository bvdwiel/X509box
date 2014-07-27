/**
 * X509box dialog for CSR generation
 **/

#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

class QComboBox;
class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;

class mainDialog : public QDialog {
	Q_OBJECT

public:
	mainDialog(QWidget* parent = 0);
private slots:
	void generateKey();
private:
	QLabel* countryLabel;
	QLineEdit* countryField;
	QLabel* stateLabel;
	QLineEdit* stateField;
	QLabel* localityLabel;
	QLineEdit* localityField;
	QLabel* organizationLabel;
	QLineEdit* organizationField;
	QLabel* organizationalUnitLabel;
	QLineEdit* organizationalUnitField;
	QLabel* commonNameLabel;
	QLineEdit* commonNameField;
	QLabel* keySizeLabel;
	QComboBox* keySizeSelector;
	QLabel* keyLabel;
	QTextEdit* keyField;
	QLabel* csrLabel;
	QTextEdit* csrField;
	QPushButton* generateCsrButton;
	QPushButton* quitButton;
};

#endif /*MAINDIALOG_H*/
