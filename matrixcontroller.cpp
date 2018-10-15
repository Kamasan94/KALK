#include "matrixcontroller.h"
#include "errorexceptions.h"
matrixController::matrixController(Dialog* constructorDialog) : privateDialog(constructorDialog)
{
    connect(privateDialog->addM,SIGNAL(clicked()),this,SLOT(AddMatrices()));
    connect(privateDialog->flush1, SIGNAL(clicked()),this,SLOT(flushm1()));
    connect(privateDialog->flush2, SIGNAL(clicked()), this, SLOT(flushm2()));
    connect(privateDialog->op1, SIGNAL(clicked()),this,SLOT(Det1()));
    connect(privateDialog->op12, SIGNAL(clicked()),this,SLOT(Det2()));
    connect(privateDialog->op2, SIGNAL(clicked()),this,SLOT(Inv1()));
    connect(privateDialog->op22, SIGNAL(clicked()),this,SLOT(Inv2()));
    connect(privateDialog->op3, SIGNAL(clicked()),this,SLOT(Transp1()));
    connect(privateDialog->op32, SIGNAL(clicked()),this,SLOT(Transp2()));
    connect(privateDialog->op4, SIGNAL(clicked()),this,SLOT(rank1()));
    connect(privateDialog->op42, SIGNAL(clicked()),this,SLOT(rank2()));
    connect(privateDialog->op5, SIGNAL(clicked()),this,SLOT(tr1()));
    connect(privateDialog->op52, SIGNAL(clicked()),this,SLOT(tr2()));
    connect(privateDialog->mulM, SIGNAL(clicked()),this,SLOT(multiply()));
    connect(privateDialog->minM, SIGNAL(clicked()),this,SLOT(minus()));
    connect(privateDialog->op6, SIGNAL(clicked()),this,SLOT(mul1()));
    connect(privateDialog->op62, SIGNAL(clicked()),this,SLOT(mul2()));
    connect(privateDialog->op72, SIGNAL(clicked()),this,SLOT(power2()));
    connect(privateDialog->op7, SIGNAL(clicked()),this,SLOT(power1()));

    privateDialog->show();


}


void matrixController::getMatrix1() {
    int rows=0;
    int cols=1;
    bool trovato = false;
    bool atleast = false;
    int lasttrovatorow = 0;


    for(int i=0; i<privateDialog->getRows1(); i++){
        trovato=false;
        for(int j=0; j<privateDialog->getCol1(); j++){
            if(privateDialog->getCell1(i,j)->text().isEmpty()){
                     j = j;
            }
            else{
                    if(i==0)
                        cols = j+1;
                    if(j>cols-1)
                        cols = j+1;
                    trovato = true;
                    atleast = true;
                    lasttrovatorow = i+1;
            }

        }
    }

    rows = lasttrovatorow;

    if(atleast == false)
        throw ErrorExceptions("Inserire almeno un valore nella matrice");

    myMatrix1 = Matrix(rows,cols);

    for(int i=0; i<rows; i++){
        if(!privateDialog->getCell1(i,0)->text().isEmpty())
            myMatrix1.setElement(privateDialog->getCell1(i,0)->text().toDouble(),i);
        for(int j=0; j<cols; j++){
            if(privateDialog->getCell1(i,j)->text().isEmpty())
                    myMatrix1[i][j] = 0;
            else
                    myMatrix1[i][j] = privateDialog->getCell1(i,j)->text().toDouble();
        }
    }
    myMatrix1.setx(myMatrix1[0][0]);
    if(myMatrix1.getRighe()>1)
        myMatrix1.sety(myMatrix1[1][0]);
    else
        myMatrix1.sety(0);

}

void matrixController::getMatrix2(){
    int rows=0;
    int cols=1;
    bool trovato = false;
    bool atleast = false;
    int lasttrovatorow = 0;
    for(int i=0; i<privateDialog->getRows2(); i++){
        trovato=false;
        for(int j=0; j<privateDialog->getCol2(); j++){
            if(privateDialog->getCell2(i,j)->text().isEmpty()){
                j = j;
            }
            else{
                if(i==0)
                    cols = j+1;
                if(j>cols-1)
                    cols = j+1;
                trovato = true;
                atleast = true;
                lasttrovatorow = i+1;
            }

        }

    }
    rows = lasttrovatorow;

    if(atleast == false)
        throw ErrorExceptions("Inserire almeno un valore nella matrice");

    myMatrix2 = Matrix(rows,cols);

    for(int i=0; i<rows; i++){
        if(!privateDialog->getCell2(i,0)->text().isEmpty())
            myMatrix2.setElement(privateDialog->getCell2(i,0)->text().toDouble(),i);
        for(int j=0; j<cols; j++){
            if(privateDialog->getCell2(i,j)->text().isEmpty())
                    myMatrix2[i][j] = 0;
            else
                    myMatrix2[i][j] = privateDialog->getCell2(i,j)->text().toDouble();
        }
    }
    myMatrix2.setx(myMatrix2[0][0]);
    if(myMatrix2.getRighe()>1)
        myMatrix2.sety(myMatrix2[1][0]);
    else
        myMatrix2.sety(0);

}


