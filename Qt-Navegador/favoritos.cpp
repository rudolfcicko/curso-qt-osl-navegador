#include "favoritos.h"
#include <QDir>
#include <QDebug>
#include <QModelIndex>
#include <QScreen>
#include <QAbstractItemView>
#include <QAction>

favoritos::favoritos(QWidget* parent):
    QDialog(parent)
{
    layout_ = new QGridLayout;
    //model_ = new QFileSystemModel(this);
    tree_ = new QTreeWidget(this);
    mkdir_ = new QToolButton();
    rmdir_ = new QToolButton();

    mkdir_->setText("Crear Directorio");
    rmdir_->setText("Borrar Directorio");

    this->setWindowTitle("Favoritos");
    this->setGeometry(400,400,500,500);


//    model_->setRootPath("Favoritos");

//    tree_->setModel(model_);
//    tree_->setRootIndex(model_->index("Favoritos"));
//    tree_->setGeometry(0,0,400,400);

    layout_->addWidget(tree_,0,0,6,6);
    layout_->addWidget(mkdir_,7,0,1,3);
    layout_->addWidget(rmdir_,7,3,1,3);

    this->setLayout(layout_);


    connect(mkdir_, SIGNAL(pressed()), this, SLOT(onCrearDir()));
    connect(rmdir_, SIGNAL(pressed()), this, SLOT(onBorrarDir()));
}

favoritos::~favoritos()
{

}


void favoritos::onCrearDir()
{
//        // Si el objeto seleccionado es un directorio
//        if(model_->fileInfo(tree_->currentIndex()).isDir())
//            model_->mkdir(tree_->currentIndex(),"Pepo");
//        else
//            model_->mkdir(tree_->currentIndex().parent(),"Pepo");
        qDebug() << "Apretamos crear" ;
        QAction *act = new QAction("Hola",NULL);
        //tree_->insertAction(NULL,act);
        tree_->addAction(act);

}

void favoritos::onBorrarDir()
{
       // model_->remove(tree_->selectionModel()->currentIndex());
}
