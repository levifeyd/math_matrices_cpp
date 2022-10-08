TEST = all_tests
HEADER = s21_matrix_oop.h
SRC = s21_matrix_oop.cpp
SRC_TEST = tests.cpp
LIB = s21_matrix_oop.a
OBJ = $(patsubst %.cpp, %.o, $(SRC))
OBJ_TEST = $(patsubst %.cpp, %.o, $(SRC_TEST))
WWW = -std=c++17 -Wall -Werror -Wextra -lstdc++ -g
LIB_FLAGS = -lgtest -Dgtest_disable_pthreads=OFF
COV_FLAGS = --coverage

.PHONY: all, clean, test, s21_matrix_oop.a

all: test clean

s21_matrix_oop.a: $(OBJ)
	ar rcs $@ $?
	ranlib $(LIB)

%.o: %.cpp $(HEADER)
	gcc $(WWW) -c $< -o $@

test: clean
	gcc $(WWW) $(SRC_TEST) $(SRC) $(LIB_FLAGS) $(COV_FLAGS) -o $(TEST)
	./$(TEST)

clean:
	@rm -rf *.info report *.gcda *.gcno
	@rm -rf a.out *.dSYM $(TEST) $(LIB) $(OBJ)

style_check:
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp *.h
	@rm -rf CPPLINT*.cfg
