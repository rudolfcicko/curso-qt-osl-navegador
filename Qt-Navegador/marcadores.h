#ifndef MARCADORES_H
#define MARCADORES_H

#include <QDialog>


class marcadores : public QDialog // De main window solo puede heredar una.
{
    Q_OBJECT

private:

public:
    marcadores(QWidget *parent = 0);
    ~marcadores();

};

#endif // MARCADORES_H
