#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>


class S21Matrix {
 private:
     int rows_;
     int cols_;
     double** matrix_;

 public:
    S21Matrix();
    S21Matrix(int rows_, int cols_);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);
    ~S21Matrix();
    void set_sizerows_(int x);
    void set_sizecols_(int y);
    int getrows_();
    int getcols_();
    bool eq_matrix(const S21Matrix& other);
    void sum_matrix(const S21Matrix& other);
    void sub_matrix(const S21Matrix& other);
    void mul_number(const double num);
    void mul_matrix(const S21Matrix& other);
    S21Matrix transpose();
    S21Matrix minor_matrix(int rows_, int cols_);
    double determinant();
    S21Matrix calc_complements();
    S21Matrix inverse_matrix();
    void init_matrix_1_();
    void init_matrix_2_();
    void init_matrix_3_();
    void init_sum_();
    void init_mull_();
    void init_transp_();
    void init_calc_();
    void init_inverse_();
    void init_set_();
    void init_set_2_();
    S21Matrix operator + (const S21Matrix& a);
    S21Matrix operator - (const S21Matrix& a);
    S21Matrix operator * (const S21Matrix& a);
    S21Matrix operator * (double a);
    bool operator == (const S21Matrix& a);
    bool operator != (const S21Matrix& a);
    S21Matrix operator = (const S21Matrix& a);
    S21Matrix operator += (const S21Matrix& a);
    S21Matrix operator -= (const S21Matrix& a);
    S21Matrix operator *= (const S21Matrix& a);
    S21Matrix operator *= (double a);
    double operator () (int a, int b);

 private:
     void setting_value_(const S21Matrix& other);
     int check_matrix_(const S21Matrix& other);
     void remove_matrix_();
};
#endif  // SRC_S21_MATRIX_OOP_H_
