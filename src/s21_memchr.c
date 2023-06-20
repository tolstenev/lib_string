/*
 * Copyright 2023 Gleb Tolstenev
 * yonnarge@student.21-school.ru
 *
 * s21_memchr.c is the source file for s21_string library
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

#include "s21_string.h"

/*
 * Функция s21_memchr ищет символ 'c' в первых n байтах
 * той области памяти, на которую указывает str.
 * Совпадение первого байта с 'c' (представленным как беззнаковый символ)
 * останавливает выполнение операции.
 */
void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *p = (unsigned char *)str;
    unsigned char *result = S21_NULL;
    for (; n != 0; n--, p++) {
        if (*p == (unsigned char)c) {
            result = p;
            break;
        }
    }
    return (result);
}
