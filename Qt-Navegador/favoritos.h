#ifndef FAVORITOS_H
#define FAVORITOS_H

#include <QWidget>
#include <QDialog>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTreeWidget>
#include <QGridLayout>
#include <QToolButton>
//#include <QListView>


class favoritos : public QDialog
{
    Q_OBJECT
private:
    //QFileSystemModel* model_;
    //QTreeView * tree_;
    QTreeWidget * tree_;
    QGridLayout * layout_;
    QToolButton * mkdir_;
    QToolButton * rmdir_;
public:
    favoritos(QWidget* parent = 0);
    ~favoritos();

public slots:
     void onCrearDir();
     void onBorrarDir();
};

#endif // FAVORITOS_H
