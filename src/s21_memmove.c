/*
 * Copyright 2023 Gleb Tolstenev
 * yonnarge@student.21-school.ru
 *
 * s21_memmove.c is the source file for s21_string library
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
 * Функция s21_memmove копирует n байтов из области памяти src
 * в облать памяти dest. Области памяти могут перекрываться.
 */
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *p_src = (char *)src;
    char *p_dest = dest;
    unsigned long int i;

    if (p_dest < p_src) {
        for (i = 0; i < n; i++) {
            p_dest[i] = p_src[i];
        }
    } else if (p_dest > p_src) {
        for (i = (n - (n != 0)); i > 0 ; i--) {
            p_dest[i] = p_src[i];
        }
        p_dest[0] = p_src[0];
    }
    return p_dest;
}
