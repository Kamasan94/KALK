#include "dialog.h"
#include "matrixcell.h"
#include "matrixbutton.h"
#include "QLabel"
#include <sstream>
#include<vector>
using std::vector;
Dialog::Dialog(int r1, int c1, int r2, int c2) : rows1(r1), col1(c1), rows2(r2), col2(c2)  {
    createMatrices(r1,c1,r2,c2);
    createButtons();
    createMainOP();

    mainLayout = new QGridLayout;
    QVBoxLayout *matrix1layout = new QVBoxLayout;
    QVBoxLayout *matrix2layout = new QVBoxLayout;
    QVBoxLayout *buttonslayout1 = new QVBoxLayout;
    QVBoxLayout *buttonslayout2 = new QVBoxLayout;
    QVBoxLayout *mainoplayout = new QVBoxLayout;
    matrix1layout->addWidget(matrix);
    buttonslayout1->addWidget(buttons);

    display = new QGroupBox;
    displaylay = new QGridLayout(display);
    QLabel* welcome = new QLabel;
    welcome->setText("                 ");
    calculate = new matrixButton("Calcola");
    display->setMaximumSize(50,50);
    mainDisplay = new QVBoxLayout;

    mainDisplay->addWidget(welcome);
    matrix2layout->addWidget(matrix2);
    buttonslayout2->addWidget(buttons2);

    mainoplayout->addWidget(mainOP);

    connect(add,SIGNAL(clicked()),this,SLOT(addDimension1()));
    connect(add2,SIGNAL(clicked()),this,SLOT(addDimension2()));
    connect(remove,SIGNAL(clicked()),this,SLOT(minusDimension1()));
    connect(remove2,SIGNAL(clicked()),this,SLOT(minusDimension2()));
    mainLayout->addLayout(mainDisplay,0,0);
    mainLayout->addLayout(matrix1layout,1,0);
    mainLayout->addLayout(buttonslayout1,2,0);
    mainLayout->addLayout(mainoplayout,1,1);
    mainLayout->addLayout(matrix2layout,1,2);
    mainLayout->addLayout(buttonslayout2,2,2);

    setLayout(mainLayout);

    resize(2000,2000);


}

void Dialog::createMatrices(int r1, int c1, int r2, int c2) {


    QGridLayout *matrixlay = new QGridLayout;
    QGridLayout *matrixlay2 = new QGridLayout;

    matrix = new QGroupBox;
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            MatrixCell* cell = new MatrixCell;

            cell->setMaximumSize(50,50);
            matrixlay->addWidget(cell,i,j);
        }
    }



    matrix->setLayout(matrixlay);

    matrix2 = new QGroupBox;
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            MatrixCell* cell = new MatrixCell;
            cell->setMaximumSize(50,50);
            matrixlay2->addWidget(cell,i,j);
        }
    }

    matrix2->setLayout(matrixlay2);




}

void Dialog::createButtons() {
    //Operatori prima matrice
    buttons = new QGroupBox;
    QGridLayout *buttonlay = new QGridLayout;
    op1 = new matrixButton(tr("Determinante"));
    op2 = new matrixButton(tr("Inversa"));
    op3 = new matrixButton(tr("Trasposta"));
    op4 = new matrixButton(tr("Rango"));
    op5 = new matrixButton(tr("Triangolare"));
    op6 = new matrixButton(tr("Moltiplicare per"));
    op7 = new matrixButton(tr("Elevare a potenza"));
    add = new matrixButton(tr("+"));
    add->setMaximumSize(50,50);

    remove = new matrixButton(tr("-"));
    remove->setMaximumSize(50,50);
    flush1 = new matrixButton(tr("Cancellare"));

    QHBoxLayout* topbuttons = new QHBoxLayout;
    QHBoxLayout* freshlayout = new QHBoxLayout;

    topbuttons->addWidget(add);
    topbuttons->addWidget(remove);
    freshlayout->addWidget(flush1);
    buttonlay->addLayout(topbuttons,0,0);
    buttonlay->addLayout(freshlayout,0,1);
    buttonlay->addWidget(op1,1,0);
    buttonlay->addWidget(op2,1,1);
    buttonlay->addWidget(op3,2,0);
    buttonlay->addWidget(op4,2,1);
    buttonlay->addWidget(op5,3,0);
    buttonlay->addWidget(op6,3,1);
    buttonlay->addWidget(op7,4,0);

    buttons->setLayout(buttonlay);


    //Operatori seconda matrice
    buttons2 = new QGroupBox;

    QGridLayout *buttonlay2 = new QGridLayout;
    op12 = new matrixButton(tr("Determinante"));
    op22 = new matrixButton(tr("Inversa"));
    op32 = new matrixButton(tr("Trasposta"));
    op42 = new matrixButton(tr("Rango"));
    op52 = new matrixButton(tr("Triangolare"));
    op62 = new matrixButton(tr("Moltiplicare per"));
    op72 = new matrixButton(tr("Elevare a potenza"));

    add2 = new matrixButton(tr("+"));
    add2->setMaximumSize(50,50);
    remove2 = new matrixButton(tr("-"));
    remove2->setMaximumSize(50,50);
    flush2 = new matrixButton(tr("Cancellare"));

    QHBoxLayout* topbuttons2 = new QHBoxLayout;
    QHBoxLayout* freshlayout2 = new QHBoxLayout;

    topbuttons2->addWidget(add2);
    topbuttons2->addWidget(remove2);
    freshlayout2->addWidget(flush2);
    buttonlay2->addLayout(topbuttons2,0,0);
    buttonlay2->addLayout(freshlayout2,0,1);

    buttonlay2->addWidget(op12,1,0);
    buttonlay2->addWidget(op22,1,1);
    buttonlay2->addWidget(op32,2,0);
    buttonlay2->addWidget(op42,2,1);
    buttonlay2->addWidget(op52,3,0);
    buttonlay2->addWidget(op62,3,1);
    buttonlay2->addWidget(op72,4,0);

    buttons2->setLayout(buttonlay2);

}

