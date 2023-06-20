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

#ifndef LIB_STRING_SRC_S21_STRING_H_
#define LIB_STRING_SRC_S21_STRING_H_

#define S21_NULL (void *) 0
typedef long unsigned s21_size_t;

void*       s21_memchr(const void *str, int c, s21_size_t n);
int         s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void*       s21_memcpy(void *dest, const void *src, s21_size_t n);
void*       s21_memmove(void *dest, const void *src, s21_size_t n);
void*       s21_memset(void *str, int c, s21_size_t n);

#endif //LIB_STRING_SRC_S21_STRING_H_
