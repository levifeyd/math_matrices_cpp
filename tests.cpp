#include "s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(tests_of_matrix, eq_1) {
    S21Matrix a(4, 4);
    S21Matrix b(4, 4);
    bool equal = a.eq_matrix(b);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, eq_2) {
    S21Matrix a(4, 4);
    S21Matrix b(5, 5);
    bool equal = a.eq_matrix(b);
    ASSERT_EQ(0, equal);
}
TEST(tests_of_matrix, eq_3) {
    S21Matrix a(4, 4);
    a.init_matrix_1_();
    S21Matrix b(4, 4);
    bool equal = a.eq_matrix(b);
    ASSERT_EQ(0, equal);
}
TEST(tests_of_matrix, sum_1) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(a);
    b.sum_matrix(a);
    S21Matrix s;
    s.init_sum_();
    bool equal = s.eq_matrix(b);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, sum_2) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    b.sum_matrix(a);
    S21Matrix s;
    s.init_sum_();
    bool equal = s.eq_matrix(b);
    ASSERT_EQ(0, equal);
}
TEST(tests_of_matrix, sum_3) {
    try {
        S21Matrix a(4, 4);
        S21Matrix b(3, 3);
        b.sum_matrix(a);
        FAIL() << "Expected std::Error: Incorrect size of matrix";
    }
    catch(std::out_of_range const & err) {
        std:: cout << err.what();
        ASSERT_EQ(err.what(), std::string("Error: Incorrect size of matrix"));
    }
}
TEST(tests_of_matrix, sub_1) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    b.init_matrix_3_();
    b.sub_matrix(a);
    S21Matrix s(4, 4);
    bool equal = s.eq_matrix(b);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, sub_2) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    b.init_matrix_3_();
    b.sub_matrix(a);
    S21Matrix s(4, 4);
    s.init_sum_();
    bool equal = s.eq_matrix(b);
    ASSERT_EQ(0, equal);
}
TEST(tests_of_matrix, sub_3) {
    S21Matrix a(4, 4);
    S21Matrix b(3, 3);
    try {
        S21Matrix a(4, 4);
        S21Matrix b(3, 3);
        b.sub_matrix(a);
        FAIL() << "Expected std::Error: Incorrect size of matrix";
    }
    catch(std::out_of_range const & err) {
        std:: cout << err.what();
        ASSERT_EQ(err.what(), std::string("Error: Incorrect size of matrix"));
    }
}
TEST(tests_of_matrix, mul_n_1) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    b.init_matrix_3_();
    double m = 2.0;
    b.mul_number(m);
    S21Matrix s(4, 4);
    s.init_sum_();
    bool equal = s.eq_matrix(b);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, mul_matrix_1) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    b.init_matrix_3_();
    a.mul_matrix(b);
    S21Matrix s(4, 4);
    s.init_mull_();
    bool equal = s.eq_matrix(a);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, mul_matrix_2) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    a.mul_matrix(b);
    S21Matrix s(4, 4);
    bool equal = s.eq_matrix(a);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, mul_matrix_3) {
    try {
        S21Matrix a(4, 4);
        a.init_matrix_3_();
        S21Matrix b(3, 7);
        a.mul_matrix(b);
    }
    catch(std::out_of_range const & err) {
         std:: cout << err.what();
        ASSERT_EQ(err.what(), std::string("Error: rows not equal columns"));
    }
}
TEST(tests_of_matrix, transpose) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    b.init_transp_();
    a.transpose();
    bool equal = b.eq_matrix(a);
    ASSERT_EQ(0, equal);
}
TEST(tests_of_matrix, determinant_1) {
    S21Matrix a(4, 4);
    a.init_matrix_1_();
    double det = a.determinant();
    ASSERT_DOUBLE_EQ(-1128.000000, det);
}

TEST(tests_of_matrix, determinant_2) {
    S21Matrix a(3, 3);
    a.init_matrix_3_();
    double det = a.determinant();
    ASSERT_DOUBLE_EQ(0, det);
}
TEST(tests_of_matrix, cal_c_matrix_1) {
    try {
        S21Matrix a(4, 7);
        a.init_matrix_3_();
        S21Matrix b = a.calc_complements();
    }
    catch(std::out_of_range const & err) {
         std:: cout << err.what();
        ASSERT_EQ(err.what(), std::string("Error: rows not equal columns"));
    }
}
TEST(tests_of_matrix, calc_c_matrix_2) {
    S21Matrix a(4, 4);
    a.init_matrix_1_();
    S21Matrix b = a.calc_complements();
    S21Matrix c(4, 4);
    c.init_calc_();
    bool equal = b.eq_matrix(c);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, inverse_matrix_1) {
    S21Matrix a(4, 4);
    a.init_matrix_1_();
    S21Matrix b = a.inverse_matrix();
    S21Matrix c(4, 4);
    c.init_inverse_();
    bool equal = b.eq_matrix(c);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, inverse_matrix_2) {
    try {
        S21Matrix a(4, 4);
        a.init_matrix_3_();
        S21Matrix b = a.inverse_matrix();
    }
    catch(std::out_of_range const & err) {
         std:: cout << err.what();
        ASSERT_EQ(err.what(), std::string("Error: determinant = 0"));
    }
}
TEST(tests_of_matrix, set_1) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    a.set_sizerows_(2);
    a.set_sizecols_(2);
    S21Matrix c(2, 2);
    c.init_set_();
    bool equal = a.eq_matrix(c);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, set_2) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    a.set_sizecols_(5);
    S21Matrix c(4, 5);
    c.init_set_2_();
    bool equal = a.eq_matrix(c);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, get_1) {
    S21Matrix a(4, 4);
    int size = a.getrows_();
    ASSERT_EQ(4, size);
}
TEST(tests_of_matrix, get_2) {
    S21Matrix a(4, 4);
    int size = a.getcols_();
    ASSERT_EQ(4, size);
}
TEST(tests_of_matrix, op_plus) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    b.init_matrix_3_();
    S21Matrix sum = a + b;
    S21Matrix s;
    s.init_sum_();
    bool equal = s.eq_matrix(sum);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, op_sub) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    b.init_matrix_3_();
    S21Matrix sub = a - b;
    S21Matrix s(4, 4);
    bool equal = s.eq_matrix(sub);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, op_mul) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    b.init_matrix_3_();
    S21Matrix mul = a * b;
    S21Matrix s(4, 4);
    s.init_mull_();
    bool equal = s.eq_matrix(mul);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, op_plus_eq) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    b.init_matrix_3_();
    a += b;
    S21Matrix s;
    s.init_sum_();
    bool equal = s.eq_matrix(a);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, op_sub_eq) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    b.init_matrix_3_();
    a -= b;
    S21Matrix s(4, 4);
    bool equal = s.eq_matrix(a);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, op_mul_8) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(4, 4);
    b.init_matrix_3_();
    a *= b;
    S21Matrix s(4, 4);
    s.init_mull_();
    bool equal = s.eq_matrix(a);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, mul_eq) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    // S21Matrix b(std::move(a));
    S21Matrix b(a);
    b.init_matrix_3_();
    double m = 2.0;
    b *= m;
    S21Matrix s(4, 4);
    s.init_sum_();
    bool equal = s.eq_matrix(b);
    ASSERT_EQ(1, equal);
}
TEST(tests_of_matrix, eq_8) {
    S21Matrix a(4, 4);
    a.init_matrix_3_();
    S21Matrix b(a);
    bool equal = false;
    if (b == a) {
        equal = true;
    }
    ASSERT_EQ(1, equal);
}
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
