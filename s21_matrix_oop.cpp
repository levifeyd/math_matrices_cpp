#include "s21_matrix_oop.h"
#include <stdexcept>

S21Matrix::S21Matrix() : S21Matrix(4, 4) {
}

S21Matrix::S21Matrix(int rows_, int cols_) {
    if (rows_ > 0 && cols_ > 0) {
        this->rows_ = rows_;
        this->cols_ = cols_;
        this->matrix_ = new double* [rows_];
        for (int i = 0 ; i < rows_; i++) {
            this->matrix_[i] = new double[cols_]();
        }
    } else {
        throw std::out_of_range("Error: sizes of matrix <= 0");
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) : S21Matrix(other.rows_, other.cols_) {
        (*this).setting_value_(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
    other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
    this->remove_matrix_();
}
// -------------------------------------------------------HELP FUNCTION----------------------------------
void S21Matrix:: init_matrix_1_() {
    this->matrix_[0][0] = 1.0;
    this->matrix_[0][1] = 2.0;
    this->matrix_[0][2] = 3.0;
    this->matrix_[0][3] = 4.0;
    this->matrix_[1][0] = 4.0;
    this->matrix_[1][1] = -5.0;
    this->matrix_[1][2] = -6.0;
    this->matrix_[1][3] = -9.0;
    this->matrix_[2][0] = -7.0;
    this->matrix_[2][1] = 7.0;
    this->matrix_[2][2] = -9.0;
    this->matrix_[2][3] = -9.0;
    this->matrix_[3][0] = 21.0;
    this->matrix_[3][1] = -3;
    this->matrix_[3][2] = -6;
    this->matrix_[3][3] = -16;
}
void S21Matrix::init_sum_() {
    this->matrix_[0][0] = 2.0;
    this->matrix_[0][1] = 4.0;
    this->matrix_[0][2] = 6.0;
    this->matrix_[0][3] = 8.0;
    this->matrix_[1][0] = 10.0;
    this->matrix_[1][1] = 12.0;
    this->matrix_[1][2] = 14.0;
    this->matrix_[1][3] = 16.0;
    this->matrix_[2][0] = 18.0;
    this->matrix_[2][1] = 20.0;
    this->matrix_[2][2] = 22.0;
    this->matrix_[2][3] = 24.0;
    this->matrix_[3][0] = 26.0;
    this->matrix_[3][1] = 28.0;
    this->matrix_[3][2] = 30.0;
    this->matrix_[3][3] = 32.0;
}
void S21Matrix::init_mull_() {
    this->matrix_[0][0] = 90.0;
    this->matrix_[0][1] = 100;
    this->matrix_[0][2] = 110;
    this->matrix_[0][3] = 120;
    this->matrix_[1][0] = 202;
    this->matrix_[1][1] = 228;
    this->matrix_[1][2] = 254;
    this->matrix_[1][3] = 280;
    this->matrix_[2][0] = 314;
    this->matrix_[2][1] = 356;
    this->matrix_[2][2] = 398;
    this->matrix_[2][3] = 440;
    this->matrix_[3][0] = 426;
    this->matrix_[3][1] = 484;
    this->matrix_[3][2] = 542;
    this->matrix_[3][3] = 600;
}
void S21Matrix::init_transp_() {
    this->matrix_[0][0] = 1.0;
    this->matrix_[0][1] = 5.0;
    this->matrix_[0][2] = 9.0;
    this->matrix_[0][3] = 13.0;
    this->matrix_[1][0] = 2.0;
    this->matrix_[1][1] = 6.0;
    this->matrix_[1][2] = 10.0;
    this->matrix_[1][3] = 14.0;
    this->matrix_[2][0] = 3.0;
    this->matrix_[2][1] = 7.0;
    this->matrix_[2][2] = 11.0;
    this->matrix_[2][3] = 15.0;
    this->matrix_[3][0] = 4.0;
    this->matrix_[3][1] = 8.0;
    this->matrix_[3][2] = 12.0;
    this->matrix_[3][3] = 16.0;
}
void S21Matrix::init_calc_() {
    this->matrix_[0][0] = -663.0;
    this->matrix_[0][1] = -87.00;
    this->matrix_[0][2] = 2083.0;
    this->matrix_[0][3] = -1635.0;
    this->matrix_[1][0] = -321.0;
    this->matrix_[1][1] = 111.0;
    this->matrix_[1][2] = 1245.0;
    this->matrix_[1][3] = -909;
    this->matrix_[2][0] = -27.0;
    this->matrix_[2][1] = -75.0;
    this->matrix_[2][2] = 175.0;
    this->matrix_[2][3] = -87.0;
    this->matrix_[3][0] = 30.0;
    this->matrix_[3][1] = -42.0;
    this->matrix_[3][2] = -278.0;
    this->matrix_[3][3] = 222.0;
}
void S21Matrix::init_inverse_() {
    this->matrix_[0][0] = 0.587766;
    this->matrix_[0][1] = 0.284574;
    this->matrix_[0][2] = 0.023936;
    this->matrix_[0][3] = -0.026596;
    this->matrix_[1][0] = 0.077128;
    this->matrix_[1][1] = -0.098404;
    this->matrix_[1][2] = 0.066489;
    this->matrix_[1][3] = 0.037234;
    this->matrix_[2][0] = -1.846631;
    this->matrix_[2][1] = -1.103723;
    this->matrix_[2][2] = -0.155142;
    this->matrix_[2][3] = 0.246454;
    this->matrix_[3][0] = 1.449468;
    this->matrix_[3][1] = 0.805851;
    this->matrix_[3][2] = 0.077128;
    this->matrix_[3][3] = -0.196809;
}
void S21Matrix::init_set_2_() {
    this->matrix_[0][0] = 1.0;
    this->matrix_[0][1] = 2.0;
    this->matrix_[0][2] = 3.0;
    this->matrix_[0][3] = 4.0;
    this->matrix_[1][0] = 5.0;
    this->matrix_[1][1] = 6.0;
    this->matrix_[1][2] = 7.0;
    this->matrix_[1][3] = 8.0;
    this->matrix_[2][0] = 9.0;
    this->matrix_[2][1] = 10.0;
    this->matrix_[2][2] = 11.0;
    this->matrix_[2][3] = 12.0;
    this->matrix_[3][0] = 13.0;
    this->matrix_[3][1] = 14.0;
    this->matrix_[3][2] = 15.0;
    this->matrix_[3][3] = 16.0;
    this->matrix_[0][4] = 0;
    this->matrix_[1][4] = 0;
    this->matrix_[2][4] = 0;
    this->matrix_[3][4] = 0;
}
void S21Matrix::init_set_() {
    this->matrix_[0][0] = 1;
    this->matrix_[0][1] = 2;
    this->matrix_[1][0] = 5;
    this->matrix_[1][1] = 6;
}
void S21Matrix::init_matrix_3_() {
    double m = 0;
    for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
            this->matrix_[i][j] = ++m;
        }
    }
}
void S21Matrix::remove_matrix_() {
    if (this->matrix_ != nullptr) {
        for (int i = 0; i < this->rows_; i++) {
            if (this->rows_ > 0 && this->cols_ > 0 && this->matrix_[i] != nullptr)
                delete [] (this->matrix_[i]);
        }
            delete (this->matrix_);
    }
}
void S21Matrix::setting_value_(const S21Matrix& other) {
    for (int i = 0; i < other.rows_; i++) {
        for (int j = 0; j < other.cols_; j++) {
            this->matrix_[i][j] = other.matrix_[i][j];
        }
    }
}
// -----------------------------------------------------------------------------------------

