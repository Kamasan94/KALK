#ifndef MATRIXCONTROLLER_H
#define MATRIXCONTROLLER_H
#include "dialog.h"
#include "matrix.h"
#include "QObject"
#include "matrixcell.h"

class matrixController : public QObject
{
    Q_OBJECT

public:

    matrixController(Dialog*);
    void  getMatrix();
    void  getMatrix1();
    void  getMatrix2();

private:
    Dialog *privateDialog;
    Matrix myMatrix1;
    Matrix myMatrix2;
    Matrix resMatrix;


public slots:

    void AddMatrices();
    void flushm2();
    void flushm1();
    void Det1();
    void Det2();
    void Inv1();
    void Inv2();
    void Transp1();
    void Transp2();
    void rank1();
    void rank2();
    void tr1();
    void tr2();
    void multiply();
    void minus();
    void mul1();
    void mulval1();
    void mul2();
    void mulval2();
    void power1();
    void power2();
    void poval1();
    void poval2();

signals:
    void resultready(const Matrix&);
};

#endif // MATRIXCONTROLLER_H
