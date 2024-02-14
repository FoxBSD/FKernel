/*
BSD 3-Clause License

Copyright (c) 2024, FoxBSD

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#pragma once

#ifndef _STDINT_H
#define _STDINT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Signed 8-bit integer type.
 */
typedef __INT8_TYPE__ int8_t;

/**
 * @brief Signed 16-bit integer type.
 */
typedef __INT16_TYPE__ int16_t;

/**
 * @brief Signed 32-bit integer type.
 */
typedef __INT32_TYPE__ int32_t;

/**
 * @brief Signed 64-bit integer type.
 */
typedef __INT64_TYPE__ int64_t;

/**
 * @brief Unsigned 8-bit integer type.
 */
typedef __UINT8_TYPE__ uint8_t;

/**
 * @brief Unsigned 16-bit integer type.
 */
typedef __UINT16_TYPE__ uint16_t;

/**
 * @brief Unsigned 32-bit integer type.
 */
typedef __UINT32_TYPE__ uint32_t;

/**
 * @brief Unsigned 64-bit integer type.
 */
typedef __UINT64_TYPE__ uint64_t;

/**
 * @brief Signed integer type with a width of at least 8 bits.
 */
typedef __INT_LEAST8_TYPE__ int_least8_t;

/**
 * @brief Signed integer type with a width of at least 16 bits.
 */
typedef __INT_LEAST16_TYPE__ int_least16_t;

/**
 * @brief Signed integer type with a width of at least 32 bits.
 */
typedef __INT_LEAST32_TYPE__ int_least32_t;

/**
 * @brief Signed integer type with a width of at least 64 bits.
 */
typedef __INT_LEAST64_TYPE__ int_least64_t;

/**
 * @brief Unsigned integer type with a width of at least 8 bits.
 */
typedef __UINT_LEAST8_TYPE__ uint_least8_t;

/**
 * @brief Unsigned integer type with a width of at least 16 bits.
 */
typedef __UINT_LEAST16_TYPE__ uint_least16_t;

/**
 * @brief Unsigned integer type with a width of at least 32 bits.
 */
typedef __UINT_LEAST32_TYPE__ uint_least32_t;

/**
 * @brief Unsigned integer type with a width of at least 64 bits.
 */
typedef __UINT_LEAST64_TYPE__ uint_least64_t;

/**
 * @brief Fastest signed integer type with a width of at least 8 bits.
 */
typedef __INT_FAST8_TYPE__ int_fast8_t;

/**
 * @brief Fastest signed integer type with a width of at least 16 bits.
 */
typedef __INT_FAST16_TYPE__ int_fast16_t;

/**
 * @brief Fastest signed integer type with a width of at least 32 bits.
 */
typedef __INT_FAST32_TYPE__ int_fast32_t;

/**
 * @brief Fastest signed integer type with a width of at least 64 bits.
 */
typedef __INT_FAST64_TYPE__ int_fast64_t;

/**
 * @brief Fastest unsigned integer type with a width of at least 8 bits.
 */
typedef __UINT_FAST8_TYPE__ uint_fast8_t;

/**
 * @brief Fastest unsigned integer type with a width of at least 16 bits.
 */
typedef __UINT_FAST16_TYPE__ uint_fast16_t;

/**
 * @brief Fastest unsigned integer type with a width of at least 32 bits.
 */
typedef __UINT_FAST32_TYPE__ uint_fast32_t;

/**
 * @brief Fastest unsigned integer type with a width of at least 64 bits.
 */
typedef __UINT_FAST64_TYPE__ uint_fast64_t;

/**
 * @brief Largest signed integer type.
 */
typedef __INTMAX_TYPE__ intmax_t;

/**
 * @brief Largest unsigned integer type.
 */
typedef __UINTMAX_TYPE__ uintmax_t;

#ifdef __cplusplus
}
#endif

#endif /* _STDINT_H */