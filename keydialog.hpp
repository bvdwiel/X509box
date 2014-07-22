/**
 * X509box dialog for RSA key parameters
 **/

#ifndef KEYDIALOG_H
#define KEYDIALOG_H

#include <QDialog>

class QComboBox;
class QLabel;
class QTextEdit;
class QPushButton;

class keyDialog : public QDialog {
	Q_OBJECT

public:
	keyDialog(QWidget* parent = 0);
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

#endif /*KEYDIALOG_H*/
