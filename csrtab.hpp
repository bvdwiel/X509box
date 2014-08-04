#ifndef CSRTAB_H
#define CSRTAB_H

#include <QtWidgets>

class csrTab : public QWidget {
	Q_OBJECT
public:
	csrTab(QWidget* parent);
private:
	QLabel* csrLabel;
	QTextEdit* csrField;
	QPushButton* generateCsrButton;
	QPushButton* saveCsrButton;
};

#endif /*CSRTAB*/
