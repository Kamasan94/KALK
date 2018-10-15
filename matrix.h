#ifndef MATRIX_H
#define MATRIX_H
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include "point.h"
#include"errorexceptions.h"
#include "customvector.h"
using std::vector;
class Matrix : public CustomVector
{
public:
    Matrix(int = 0,int = 0);



    vector<double>& operator [] (size_t index) {
        return p[index];
    }

    vector<double> const& operator[](size_t index) const
    {
       return p[index];
    }

    friend Matrix Complement(const Matrix& , int , int );
    friend Matrix operator + (const Matrix&, const Matrix&);
    friend Matrix operator - (const Matrix&, const Matrix&);
    friend Matrix operator * (const Matrix&, const Matrix&);
    Matrix operator *= (double);
    Matrix operator ^ (double);
    static double determinante(const Matrix&, double);
    int getRighe () const;
    int getColonne () const;
    Matrix inverse();
    Matrix augment(Matrix, Matrix);
    Matrix createIdentity(int);
    Matrix gaussianEliminate();
    Matrix rowReduceFromGaussian();
    void swapRows(int, int);
    Matrix transpose();
    void swap(int, int,int);
    int rankOfMatrix();
    Matrix solve(Matrix, Matrix);
    Matrix expHelper(const Matrix&, int);
    Matrix& operator*=(const Matrix&) ;

private:
    vector< vector<double> > p;
    vector<double> row;
    int righe;
    int colonne;
};



#endif // MATRIX_H