void matrixController::getMatrix() {
    int rows=0;
    int cols=1;
    bool trovato = false;
    bool atleast = false;
    int lasttrovatorow = 0;


    for(int i=0; i<privateDialog->getRows1(); i++){
        trovato=false;
        for(int j=0; j<privateDialog->getCol1(); j++){
            if(privateDialog->getCell1(i,j)->text().isEmpty()){
                     j = j;
            }
            else{
                    if(i==0)
                        cols = j+1;
                    if(j>cols-1)
                        cols = j+1;
                    trovato = true;
                    atleast = true;
                    lasttrovatorow = i+1;
            }

        }
    }

    rows = lasttrovatorow;

    if(atleast == false)
        throw ErrorExceptions("Inserire almeno un valore nella matrice");

    myMatrix1 = Matrix(rows,cols);

    for(int i=0; i<rows; i++){
        if(!privateDialog->getCell1(i,0)->text().isEmpty())
            myMatrix1.setElement(privateDialog->getCell1(i,0)->text().toDouble(),i);
        for(int j=0; j<cols; j++){
            if(privateDialog->getCell1(i,j)->text().isEmpty())
                    myMatrix1[i][j] = 0;
            else
                    myMatrix1[i][j] = privateDialog->getCell1(i,j)->text().toDouble();
        }
    }

    myMatrix1.setx(myMatrix1[0][0]);
    if(rows>1)
        myMatrix1.sety(myMatrix1[1][0]);
    else
        myMatrix1.sety(0);

    rows = 0;
    cols = 1;

    for(int i=0; i<privateDialog->getRows2(); i++){
        trovato=false;
        for(int j=0; j<privateDialog->getCol2(); j++){
            if(privateDialog->getCell2(i,j)->text().isEmpty()){
                j = j;
            }
            else{
                if(i==0)
                    cols = j+1;
                if(j>cols-1)
                    cols = j+1;
                trovato = true;
                atleast = true;
                lasttrovatorow = i+1;
            }

        }

    }
    rows = lasttrovatorow;

    if(atleast == false)
        throw ErrorExceptions("Inserire almeno un valore nella matrice");

    myMatrix2 = Matrix(rows,cols);

    for(int i=0; i<rows; i++){
        if(!privateDialog->getCell2(i,0)->text().isEmpty())
            myMatrix2.setElement(privateDialog->getCell2(i,0)->text().toDouble(),i);
        for(int j=0; j<cols; j++){
            if(privateDialog->getCell2(i,j)->text().isEmpty())
                    myMatrix2[i][j] = 0;
            else
                    myMatrix2[i][j] = privateDialog->getCell2(i,j)->text().toDouble();
        }
    }

    myMatrix2.setx(myMatrix2[0][0]);
    if(rows>1)
        myMatrix2.sety(myMatrix2[1][0]);
    else
        myMatrix2.sety(0);
}

void matrixController::AddMatrices() {
    try {
        getMatrix();
        if((myMatrix1.getColonne() == 1 && myMatrix1.getRighe() ==  2) && (myMatrix2.getColonne() == 1 && myMatrix2.getRighe() == 2)){
            Point * p1 = dynamic_cast<Point*>(&myMatrix1);
            Point * p2 = dynamic_cast<Point*>(&myMatrix2);
            Point r = *p1 + *p2;
            privateDialog->ShowResult(r);
        }
        else if((myMatrix1.getColonne() == 1 && myMatrix1.getRighe()>2) && (myMatrix2.getColonne() == 1 && myMatrix2.getRighe() >2)){
            CustomVector * v1 = dynamic_cast<CustomVector*>(&myMatrix1);
            CustomVector * v2 = dynamic_cast<CustomVector*>(&myMatrix2);
            CustomVector r(myMatrix1.getRighe());
            r = *v1+*v2;
            privateDialog->ShowResult(r);
        }
        else{
            resMatrix = myMatrix1 + myMatrix2;
            privateDialog->ShowResult(resMatrix);
        };
    }
    catch (ErrorExceptions p) {
        privateDialog->showError(p);
    }

}

