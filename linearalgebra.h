#ifndef LINERALGEBRA_H
#define LINEARALGEBRA_H

#include "Matrix.h"
#include <vector>
#include <iostream>
using namespace std;


namespace linearlalgebra{
    Matrix Hardmoid_mult( const Matrix &m1, const Matrix &m2);
    Matrix mult( const Matrix &m1,   const Matrix &m2);
    Matrix add(const Matrix &m1, const Matrix &m2);
    Matrix tran( const Matrix &M);
    Matrix dot_product( const Matrix &m1, const Matrix &m2);
    Matrix subtraction( const Matrix &m1 , const Matrix &m2);
    Matrix multiply(const Matrix &m1, double value);
    double Dot_Product(const vector<double> &v1, const vector<double> &v2);
    Matrix DotProduct(const vector<double> &v1, const Matrix &m1);
    double subtractorV(const vector<double> &v1, const vector<double> &v2);
    Matrix contacinate(const Matrix &m1 , const Matrix &m2);
    double flatten(const Matrix &m1);
    Matrix reshape(const std::vector<double>& v, Shape shape);
    }

#endif







