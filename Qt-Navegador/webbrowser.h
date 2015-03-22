#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QGridLayout>
#include <QWebView>
#include <QLineEdit>
#include <QToolButton>
#include <QWidget>
#include <QAction>
//*** Rudy ***//
#include <QJsonDocument>
#include <QJSonArray>
#include <QJsonObject>
#include <QFile>
#include <QComboBox>
#include "favoritos.h"
#include <QToolBar>

class WebBrowser : public QWidget
{
    Q_OBJECT // Esta clase se comporta como un objeto de QT
public:
    explicit WebBrowser(QWidget *parent = 0);
    //QToolBar* getToolBar();
private:
    QWebView *web_;
    QLineEdit *address_;
    QToolButton *refresh_;
    QToolButton *back_;
    QToolButton *forward_;
    QToolButton *home_;
    QGridLayout *layout_;
    /////////*** RUDY ***///////////
    QToolButton *setMarcador_;
    QToolButton   *menuConfiguracion_;
    QAction  *verMarcadores_;
    QString homepage_;
    QToolBar    *toolbar_;
    favoritos * favoritos_;
    QAction* change_homepage_;
private:
    void setupConnections(); // Solo para los connect
signals:

public slots:
    void onLoad();
    void onHome();
    void onUrlChange(QUrl url);
    void onCargarMarcadores();
    void onGuardarMarcador();
    void onLoadFinished(bool ok);
    void onConfiguracion();
};

#endif // WEBBROWSER_H