void matrixController::flushm1() {
    privateDialog->f1();
}

void matrixController::flushm2() {
    privateDialog->f2();
}

void matrixController::Det1() {
    try{
        getMatrix1();
        double result = Matrix::determinante(myMatrix1,0);
        privateDialog->ShowValue(result);
    }
    catch(ErrorExceptions p) {
        privateDialog->showError(p);
    }


}

void matrixController::Det2() {
    try{
        getMatrix2();
        double result = Matrix::determinante(myMatrix2,0);
        privateDialog->ShowValue(result);
    }
    catch(ErrorExceptions p) {
        privateDialog->showError(p);
    }

}

void matrixController::Inv1() {
    try{
        getMatrix1();
        resMatrix = myMatrix1.inverse();
        privateDialog->ShowResult(resMatrix);
    }
    catch(ErrorExceptions p){
        privateDialog->showError(p);
    }
}

void matrixController::Inv2() {
    try{
        getMatrix2();
        resMatrix = myMatrix2.inverse();
        privateDialog->ShowResult(resMatrix);
    }
    catch(ErrorExceptions p) {
        privateDialog->showError(p);
    }
}

void matrixController::Transp1(){
    try{
        getMatrix1();
        Matrix m = myMatrix1.transpose();
        privateDialog->ShowResult(m);
    }
    catch(ErrorExceptions p){
        privateDialog->showError(p);
    }
}

void matrixController::Transp2(){
    try{
        getMatrix2();
        Matrix m = myMatrix2.transpose();
        privateDialog->ShowResult(m);
    }
    catch(ErrorExceptions p){
        privateDialog->showError(p);
    }
}

void matrixController::rank1() {
    try{
        getMatrix1();
        int c = myMatrix1.rankOfMatrix();
        privateDialog->ShowValue(c);
    }
    catch(ErrorExceptions p){
        privateDialog->showError(p);
    }
}

void matrixController::rank2() {
    try{
        getMatrix2();
        int c = myMatrix2.rankOfMatrix();
        privateDialog->ShowValue(c);
    }
    catch(ErrorExceptions p){
        privateDialog->showError(p);
    }
}

void matrixController::tr1(){
    try{
        getMatrix1();
        Matrix m = myMatrix1.gaussianEliminate();
        privateDialog->ShowResult(m);
    }
    catch(ErrorExceptions p){
        privateDialog->showError(p);
    }
}

void matrixController::tr2(){
    try{
        getMatrix2();
        Matrix m = myMatrix2.gaussianEliminate();
        privateDialog->ShowResult(m);
    }
    catch(ErrorExceptions p){
        privateDialog->showError(p);
    }
}

void matrixController::multiply() {
    try {
        getMatrix();
        if((myMatrix1.getColonne() == 1 && myMatrix1.getRighe() ==  2) && (myMatrix2.getColonne() == 1 && myMatrix2.getRighe() == 2)){
            Point * p1 = dynamic_cast<Point*>(&myMatrix1);
            Point * p2 = dynamic_cast<Point*>(&myMatrix2);
            Point r = *p1 * *p2;
            privateDialog->ShowResult(r);
        }
        else if((myMatrix1.getColonne() == 1 && myMatrix1.getRighe()>2) && (myMatrix2.getColonne() == 1 && myMatrix2.getRighe() >2)){
            CustomVector * v1 = dynamic_cast<CustomVector*>(&myMatrix1);
            CustomVector * v2 = dynamic_cast<CustomVector*>(&myMatrix2);
            CustomVector r(myMatrix1.getRighe());
            r = *v1 * *v2;
            privateDialog->ShowResult(r);
        }
        else{
            resMatrix = myMatrix1 * myMatrix2;
            privateDialog->ShowResult(resMatrix);
        }
    } catch (ErrorExceptions p) {
         privateDialog->showError(p);
    }
}

void matrixController::minus() {
    try {
        getMatrix();
        if((myMatrix1.getColonne() == 1 && myMatrix1.getRighe() ==  2) && (myMatrix2.getColonne() == 1 && myMatrix2.getRighe() == 2)){
            Point * p1 = dynamic_cast<Point*>(&myMatrix1);
            Point * p2 = dynamic_cast<Point*>(&myMatrix2);
            Point r = *p1 - *p2;
            privateDialog->ShowResult(r);
        }
        else if((myMatrix1.getColonne() == 1 && myMatrix1.getRighe()>2) && (myMatrix2.getColonne() == 1 && myMatrix2.getRighe() >2)){
            CustomVector * v1 = dynamic_cast<CustomVector*>(&myMatrix1);
            CustomVector * v2 = dynamic_cast<CustomVector*>(&myMatrix2);
            CustomVector r(myMatrix1.getRighe());
            r = *v1 - *v2;
            privateDialog->ShowResult(r);
        }
        else{
            resMatrix = myMatrix1 - myMatrix2;
            privateDialog->ShowResult(resMatrix);
        };
    }
    catch (ErrorExceptions p) {
        privateDialog->showError(p);
    }
}