bool S21Matrix::eq_matrix(const S21Matrix& other) {
    bool res_value = false;
    if (this->check_matrix_(other)) {
        res_value = true;
        for (int i = 0; i < other.rows_; i++) {
            for (int j = 0; j < other.cols_; j++) {
                if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) > 1e-06) {
                        res_value = false;
                }
            }
        }
    }
    return res_value;
}
void S21Matrix::sum_matrix(const S21Matrix& other) {
    if (this->check_matrix_(other)) {
        for (int i = 0; i < other.rows_; i++) {
            for (int j = 0; j < other.cols_; j++) {
                this->matrix_[i][j] = this->matrix_[i][j] + other.matrix_[i][j];
            }
        }
    } else {
        throw std::out_of_range("Error: Incorrect size of matrix");
    }
}

void S21Matrix:: sub_matrix(const S21Matrix& other) {
    if (this->check_matrix_(other)) {
        for (int i = 0; i < other.rows_; i++) {
            for (int j = 0; j < other.cols_; j++) {
                this->matrix_[i][j] = this->matrix_[i][j] - other.matrix_[i][j];
                }
            }
    } else {
        throw std::out_of_range("Error: Incorrect size of matrix");
    }
}

void S21Matrix::mul_number(const double number) {
    if (this->matrix_ != nullptr) {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->cols_; j++)
                if (this->matrix_[i][j] != 0)
                    this->matrix_[i][j] = this->matrix_[i][j] * number;
        }
    }
}

