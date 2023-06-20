/*
 * Copyright 2023 Gleb Tolstenev
 * yonnarge@student.21-school.ru
 *
 * s21_string.h is the header file for s21_string library
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <check.h>
#include <string.h>
#include "s21_string.h"

START_TEST(test_s21_memcmp) {
    char *ab = "ab";
    char *cd = "cd";
    ck_assert_int_eq(s21_memcmp(ab, ab, 3), 0);
    ck_assert_int_lt(s21_memcmp(ab, cd, 3), 0);
    ck_assert_int_eq(s21_memcmp(ab, "ab", 3), 0);
    ck_assert_int_gt(s21_memcmp(ab, "a", 3), 0);
    ck_assert_int_eq(s21_memcmp(ab, "a", 1), 0);
    ck_assert_int_eq(s21_memcmp(ab, "a", 0), 0);
    ck_assert_int_lt(s21_memcmp(ab, "b", 3), 0);
    ck_assert_int_gt(s21_memcmp(ab, "\0", 3), 0);
}
END_TEST

START_TEST(test_s21_memcpy) {
    char *s4 = "abcd";
    char *s3 = "xyz";
    char d3[3] = {0, 0, 0};
    char d5[5] = {0, 0, 0, 0, 0};

    ck_assert_str_eq(s21_memcpy(d3, s3, 0), memcpy(d3, s3, 0));
    ck_assert_str_eq(s21_memcpy(d5, s3, sizeof(char)*3), memcpy(d5, s3, sizeof(char)*3));
    ck_assert_str_eq(s21_memcpy(d5, s4, sizeof(char)*4), memcpy(d5, s4, sizeof(char)*4));
    ck_assert_str_eq(s21_memcpy(d5, s4, sizeof(char)*5), memcpy(d5, s4, sizeof(char)*5));
}
END_TEST

START_TEST(test_s21_memchr) {
    char *ab = "ab";
    ck_assert_str_eq(s21_memchr(ab, 'a', 1), memchr(ab, 'a', 1));
    ck_assert_str_eq(s21_memchr(ab, 'b', 2), memchr(ab, 'b', 2));
    ck_assert_str_eq(s21_memchr(ab, '\0', 3), memchr(ab, '\0', 3));
    ck_assert_str_eq(s21_memchr("aba", 'a', 4), memchr("aba", 'a', 4));
    ck_assert_str_eq(s21_memchr("ab\0a", 'a', 4), memchr("ab\0a", 'a', 4));

    ck_assert_ptr_eq(s21_memchr(ab, 'c', 3), memchr(ab, 'c', 3));
    ck_assert_ptr_eq(s21_memchr(ab, 'c', 4), memchr(ab, 'c', 4));
    ck_assert_ptr_eq(s21_memchr(ab, 'c', 0), memchr(ab, 'c', 0));
    ck_assert_ptr_eq(s21_memchr(ab, 'a', 0), memchr(ab, 'a', 0));
}
END_TEST

START_TEST(test_s21_memmove) {
    char s[] = "abcde";
    ck_assert_str_eq(s21_memmove(s, s, 0), memmove(s, s, 0));
    ck_assert_str_eq(s21_memmove(s, s, 2), memmove(s, s, 2));
    ck_assert_str_eq(s21_memmove(s, s + 1, 0), memmove(s, s + 1, 0));
    ck_assert_str_eq(s21_memmove(s + 1, s, 0), memmove(s + 1, s, 0));
    ck_assert_str_eq(s21_memmove(s, s + 2, 2), memmove(s, s + 2, 2));
    ck_assert_str_eq(s21_memmove(s + 2, s, 2), memmove(s + 2, s, 2));
    ck_assert_str_eq(s21_memmove(s, s + 3, 2), memmove(s, s + 3, 2));
    ck_assert_str_eq(s21_memmove(s + 3, s, 2), memmove(s + 3, s, 2));
}
END_TEST

START_TEST(test_s21_memset) {
    char a[] = "defg";
    char b[] = "defg";
    char c[] = "";
    ck_assert_str_eq(s21_memset(a, 'y', 3), memset(a, 'y', 3));
    ck_assert_str_eq(s21_memset(b, 'a', 5), memset(b, 'a', 5));
    ck_assert_str_eq(s21_memset(c, 'b', 1), memset(c, 'b', 1));
    ck_assert_str_eq(s21_memset(c, '\0', 1), memset(c, '\0', 1));
}
END_TEST

Suite *lib_suite_create(void) {
    Suite *suite_s21_string = suite_create("Suite_of_test_s21_string");
    TCase *tc_core_s21_string = tcase_create("Core_of_test_s21_string");

    tcase_add_test(tc_core_s21_string, test_s21_memcpy);
    tcase_add_test(tc_core_s21_string, test_s21_memchr);
    tcase_add_test(tc_core_s21_string, test_s21_memcmp);
    tcase_add_test(tc_core_s21_string, test_s21_memmove);
    tcase_add_test(tc_core_s21_string, test_s21_memset);

    suite_add_tcase(suite_s21_string, tc_core_s21_string);

    return suite_s21_string;
}

int main(void) {
    int failed_counter;
    Suite *suite = lib_suite_create();
    SRunner *suite_runner = srunner_create(suite);

    srunner_run_all(suite_runner, CK_NORMAL);
    failed_counter = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (failed_counter == 0 ? 0 : 2);
}



