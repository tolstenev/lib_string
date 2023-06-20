#
# Copyright 2023 Gleb Tolstenev
# yonnarge@student.21-school.ru
#
# Makefile for s21_string library
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

NAME = s21_string.a
HEADER = s21_string.h
TEST = s21_string_unit_test
REPORT = GcovReport

CC = gcc
GCOVFLAGS = -fprofile-arcs -ftest-coverage
CFLAGS = -std=c11 -Wall -Werror -Wextra
OS = $(shell uname)
ifeq ($(OS), Linux)
    CHECK_FLAGS = -lcheck -lpthread -lrt -lm
else
    CHECK_FLAGS = -lcheck
endif

# Основные функции библиотеки
SRCS_LIBS = s21_memchr.c	\
            s21_memcmp.c	\
            s21_memcpy.c	\
            s21_memset.c	\
            s21_memmove.c

SRCS = $(SRCS_LIBS)

OBJS = $(SRCS:.c=.o)

all: s21_string.a

s21_string.a: $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	$(CC) $< $(TEST).c $(NAME) $(CHECK_FLAGS) -o $(TEST)
	./$(TEST)

gcov_report:
	gcc $(GCOVFLAGS) $(TEST).c $(SRCS) $(CHECK_FLAGS) -o $(REPORT)
	chmod +x *
	./GcovReport
	lcov -t "$(REPORT)" -o $(REPORT).info -c -d .
	genhtml -o report $(REPORT).info
	rm -rf ./*.gcno ./*.gcda ./$(REPORT).*
	@echo Code coverage report generated. To view the report via web-browser, enter the command \"open ./report/index.html\"

check: $(NAME)
	@echo ---------------------CPPCHECK---------------------
	cppcheck *.h *.c
	@echo -------------------MEMORY_LEAKS-------------------
	$(CC) -g $(TEST).c $(NAME) $(CHECK_FLAGS) -o $(TEST)
	CK_FORK=no leaks --atExit -- ./$(TEST)

check_valgrind: $(NAME)
	@echo -------------------MEMORY_LEAKS-------------------
	$(CC) -g $(TEST).c $(NAME) $(CHECK_FLAGS) -o $(TEST)
	CK_FORK=no valgrind --leak-check=full -s ./$(TEST)

clean:
	rm -rf $(OBJS) ./GcovReport ./*.gcov ./*.gcno ./*.gcda ./report ./*.info ./*.dSYM ./$(TEST)

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all test check check_valgrind clean fclean re