void S21Matrix::mul_matrix(const S21Matrix& other) {
    if (this->matrix_ != nullptr && (this->rows_ == other.cols_) && this->cols_ == other.rows_) {
        S21Matrix c(this->rows_, this->cols_);
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < other.cols_; j++) {
                for (int k = 0; k < this->cols_; k++)
                    c.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
           }
        }
    *this = c;
    } else {
        throw std::out_of_range("Error: rows not equal columns");
    }
}

S21Matrix S21Matrix::transpose() {
    S21Matrix c(this->rows_, this->cols_);
    if (this->matrix_ != nullptr) {
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++)
                    c.matrix_[j][i] = this->matrix_[i][j];
            }
    }
    return c;
}

S21Matrix S21Matrix::minor_matrix(int rows_, int cols_) {
    S21Matrix minormatrix_((this->rows_ - 1), (this->cols_ - 1));
    for (int i = 0, x = 0; i < this->rows_; i++) {
        if (rows_ != i) {
            for (int j = 0, y = 0; j < this->cols_; j++) {
                if (cols_ != j) {
                    minormatrix_.matrix_[x][y] = this->matrix_[i][j];
                    y++;
                }
            }
            x++;
        }
    }
    return minormatrix_;
}

double S21Matrix::determinant() {
    double determinant = 0;
    if (this->matrix_ != nullptr) {
        if (this->cols_ == this->rows_) {
            if (this->rows_ == 1 && this->cols_ == 1) {
                determinant = this->matrix_[0][0];
            }
            if (this->rows_ == 2 && this->cols_ == 2) {
                determinant = (this->matrix_[0][0] * this->matrix_[1][1]) -
                (this->matrix_[0][1] * this->matrix_[1][0]);
            }
            if (this->rows_ > 2 && this->cols_ > 2) {
                for (int i = 0; i < this->cols_; i++) {
                    S21Matrix minor((*this).minor_matrix(0, i));
                    double tmp_determinant = minor.determinant();
                    double tmp_res = pow(-1, 2 + i) * this->matrix_[0][i] * tmp_determinant;
                    determinant += tmp_res;
                }
            }
        } else {
            throw std::out_of_range("Error: rows not equal columns");
        }
    }
    return determinant;
}

S21Matrix S21Matrix::calc_complements() {
    S21Matrix m(this->cols_, this->rows_);
    if (this->matrix_ != nullptr) {
        if (this->cols_ == this->rows_) {
            S21Matrix tmp;
            double temp = 0;
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++) {
                    tmp = (this->minor_matrix(i, j));
                    temp = tmp.determinant();
                    m.matrix_[i][j] = temp * pow(-1, 2 + i + j);
                }
            }
        }  else {
            throw std::out_of_range("Error: rows not equal columns");
        }
    }
    return m;
}

