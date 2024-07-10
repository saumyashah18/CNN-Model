#include "Matrix.h"
#include "Matrix.cpp"
#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <memory>
#include<cassert>
using namespace std;

namespace linearalgebra{

//Hardmoid Function of Multiplyung 2 matricies...
Matrix Hardmoid_mult( const Matrix &m1,   const Matrix &m2){
    assert(m1.getRows()== m2.getRows() && m1.getColumns() == m2.getColumns());
       Matrix m3(m1.getRows(), m1.getColumns(), true); 
     cout<<"multiplication of two matrix is:";
     for ( int i = 0; i < m3.getRows(); ++i) {
        for (int j = 0; j < m3.getColumns(); ++j) {
            m3.set(i, j, m1.get(i, j) * m2.get(i, j));
            }
}
return m3;

}

Matrix mult( const Matrix &m1,   const Matrix &m2){
    assert(m1.getRows()== m2.getRows() && m1.getColumns() == m2.getColumns());
      Matrix result(m1.getRows(), m2.getColumns(), true);
    for (int i = 0; i < result.getRows(); ++i) {
        for (int j = 0; j < result.getColumns(); ++j) {
            double sum = 0;
            for (int k = 0; k < m1.getColumns(); ++k) {
                sum += m1.get(i, k) * m2.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

//Function of adding 2 matrices...
Matrix add(const Matrix &m1, const Matrix &m2) {
    assert(m1.getRows() == m2.getRows() && m1.getColumns() == m2.getColumns());

    Matrix m3(m1.getRows(), m1.getColumns(), true);
    for ( int i = 0; i < m1.getRows(); ++i) {
        for (int j = 0; j < m1.getColumns(); ++j) {
            m3.set(i, j, m1.get(i, j) + m2.get(i, j));
        }
    }
    return m3;
}

//Function of transposing the matrices...
Matrix tran( const Matrix &M){
    Matrix transpose(M.getColumns(), M.getRows());
    for (int i =0;i < M.getRows(); i++){

        for (int j = 0; j< M.getColumns();j++){

            transpose.set(j,i,M.get(i,j));
        }
    }

    return transpose;
}

//Function of Dot Product of 2 matrices...
Matrix dot_product( const Matrix &m1, const Matrix &m2){
     assert(m1.getRows() == m2.getRows() && m1.getColumns() == m2.getColumns());

     Matrix m3(m1.getRows(), m1.getColumns(), true);
     for (int i = 0; i < m1.getRows(); ++i) {
        for (int j = 0; j < m2.getColumns(); ++j) {
            double sum = 0;
            for (int k = 0; k < m1.getColumns(); ++k) {
                sum += m1.get(i, k) * m2.get(k, j);
            }
            m3.set(i, j, sum);
        }

        return m3;

      }
    
    }

//Function of Subtracting 2 matrices...
Matrix subtraction( const Matrix &m1 , const Matrix &m2){
    assert(m1.getRows() == m2.getRows() && m1.getColumns() == m2.getColumns());

    Matrix m3(m1.getRows(), m1.getColumns(), true);
    for ( int i = 0; i < m1.getRows(); ++i) {
        for (int j = 0; j < m1.getColumns(); ++j) {
            m3.set(i, j, m1.get(i, j) - m2.get(i, j));
        }
    }
    return m3;
   
}

//Function to m
Matrix multiply( const Matrix &m1, double value){

       Matrix result(m1.getRows(), m1.getColumns(), true); 
     cout<<"multiplication of two matrix is:";
     for ( int i = 0; i < result.getRows(); ++i) {
        for (int j = 0; j < result.getColumns(); ++j) {
            result.set(i, j, m1.get(i, j) * value);
            }
}
return result;

}

double Dot_Product(const vector<double> &v1, const vector<double> &v2){
     double result = 0;
     for ( size_t i = 0; i< v1.size();i++){
        result += v1[i] * v2[i];
        }

     return result;

}

Matrix DotProduct(const vector<double> &v1, const Matrix &m1){
    Matrix result(m1.getRows(), m1.getColumns(), true);
    for (int j = 0; j < m1.getColumns(); ++j){
     for ( size_t i = 0; i < v1.size();i++){
        result.set(i, j, v1[i] * m1.get(i,j));
        }
    }
     return result;
}

double subtractorV(const vector<double> &v1, const vector<double> &v2){
     double subtractor = 0;
     for ( size_t i = 0; i< v1.size();i++){
        subtractor = v1[i] - v2[i];
        }

     return subtractor;

}

//Function to contacinate the matr
Matrix contacinate(const Matrix &m1 , const Matrix &m2){
    Matrix result(m1.getRows(), m1.getColumns(), true);
    for (unsigned i = 0; i< m1.getRows();i++){
        for (unsigned j = 0; i < m1.getColumns(); j++){
            result.set(i,j,m1.get(i,j));
        }
    for (unsigned j=m1.getColumns();j < m1.getColumns() + m2.getColumns(); j++){
         result.set(i,j,m2.get(i,j - m1.getColumns()));
        }

      }
       return result;
   }

//Function to flatten matrice to 1-D Arrayyyy....
vector<double> flatten(const Matrix &m1){
     vector<double> value((m1.getRows() * m1.getColumns()));
     for(unsigned int i=0; i < m1.getRows(); i++){
			for(unsigned int j=0; j < m1.getColumns(); j++){
				value.at((i*m1.getColumns()) + j) = m1.get(i,j);
			}


 }
        return value;

}

//Function to reshape the matrices....
Matrix reshape(const vector<double>& v, Shape shape) {
    assert((shape.rows * shape.columns) == v.size());
    
    Matrix m3(shape.rows, shape.columns, true);
    for (unsigned int i = 0; i < shape.rows; i++) {
        for (unsigned int j = 0; j < shape.columns; ++j) {
            m3.set(i, j, v.at((i * shape.rows) + j));
        }
    }
    return m3;
}

//update kernell

void update_kernel(const Matrix &delta_conv, const Matrix &input, Matrix &kernel, double learning_rate) {
    for (int i = 0; i < kernel.getRows(); ++i) {
        for (int j = 0; j < kernel.getColumns(); ++j) {
            double delta = 0.0;
            for (int r = 0; r < delta_conv.getRows(); ++r) {
                for (int c = 0; c < delta_conv.getColumns(); ++c) {
                    delta += delta_conv.get(r, c) * input.get(r + i, c + j);
                }
            }
            kernel.set(i, j, kernel.get(i, j) - learning_rate * delta);
        }
    }
}

//Max pooling function
Matrix max_pool(const Matrix &input, int pool_size, int stride) {
    int output_rows = input.getRows() / pool_size;
    int output_cols = input.getColumns() / pool_size;
    Matrix pooled(output_rows, output_cols, false);

    for (int i = 0; i < output_rows; ++i) {
        for (int j = 0; j < output_cols; ++j) {
            double max_val = numeric_limits<double>::infinity();
            for (int r = 0; r < pool_size; ++r) {
                for (int c = 0; c < pool_size; ++c) {
                    int row = i * stride + r;
                    int col = j * stride + c;
                    if (row < input.getRows() && col < input.getColumns()) {
                        max_val = max(max_val, input.get(row, col));
                    }
                }
            }
            pooled.set(i, j, max_val);
        }
    }

    return pooled;
}


}
