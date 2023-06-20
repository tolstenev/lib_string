/*
 * Copyright 2023 Gleb Tolstenev
 * yonnarge@student.21-school.ru
 *
 * s21_memcmp.c is the source file for s21_string library
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
 * Функция s21_memcmp сравнивает первые n байтов областей памяти
 * str1 и str2. Функция возвращает целое число.
 * Число будет больше нуля, если s1 больше s2.
 * Число будет меньше нуля, если s1 меньше s2.
 * При равенстве строк (и по длине и по составу) функция вернёт ноль.
 */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *p1 = str1, *p2 = str2;
    int result = 0;
    for (; n != 0; n--, p1++, p2++) {
        if (*p1 != *p2) {
            result = *p1 - *p2;
            break;
        }
    }
    return (result);
}