void matrixController::mul1() {
    privateDialog->showOptions();
    connect(privateDialog->calculate, SIGNAL(clicked()),this,SLOT(mulval1()));
}

void matrixController::mulval1() {
    try{
        double c = privateDialog->getOption();
        getMatrix1();
        if(myMatrix1.getColonne() == 1 && myMatrix1.getRighe() ==  2){
            Point * p = dynamic_cast<Point*>(&myMatrix1);
            Point r = *p *= c;
            privateDialog->ShowResult(r);
        }
        else if(myMatrix1.getColonne() == 1 && myMatrix1.getRighe()>2){
            CustomVector * v1 = dynamic_cast<CustomVector*>(&myMatrix1);
            CustomVector r(myMatrix1.getRighe());
            r = *v1 *= c;
            privateDialog->ShowResult(r);
        }
        else{
            resMatrix = myMatrix1*=c;
            privateDialog->ShowResult(resMatrix);
        }
    }
    catch(ErrorExceptions p){
        privateDialog->showError(p);
    }
}

void matrixController::mul2() {
    privateDialog->showOptions();
    connect(privateDialog->calculate, SIGNAL(clicked()),this,SLOT(mulval2()));
}

void matrixController::mulval2() {
    try{
        double c = privateDialog->getOption();
        getMatrix2();
        if(myMatrix2.getColonne() == 1 && myMatrix2.getRighe() ==  2){
            Point * p = dynamic_cast<Point*>(&myMatrix2);
            *p = *p *= c;
            privateDialog->ShowResult(*p);
        }
        else if(myMatrix2.getColonne() == 1 && myMatrix2.getRighe() >2){
            CustomVector * v2 = dynamic_cast<CustomVector*>(&myMatrix2);
            CustomVector r(myMatrix2.getRighe());
            r = *v2 *= c;
            privateDialog->ShowResult(r);
        }
        else{
            resMatrix = myMatrix2*=c;
            privateDialog->ShowResult(resMatrix);
        }
    }
    catch(ErrorExceptions p){
        privateDialog->showError(p);
    }
}

void matrixController::power1() {
    privateDialog->showOptions();
    connect(privateDialog->calculate, SIGNAL(clicked()),this,SLOT(poval1()));
}

void matrixController::power2() {
    privateDialog->showOptions();
    connect(privateDialog->calculate, SIGNAL(clicked()),this,SLOT(poval2()));
}

void matrixController::poval1() {
    try{
        double c = privateDialog->getOption();
        getMatrix1();
        if(myMatrix1.getColonne() == 1 && myMatrix1.getRighe() ==  2){
            Point * p = dynamic_cast<Point*>(&myMatrix1);
            *p = *p ^ c;
            privateDialog->ShowResult(*p);
        }
        else if(myMatrix1.getColonne() == 1 && myMatrix1.getRighe() >2){
            CustomVector * v1 = dynamic_cast<CustomVector*>(&myMatrix1);
            CustomVector r(myMatrix1.getRighe());
            r = *v1 ^ c;
            privateDialog->ShowResult(r);
        }
        else{
            resMatrix = myMatrix1^c;
            privateDialog->ShowResult(resMatrix);
        }
    }
    catch(ErrorExceptions p){
        privateDialog->showError(p);
    }
}

void matrixController::poval2() {
    try{
        double c = privateDialog->getOption();
        getMatrix2();
        if(myMatrix2.getColonne() == 1 && myMatrix2.getRighe() ==  2){
            Point * p = dynamic_cast<Point*>(&myMatrix2);
            *p = *p ^ c;
            privateDialog->ShowResult(*p);
        }
        else if(myMatrix2.getColonne() == 1 && myMatrix2.getRighe() >2){
            CustomVector * v2 = dynamic_cast<CustomVector*>(&myMatrix2);
            CustomVector r(myMatrix2.getRighe());
            r = *v2 ^ c;
            privateDialog->ShowResult(r);
        }
        else{
            resMatrix = myMatrix2^c;
            privateDialog->ShowResult(resMatrix);
        }
    }
    catch(ErrorExceptions p){
        privateDialog->showError(p);
    }
}
