#ifndef ABOUTTAB_H
#define ABOUTTAB_H

#include <QtWidgets>

class mainDialog;

class aboutTab : public QWidget {
	Q_OBJECT
public:
    aboutTab(mainDialog* parent);
private:
    QLabel* aboutText;
};

#endif /* ABOUTTAB_H */
