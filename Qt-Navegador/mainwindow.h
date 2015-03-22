#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "webbrowser.h"
#include <QToolBar>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    //QToolBar*   toolbar_;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    WebBrowser *browser_;
};

#endif // MAINWINDOW_H
