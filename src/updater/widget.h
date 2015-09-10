#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>

#include <QDesktopServices>

#include "fonctions.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void checkQtChanges();

public slots:
    void runApplication();
    void runAndStopApplication();
    void updateSoftware();
    void refreshInterface();
private:
    QVBoxLayout *mainLayout;
    QTextBrowser *textBrowser;

    QHBoxLayout *layoutVersions;
    QLabel *labelLocalVersion;
    QLabel *labelLastVersion;

    QHBoxLayout *layoutButtons;
    QPushButton *pushButtonRunViewer;
    QPushButton *pushButtonUpdate;
    QPushButton *pushButtonExit;

    int viewerVersions[2][4]; // viewerVersions[LOCAL/LAST][VERSION]
    int version_qt_local;
    int version_qt_last;
    bool updateNeeded;
};

#endif // WIDGET_H
