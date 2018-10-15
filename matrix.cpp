#include "matrix.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "errorexceptions.h"
using std::vector;
using std::cout;
using std::endl;
int Matrix::getColonne() const { return colonne; }
int Matrix::getRighe() const { return righe; }

Matrix::Matrix(int rows, int cols) : righe(rows), colonne(cols), CustomVector (rows) {
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            row.push_back(0);
        }
        p.push_back(row);
    }
}

Matrix Matrix::operator^(double c) {
    Matrix temp(*this);
    return expHelper(temp, c);
}

Matrix Matrix::operator *= (double c) {
    Matrix temp(righe,colonne);
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            temp[i][j] = p[i][j]*c;
        }
    }
    return temp;
}

Matrix operator + (const Matrix& r1, const Matrix& r2) {
    if(r1.getColonne() != r2.getColonne() || r1.getRighe() != r2.getRighe())
        throw ErrorExceptions ("Errore: Le Matrici devono avere dimensioni uguali");
    Matrix result;
    if (r1.righe == r2.righe && r1.colonne == r2.colonne)
    {
        result = Matrix(r1.righe, r2.colonne);
        for (int i = 0; i < r1.righe; ++i)
            for (int j = 0; j < r2.colonne; ++j)
                result[i][j] = r1[i][j] + r2[i][j];
    }
    return result;
}
Matrix operator*(const Matrix& m1, const Matrix& m2) {
    if(m1.getColonne() != m2.getRighe())
        throw ErrorExceptions ("Errore: Il numero di colonne della prima matrice deve corrispondere al numero di righe della seconda matrice");
    Matrix temp(m1.righe, m2.colonne);
    for (int i = 0; i < temp.righe; ++i) {
        for (int j = 0; j < temp.colonne; ++j) {
            for (int k = 0; k < m1.colonne; ++k) {
                temp[i][j] += (m1[i][k] * m2[k][j]);
            }
        }
    }
    return temp;
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{
    if(m1.getColonne() != m2.getColonne() || m1.getRighe() != m2.getRighe())
        throw ErrorExceptions ("Errore: Le Matrici devono avere dimensioni uguali");
    Matrix temp(m1.righe,m1.colonne);
    for (int i = 0; i < m1.righe; ++i) {
        for (int j = 0; j < m1.colonne; ++j) {
            temp[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return temp;
}


double Matrix::determinante(const Matrix& r1, double det) {
    if(r1.righe != r1.colonne)
        throw ErrorExceptions("Errore: Matrice non quadrata" );
    if(r1.righe == 1 ) {
        return r1[0][0];
    }
    else {
        double prov=0;
        for(int i=0; i<r1.righe; i++){
            Matrix C(r1.righe-1,r1.colonne-1);
            C = Complement(r1,i,0);
            prov += pow(-1,i)*(r1[i][0])*determinante(C,det);
            det = prov;
        }
    }
    return det;
}

Matrix Complement(const Matrix& A, int a, int b) {
    if (a>=A.righe || b>=A.colonne)
       cout << "c'è un errore" << endl;

    Matrix X(A.righe-1,A.colonne-1);

    int c=0,d=0;

    for (int i=0;i<A.righe;i++){
     if (i != a){
      for (int j=0;j<A.colonne;j++)
        if (j != b){
          X[c][d]=A[i][j];
          d++;
                   }
    d=0;
    c++;
                }
    }

    return X;
}

Matrix Matrix::createIdentity(int size){
    Matrix temp(size, size);
    for (int i = 0; i < temp.righe; ++i) {
        for (int j = 0; j < temp.colonne; ++j) {
            if (i == j) {
                temp[i][j] = 1;
            } else {
                temp[i][j] = 0;
            }
        }
    }
    return temp;
}

Matrix Matrix::augment(Matrix A, Matrix B){
    Matrix AB(A.righe, A.colonne + B.colonne);
    for (int i = 0; i < AB.righe; ++i) {
        for (int j = 0; j < AB.colonne; ++j) {
            if (j < A.colonne)
                AB[i][j] = A[i][j];
            else
                AB[i][j] = B[i][j - B.colonne];
        }
    }
    return AB;
}

void Matrix::swapRows(int r1, int r2){
    vector<double> temp = p[r1];
    p[r1] = p[r2];
    p[r2] = temp;
}




Matrix Matrix::gaussianEliminate(){
    Matrix Ab(*this);
    int rows = Ab.righe;
    int cols = Ab.colonne;
    int Acols = cols - 1;

    int i = 0;
    int j = 0;


    while (i < rows){
        bool pivot_found = false;
        while (j < Acols && !pivot_found){
            if (Ab[i][j] != 0) {
                pivot_found = true;
            } else {
                int max_row = i;
                double max_val = 0;
                for (int k = i + 1; k < rows; ++k)
                {
                    double cur_abs = Ab[k][j] >= 0 ? Ab[k][j] : -1 * Ab[k][j];
                    if (cur_abs > max_val)
                    {
                        max_row = k;
                        max_val = cur_abs;
                    }
                }
                if (max_row != i) {
                    Ab.swapRows(max_row, i);
                    pivot_found = true;
                } else {
                    j++;
                }
            }
        }


        if (pivot_found){
            for (int t = i + 1; t < rows; ++t) {
                for (int s = j + 1; s < cols; ++s) {
                    Ab[t][s] = Ab[t][s] - Ab[i][s] * (Ab[t][j] / Ab[i][j]);
                    if (Ab[t][s] < 1e-10 && Ab[t][s] > -1*1e-10)
                        Ab[t][s] = 0;
                }
                Ab[t][j] = 0;
            }
        }

        i++;
        j++;
    }

    return Ab;
}


Matrix Matrix::rowReduceFromGaussian(){
    Matrix R(*this);
    int rows = R.righe;
    int cols = R.colonne;

    int i = rows - 1;
    int j = cols - 2;


    while (i >= 0){
        int k = j - 1;
        while (k >= 0) {
            if (R[i][k] != 0)
                j = k;
            k--;
        }


        if (R[i][j] != 0) {

            for (int t = i - 1; t >= 0; --t) {
                for (int s = 0; s < cols; ++s) {
                    if (s != j) {
                        R[t][s] = R[t][s] - R[i][s] * (R[t][j] / R[i][j]);
                        if (R[t][s] < 1e-10 && R[t][s] > -1*1e-10)
                            R[t][s] = 0;
                    }
                }
                R[t][j] = 0;
            }


            for (int k = j + 1; k < cols; ++k) {
                R[i][k] = R[i][k] / R[i][j];
                if (R[i][k] < 1e-10 && R[i][k] > -1*1e-10)
                    R[i][k] = 0;
            }
            R[i][j] = 1;

        }

        i--;
        j--;
    }

    return R;
}


Matrix Matrix::inverse() {
    if(determinante(*this,0) == 0)
        throw ErrorExceptions("Determinante uguale a 0, matrice non invertibile");
    Matrix I = Matrix::createIdentity(righe);
    Matrix AI = Matrix::augment(*this, I);
    Matrix U = AI.gaussianEliminate();
    Matrix IAInverse = U.rowReduceFromGaussian();
    Matrix AInverse(righe, colonne);
    for (int i = 0; i < AInverse.righe; ++i) {
        for (int j = 0; j < AInverse.colonne; ++j) {
            AInverse[i][j] = IAInverse[i][j+colonne];
        }
    }
    return AInverse;
}


Matrix Matrix::transpose(){
    Matrix ret(colonne, righe);
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            ret[j][i] = p[i][j];
        }
    }
    return ret;
}


void Matrix::swap(int row1, int row2,int col){
    for (int i = 0; i < col; i++){
        int temp = p[row1][i];
        p[row1][i] = p[row2][i];
        p[row2][i] = temp;
    }
}

int Matrix::rankOfMatrix(){
    int rank = getColonne();

    for (int row = 0; row < rank; row++){
        if (p[row][row]){
           for (int col = 0; col < getRighe(); col++){
               if (col != row){
                 double mult =p[col][row] / p[row][row];
                 for (int i = 0; i < rank; i++)
                   p[col][i] -= mult * p[row][i];
              }
           }
        }

        else{
            bool reduce = true;
            for (int i = row + 1; i < getRighe();  i++){
                if (p[i][row]){
                    swap(row, i, rank);
                    reduce = false;
                    break ;
                }
            }


            if (reduce){
                rank--;
                for (int i = 0; i < getRighe(); i ++)
                    p[i][row] = p[i][rank];
            }
            row--;
        }
    }
    return rank;
}

Matrix Matrix::solve(Matrix A, Matrix b){
    for (int i = 0; i < A.righe; ++i) {
        if (A[i][i] == 0) {
            throw ErrorExceptions("Error: the coefficient matrix has 0 as a pivot. Please fix the input and try again.");
        }
        for (int j = i + 1; j < A.righe; ++j) {
            for (int k = i + 1; k < A.colonne; ++k) {
                A[j][k] -= A[i][k] * (A[j][i] / A[i][i]);
                if (A[j][k] < 1e-10 && A[j][k] > -1*1e-10)
                    A[j][k] = 0;
            }
            b[j][0] -= b[i][0] * (A[j][i] / A[i][i]);
            if (A[j][0] < 1e-10 && A[j][0] > -1*1e-10)
                A[j][0] = 0;
            A[j][i] = 0;
        }
    }


    Matrix x(b.righe, 1);
    x[x.righe - 1][0] = b[x.righe - 1][0] / A[x.righe - 1][x.righe - 1];
    if (x[x.righe - 1][0] < 1e-10 && x[x.righe - 1][0] > -1*1e-10)
        x[x.righe - 1][0] = 0;
    for (int i = x.righe - 2; i >= 0; --i) {
        int sum = 0;
        for (int j = i + 1; j < x.righe; ++j) {
            sum += A[i][j] * x[j][0];
        }
        x[i][0] = (b[i][0] - sum) / A[i][i];
        if (x[i][0] < 1e-10 && x[i][0] > -1*1e-10)
            x[i][0] = 0;
    }

    return x;
}
Matrix& Matrix::operator*=(const Matrix& m){
    Matrix temp(righe, m.colonne);
    for (int i = 0; i < temp.righe; ++i) {
        for (int j = 0; j < temp.colonne; ++j) {
            for (int k = 0; k < colonne; ++k) {
                temp[i][j] += (p[i][k] * m[k][j]);
            }
        }
    }
    return (*this = temp);
}

Matrix Matrix::expHelper(const Matrix& m, int num){
    if (num == 0) {
        return createIdentity(m.righe);
    } else if (num == 1) {
        return m;
    } else if (num % 2 == 0) {  // num is even
        return expHelper(m * m, num/2);
    } else {                    // num is odd
        return m * expHelper(m * m, (num-1)/2);
    }
}