void Dialog::createMainOP() {
    mainOP = new QGroupBox;

    QVBoxLayout * oplayout = new QVBoxLayout;

    mulM = new matrixButton(tr("A*B"));

    addM = new matrixButton(tr("A+B"));
    minM = new matrixButton(tr("A-B"));

    oplayout->addWidget(mulM);
    oplayout->addWidget(addM);
    oplayout->addWidget(minM);

    mainOP->setLayout(oplayout);


}

int Dialog::getCol1() const { return col1; }
int Dialog::getRows1() const { return rows1; }
int Dialog::getCol2() const { return col2; }
int Dialog::getRows2() const { return rows2; }






void Dialog::addDimension1() {
    delete matrix;
    QGridLayout *matrixlay = new QGridLayout;
    matrix = new QGroupBox;
    if(col1==7)
        col1--;
    if(rows1==7)
        rows1--;
    for(int i=0; i<getRows1()+1; i++){
        for(int j=0; j<getCol1()+1; j++){
            MatrixCell* cell = new MatrixCell;
            cell->setMaximumSize(50,50);
            matrixlay->addWidget(cell,i,j);
        }
    }
    matrix->setLayout(matrixlay);
    col1 = col1+1;
    rows1 = rows1+1;
    QVBoxLayout *matrix1layout = new QVBoxLayout;
    matrix1layout->addWidget(matrix);
    mainLayout->addLayout(matrix1layout,1,0);



}

void Dialog::addDimension2() {
    delete matrix2;
    QGridLayout *matrixlay = new QGridLayout;
    matrix2 = new QGroupBox;

    if(col2==7)
        col2--;
    if(rows2==7)
        rows2--;

    for(int i=0; i<getRows2()+1; i++){
        for(int j=0; j<getCol2()+1; j++){
            MatrixCell* cell = new MatrixCell;
            cell->setMaximumSize(50,50);
            matrixlay->addWidget(cell,i,j);
        }
    }
    matrix2->setLayout(matrixlay);
    col2 = col2+1;
    rows2 = rows2+1;
    QVBoxLayout *matrix1layout = new QVBoxLayout;
    matrix1layout->addWidget(matrix2);
    mainLayout->addLayout(matrix1layout,1,2);

}

void Dialog::minusDimension1() {
    delete matrix;
    QGridLayout *matrixlay = new QGridLayout;
    matrix = new QGroupBox;
    if(col1==1)
        col1++;
    if(rows1==1)
        rows1++;
    for(int i=0; i<getRows1()-1; i++){
        for(int j=0; j<getCol1()-1; j++){
            MatrixCell* cell = new MatrixCell;
            cell->setMaximumSize(50,50);
            matrixlay->addWidget(cell,i,j);
        }
    }
    matrix->setLayout(matrixlay);
    col1 = col1-1;
    rows1 = rows1-1;

    QVBoxLayout *matrix1layout = new QVBoxLayout;
    matrix1layout->addWidget(matrix);
    mainLayout->addLayout(matrix1layout,1,0);


}

void Dialog::minusDimension2() {
    delete matrix2;
    QGridLayout *matrixlay = new QGridLayout;
    matrix2 = new QGroupBox;
    if(col2==1)
        col2++;
    if(rows2==1)
        rows2++;


    for(int i=0; i<getRows2()-1; i++){
        for(int j=0; j<getCol2()-1; j++){
            MatrixCell* cell = new MatrixCell;
            cell->setMaximumSize(50,50);
            matrixlay->addWidget(cell,i,j);
        }
    }
    matrix2->setLayout(matrixlay);
    col2 = col2-1;
    rows2 = rows2-1;

    QVBoxLayout *matrix2layout = new QVBoxLayout;
    matrix2layout->addWidget(matrix2);
    mainLayout->addLayout(matrix2layout,1,2);


}

MatrixCell* Dialog::getCell1(int i, int j) {

    QGridLayout* gr = dynamic_cast<QGridLayout*>(matrix->layout());
    if(gr){
        MatrixCell* p = dynamic_cast<MatrixCell*>(gr->itemAtPosition(i,j)->widget());

    if(p)
        return p;
    else
        throw(ErrorExceptions("Errore nel caricamento cella"));
    }
    else {
        throw(ErrorExceptions("Errore nel caricamento cella"));
    }


}

