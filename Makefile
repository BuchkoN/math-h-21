GCC=gcc -Wall -Wextra -Werror -std=c11
LIBFLAGS=-lcheck
CFLAG=-c
GCOVFLAGS=-fprofile-arcs -ftest-coverage
REPORTPATH=./report

all: test s21_math.a gcov_report

test: s21_math.a s21_math_test.o
	$(GCC) $(LIBFLAGS) s21_math_test.o s21_math.a -o s21_math_test

gcov_report: s21_math_test.o s21_math.a
	$(GCC) $(LIBFLAGS) $(GCOVFLAGS) s21_math.c s21_math_test.o s21_math.a -o $(REPORTPATH)/test_report
	$(REPORTPATH)/test_report
	mv *.gc* $(REPORTPATH)
	lcov -t test_report -o $(REPORTPATH)/report.info -c -d $(REPORTPATH)
	genhtml -o $(REPORTPATH)/html_report $(REPORTPATH)/report.info
	open $(REPORTPATH)/html_report/index.html

s21_math_test.o: s21_math_test.c
	$(GCC) $(CFLAG) s21_math_test.c

s21_math.o: s21_math.c
	$(GCC) $(CFLAG) s21_math.c

s21_math.a: s21_math.o
	ar rc s21_math.a s21_math.o
	ranlib s21_math.a


clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf s21_math_test
	rm -rf $(REPORTPATH)/*

rebuild: clean all