S21Matrix S21Matrix::inverse_matrix() {
    double determ = 0.0;
    S21Matrix m((this->rows_), (this->cols_));
    if (this->matrix_ != nullptr) {
        determ = (*this).determinant();
        if (determ != 0) {
            S21Matrix minor_matrix((*this).calc_complements());
            S21Matrix transp_matrix(minor_matrix.transpose());
            transp_matrix.mul_number(1.0 / determ);
            m = transp_matrix;
        } else {
            throw std::out_of_range("Error: determinant = 0");
        }
    }
    return m;
}

void S21Matrix::set_sizerows_(int x) {
    S21Matrix c(x, this->cols_);
    int rows;
    if (x > this->rows_) {
        rows = this->rows_;
    } else {
        rows = x;
    }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < this->cols_; j++) {
                c.matrix_[i][j] = this->matrix_[i][j];
            }
        }
        (*this).remove_matrix_();
        this->matrix_ = c.matrix_;
        c.matrix_ = nullptr;
        this->rows_ = x;
}

void S21Matrix::set_sizecols_(int y) {
    S21Matrix c(this->rows_, y);
    int cols = 0;
    if (y > this->cols_) {
        cols = this->cols_;
    } else {
        cols = y;
    }
    for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < cols; j++) {
            c.matrix_[i][j] = this->matrix_[i][j];
        }
    }
    (*this).remove_matrix_();
    this->matrix_ = c.matrix_;
    c.matrix_ = nullptr;
    this->cols_ = y;
}

int S21Matrix::getrows_() {
    int res = 0;
    if (this->matrix_) {
        res = this->rows_;
    }
    return res;
}

int S21Matrix::getcols_() {
    int res = 0;
    if (this->matrix_) {
        res = this->cols_;
    }
    return res;
}
S21Matrix S21Matrix::operator + (const S21Matrix& a) {
    S21Matrix s(*this);
    s.sum_matrix(a);
    return s;
}

S21Matrix S21Matrix::operator - (const S21Matrix& a) {
    S21Matrix s(*this);
    s.sub_matrix(a);
    return s;
}

S21Matrix S21Matrix::operator * (const S21Matrix& a) {
    S21Matrix s(*this);
    s.mul_matrix(a);
    return s;
}

S21Matrix S21Matrix::operator * (double a) {
    S21Matrix s(*this);
    s.mul_number(a);
    return s;
}

bool S21Matrix::operator == (const S21Matrix& a) {
    return (*this).eq_matrix(a);
}

bool S21Matrix:: operator != (const S21Matrix& a) {
    return (*this).eq_matrix(a) + 1;
}

S21Matrix S21Matrix::operator = (const S21Matrix& a) {
    if (this->rows_ == a.rows_ && this->cols_ == a.cols_) {
        (*this).setting_value_(a);
    } else {
        this->set_sizerows_(a.rows_);
        this->set_sizecols_(a.cols_);
        *this = a;
    }
    return *this;
}

S21Matrix S21Matrix::operator += (const S21Matrix&a) {
    (*this).sum_matrix(a);
    return *this;
}

S21Matrix S21Matrix::operator -= (const S21Matrix&a) {
    (*this).sub_matrix(a);
    return *this;
}

S21Matrix S21Matrix::operator *= (const S21Matrix&a) {
    (*this).mul_matrix(a);
    return *this;
}

S21Matrix S21Matrix::operator *= (double a) {
    (*this).mul_number(a);
    return *this;
}

double S21Matrix::operator () (int a, int b) {
    double m;
    if (a > this->rows_ || b > this->cols_) {
        throw std::out_of_range("Error: Incorrect index of matrix");
    } else {
        m = this->matrix_[a][b];
    }
    return m;
}

int S21Matrix::check_matrix_(const S21Matrix& other) {
    int res_check = 0;
    if (this->matrix_ != nullptr && other.matrix_ != nullptr) {
        if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
            res_check = 1;
        }
    }
    return res_check;
}