MatrixCell* Dialog::getCell2(int i, int j) {
    QGridLayout* gr = dynamic_cast<QGridLayout*>(matrix2->layout());
    if(gr){
    MatrixCell *p = dynamic_cast<MatrixCell*>(gr->itemAtPosition(i,j)->widget());
    if(p)
        return p;
    else
        throw(ErrorExceptions("Errore nel caricamento cella"));
    }
    else {
        throw(ErrorExceptions("Errore nel caricamento cella"));
    }
}

void Dialog::ShowResult(Matrix & m) {
    delete display;

    mainLayout->removeItem(mainDisplay);
    QGridLayout* LA = new QGridLayout;
    display = new QGroupBox;
    displaylay = new QGridLayout;
    for(int i=0; i<m.getRighe(); ++i){
        for(int j=0; j<m.getColonne(); ++j){
            QLabel* l = new QLabel;
            QString str;
            str.setNum(m[i][j]);

            l->setText(str);
            l->setAlignment(Qt::AlignCenter);
            displaylay->addWidget(l,i,j);

        }

    }

    LA->addLayout(displaylay,0,1);
    display->setLayout(LA);
    mainDisplay->addWidget(display);

    mainLayout->addLayout(mainDisplay,0,0);

}

void Dialog::ShowResult(Point& m) {
    delete display;

    mainLayout->removeItem(mainDisplay);
    QGridLayout* LA = new QGridLayout;
    display = new QGroupBox;
    displaylay = new QGridLayout;
    QLabel* l = new QLabel;
    QString str;
    str.setNum(m.getx());
    l->setText(str);
    l->setAlignment(Qt::AlignCenter);
    displaylay->addWidget(l,0,0);

    QLabel* l1 = new QLabel;
    QString str1;
    str1.setNum(m.gety());
    l1->setText(str1);
    l1->setAlignment(Qt::AlignCenter);
    displaylay->addWidget(l1,1,0);

    LA->addLayout(displaylay,0,1);
    display->setLayout(LA);
    mainDisplay->addWidget(display);

    mainLayout->addLayout(mainDisplay,0,0);

}

void Dialog::ShowResult(CustomVector& v){
    delete display;

    mainLayout->removeItem(mainDisplay);
    QGridLayout* LA = new QGridLayout;
    display = new QGroupBox;
    displaylay = new QGridLayout;
    for(int i=0; i<v.getSize(); i++){
        QLabel* l = new QLabel;
        QString str;
        str.setNum(v.getVal(i));
        l->setText(str);
        l->setAlignment(Qt::AlignCenter);
        displaylay->addWidget(l,i,0);

    }
    LA->addLayout(displaylay,0,1);
    display->setLayout(LA);
    mainDisplay->addWidget(display);

    mainLayout->addLayout(mainDisplay,0,0);

}

void Dialog::f1() {
    for(int i=0; i<getRows1(); i++){
        for(int j=0; j<getCol1(); j++){
            getCell1(i,j)->setText(NULL);
        }
    }
}

void Dialog::f2() {
    for(int i=0; i<getRows2(); i++){
        for(int j=0; j<getCol2(); j++){
            getCell2(i,j)->setText(NULL);
        }
    }
}

void Dialog::ShowValue(double c) {
    delete display;

    mainLayout->removeItem(mainDisplay);
    display = new QGroupBox;
    displaylay = new QGridLayout;

    QLabel* l = new QLabel;
    QString str;
    str.setNum(c);
    l->setAlignment(Qt::AlignCenter);
    l->setText(str);
    displaylay->addWidget(l,5,0);
    display->setLayout(displaylay);
    mainDisplay->addWidget(display);

    mainLayout->addLayout(mainDisplay,0,0);
}

void Dialog::showError(const ErrorExceptions& p){
    delete display;
    mainLayout->removeItem(mainDisplay);
    display = new QGroupBox;
    displaylay = new QGridLayout;

    QLabel* l = new QLabel;
    l->setText(p.geterror());
    l->setAlignment(Qt::AlignCenter);
    displaylay->addWidget(l,0,0);
    mainDisplay->addWidget(display);
    display->setLayout(displaylay);
    mainLayout->addLayout(mainDisplay,0,0);


}

void Dialog::showOptions() {
    delete display;
    mainLayout->removeItem(mainDisplay);
    display = new QGroupBox;
    displaylay = new QGridLayout;
    val = new MatrixCell;
    QString str("Inserire valore");
    QLabel* value = new QLabel;
    value->setText(str);
    value->setAlignment(Qt::AlignCenter);
    calculate = new matrixButton("Calcola");

    displaylay->addWidget(value,0,1);
    displaylay->addWidget(val,0,2);
    displaylay->addWidget(calculate,2,1);
    mainDisplay->addWidget(display);
    display->setLayout(displaylay);
    mainLayout->addLayout(mainDisplay,0,0);


}

double Dialog::getOption() {
    return val->text().toDouble();
}
