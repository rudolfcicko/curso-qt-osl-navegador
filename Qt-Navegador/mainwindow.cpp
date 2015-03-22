#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    browser_ = new WebBrowser;
    setCentralWidget(browser_);
    //toolbar_ = browser_->getToolBar();
    //addToolBar(toolbar_);
}

MainWindow::~MainWindow()
{

}
