#ifndef P12TAB_H
#define P12TAB_H

#include <QtWidgets>

class p12Tab : public QWidget {
	Q_OBJECT
public:
    p12Tab(QWidget* parent);
private:
    QLabel* messageLabel;
};

#endif /*P12TAB_H*/
