#ifndef DIALOG_H
#define DIALOG_H
#include<QDialog>
#include<QGroupBox>
#include<QVBoxLayout>
#include<QTableWidget>
#include<QHeaderView>
#include<QPushButton>
#include<QTableView>
#include<QLineEdit>
#include<QLabel>
#include "matrixbutton.h"
#include "matrixcell.h"
#include "matrix.h"
#include "errorexceptions.h"

class Dialog : public QDialog {

    Q_OBJECT

public:
    friend class matrixController;
    Dialog(int = 1 , int = 1 , int = 1, int = 1);
    int getCol1() const;
    int getRows1() const;
    int getRows2() const;
    int getCol2() const;
    MatrixCell* getCell1(int i, int j);
    MatrixCell* getCell2(int i, int j);
    void dimension();
    void ShowResult(Matrix&);
    void ShowResult(Point&);
    void ShowValue(double);
    void f1();
    void f2();
    void showError(const ErrorExceptions& );
    void showOptions();
    double getOption();
    void ShowResult(CustomVector& );

private:
    int col1;
    int rows1;
    int col2;
    int rows2;
    void createMatrices(int r1, int c1, int r2, int c2);
    void createButtons();
    void createMainOP();
    void setButton();
    QGroupBox *matrix;
    QGroupBox *matrix2;
    QGroupBox *buttons;
    QGroupBox *buttons2;
    QGroupBox *mainOP;
    QGridLayout* mainLayout;
    matrixButton* add;
    matrixButton* add2;
    matrixButton* remove;
    matrixButton* remove2;
    matrixButton* addM;
    matrixButton* mulM;
    matrixButton* minM;
    matrixButton* flush1;
    matrixButton* flush2;
    QGroupBox* display;
    QGridLayout* displaylay;
    QVBoxLayout* mainDisplay;
    matrixButton* calculate;
    MatrixCell* val;

    //-----operators 1st Matrix--------//
    matrixButton* op1;
    matrixButton* op2;
    matrixButton* op3;
    matrixButton* op4;
    matrixButton* op5;
    matrixButton* op6;
    matrixButton* op7;
    //--------------------------------//


    //---operators 2nd Matrix--------//
    matrixButton* op12;
    matrixButton* op22;
    matrixButton* op32;
    matrixButton* op42;
    matrixButton* op52;
    matrixButton* op62;
    matrixButton* op72;
    //------------------------------//

private slots:
    void addDimension1();
    void addDimension2();
    void minusDimension1();
    void minusDimension2();
};

#endif // DIALOG_H
