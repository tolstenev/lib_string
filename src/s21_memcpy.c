/*
 * Copyright 2023 Gleb Tolstenev
 * yonnarge@student.21-school.ru
 *
 * s21_memcpy.c is the source file for s21_string library
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
 * Функция s21_memcpy копирует n байтов из области памяти src
 * в область памяти dest. Области памяти НЕ МОГУТ пересекаться.
 * Используйте s21_memmove, если области памяти перекрываются.
 */
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *dp = dest;
    const char *sp = src;
    while (n != 0) {
        *dp = *sp;
        dp++;
        sp++;
        n--;
    }
    return dest;
}
