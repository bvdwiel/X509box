/**
 * X509box dialog for CSR generation
 **/

#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

class QComboBox;
class QLabel;
class QTextEdit;
class QPushButton;

class mainDialog : public QDialog {
	Q_OBJECT

public:
	mainDialog(QWidget* parent = 0);
private slots:
	void generateKey();
private:
	QLabel* label;
	QLabel* instruction;
	QComboBox* keySizeSelector;
	QTextEdit* keyResultArea;
	QPushButton* generateKeyButton;
	QPushButton* quitButton;
};

#endif /*MAINDIALOG_H*/
