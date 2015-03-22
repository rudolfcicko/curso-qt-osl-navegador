#include "webbrowser.h"
#include <QMenu>
#include <QKeySequence>


WebBrowser::WebBrowser(QWidget *parent) :
    QWidget(parent)
{
    /* RUDY    */
    setMarcador_ = new QToolButton;
    menuConfiguracion_ = new QToolButton;
    verMarcadores_ = new QAction(tr("&Favoritos"),this);
    toolbar_ = new QToolBar();
    favoritos_ = new favoritos();
    change_homepage_ = new QAction(tr("&Homepage"));

    toolbar_->addAction(verMarcadores_);
    menuConfiguracion_->setIcon(QIcon(QPixmap(":/icons/resources/configuracion.png")));
    setMarcador_->setIcon(QIcon(QPixmap(":/icons/resources/BlankStar.png")));
    /*END RUDY */

    web_ = new QWebView(this); // Para lo que más sirve es para el recolector de basura
    address_ = new QLineEdit(this);
    refresh_ = new QToolButton;
    back_ = new QToolButton;
    forward_ = new QToolButton;
    home_ = new QToolButton;
    layout_ = new QGridLayout;

    refresh_->setIcon(QIcon(QPixmap(":/icons/resources/refresh.png")));
    back_->setIcon(QIcon(QPixmap(":/icons/resources/go-previous.png")));
    forward_->setIcon(QIcon(QPixmap(":/icons/resources/go-next.png")));
    home_->setIcon(QIcon(QPixmap(":/icons/resources/go-home.png")));
    layout_->addWidget(back_,0,0,1,1);
    layout_->addWidget(forward_,0,1,1,1);
    layout_->addWidget(home_,0,2,1,1);
    layout_->addWidget(refresh_,0,3,1,1);
    layout_->addWidget(address_,0,5,1,1);
    layout_->addWidget(web_,1,0,1,7);
    layout_->addWidget(setMarcador_,0,4,1,1);
    layout_->addWidget(menuConfiguracion_,0,6,1,1);
    ///* RUDY * ////
    toolbar_->setVisible(false);
    layout_->addWidget(toolbar_,0,0,1,7);

    /////////////
    homepage_="http://duckduckgo.com";
    address_->setText(homepage_);
    web_->load(homepage_);
    setLayout(layout_);
    setupConnections();
}

void WebBrowser::setupConnections()
{
    connect(menuConfiguracion_, SIGNAL(pressed()), this, SLOT(onConfiguracion()));
    connect(setMarcador_, SIGNAL(pressed()), this, SLOT(onGuardarMarcador()));
    connect(verMarcadores_, SIGNAL(triggered()), this , SLOT(onCargarMarcadores()));
    connect(address_,SIGNAL(returnPressed()),this,SLOT(onLoad()));
    connect(refresh_,SIGNAL(pressed()),web_,SLOT(reload()));
    connect(forward_,SIGNAL(pressed()),web_,SLOT(forward()));
    connect(back_,SIGNAL(pressed()),web_,SLOT(back()));
    connect(home_,SIGNAL(pressed()),this,SLOT(onHome()));
    connect(web_,SIGNAL(urlChanged(QUrl)),this,SLOT(onUrlChange(QUrl)));
    connect(web_,SIGNAL(loadFinished(bool)),this,SLOT(onLoadFinished(bool)));
}

void WebBrowser::onLoad()
{
    if(!address_->text().startsWith("http://")
            && !address_->text().startsWith("https://")
            && address_->text().length()!=0)
        web_->load("http://"+address_->text());
    else
        web_->load(address_->text());

}

void WebBrowser::onHome()
{
    web_->load(homepage_);
}

void WebBrowser::onUrlChange(QUrl url)
{
    address_->setText(url.toString());
}

void WebBrowser::onLoadFinished(bool ok)
{
    if(!ok)
        web_->load("https://duckduckgo.com/?q="+address_->text());


}

void WebBrowser::onGuardarMarcador()
{
    QFile  file("favoritos.txt");

    QString url(address_->text());

    qDebug() << "El url es : " << url ;

    QJsonDocument   doc;
    QJsonObject     urlViejos;
    QJsonObject     urlActualizados;
    QJsonArray      urls;

    if(!file.open( QIODevice::ReadOnly | QIODevice::Text))
        qDebug () << "Error a la hora de abrir el archivo de favoritos" ;
    else
    {
        doc = QJsonDocument::fromJson(file.readAll());
        file.close();
        urlViejos = doc.object();
        urls = urlViejos["urls"].toArray();

        urls.append(url);

        urlActualizados.insert("urls",urls);

        doc = QJsonDocument(urlActualizados);

        if(!file.open( QIODevice::WriteOnly | QIODevice::Text ))
            qDebug() << "Error a la hora de abrir el archivo de favoritos";
        else
        {
            file.write(doc.toJson());
            file.close();
        }
    }
}


void WebBrowser::onCargarMarcadores()
{
    qDebug() << "Apretamos favoritos";
    favoritos_->exec();
}

void WebBrowser::onConfiguracion()
{
    int desplazamiento;
    qDebug() << "Apretamos configuracion" ;
    if(!toolbar_->isVisible())
    {
        desplazamiento = 1;
        toolbar_->setVisible(true);

    }
    else
    {
        desplazamiento = 0;
        toolbar_->setVisible(false);
    }

    // Desplazamos Widgets
    layout_->addWidget(back_,desplazamiento,0,1,1);
    layout_->addWidget(forward_,desplazamiento,1,1,1);
    layout_->addWidget(home_,desplazamiento,2,1,1);
    layout_->addWidget(refresh_,desplazamiento,3,1,1);
    layout_->addWidget(address_,desplazamiento,5,1,1);
    layout_->addWidget(web_,1+desplazamiento,0,1,7);
    layout_->addWidget(setMarcador_,desplazamiento,4,1,1);
    layout_->addWidget(menuConfiguracion_,desplazamiento,6,1,1);

}






