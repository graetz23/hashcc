/**
 * @file hashccTypes.h
 * @brief Type definitions for HASHCC library
 * @author Christian (graetz23@gmail.com)
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2026 Christian (graez23@gmail.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @defgroup Types Type Definitions
 * @brief Core type definitions used throughout the HASHCC library.
 *
 * This file provides platform-independent type definitions for characters,
 * integers, and strings used by the HASHCC library.
 */

#ifndef __hashccTypes_h__
#define __hashccTypes_h__

/******************************************************************************/

#include <exception> // std::exception
#include <typeinfo>  // dynamic_cast<T>
#include <iostream>  // std::cout
#include <sstream>   // std::strstream
#include <bitset>    // std::bitset
#include <limits>    // std::numeric_limits
#include <string>    // std::string
#include <math.h>    // mathematics
#include <stack>     // std::stack

/******************************************************************************/

namespace HASHCC {

#define _DEBUG_HASHCC_Types_

/******************************************************************************/

/// for compiling the actual date
#define _HASHCC_BUILT_DATE_ __DATE__

/// for compiling the actual time
#define _HASHCC_BUILT_TIME_ __TIME__
/// enable this for debug code running

/// define this to use development code in HASHCC:: namespace
#define _HASHCC_USE_DEV_
#ifdef _HASHCC_USE_DEV_
  // pattern used in code to activate debug code
#endif

/// activate debug code
#define _DEBUG_HASHCC_

/******************************************************************************/

/**
 * @defgroup CharTypes Character Types
 * @brief Character type definitions
 * @ingroup Types
 */

/** @brief Character type (8-bit) @ingroup CharTypes */
typedef char                              Char; // char typedef
/** @brief Constant character type (8-bit) @ingroup CharTypes */
typedef const char                       cChar; // char typedef
/** @brief Unsigned character type (8-bit) @ingroup CharTypes */
typedef unsigned char                    uChar; // char typedef
/** @brief Constant unsigned character type (8-bit) @ingroup CharTypes */
typedef const unsigned char             cuChar; // char typedef

/******************************************************************************/

/**
 * @defgroup Int16Types 16-bit Integer Types
 * @brief 16-bit integer type definitions
 * @ingroup Types
 */

/** @brief 16-bit signed integer type @ingroup Int16Types */
typedef int                              Int16; // 16 bit typedef
/** @brief Constant 16-bit signed integer type @ingroup Int16Types */
typedef const int                       cInt16; // 16 bit typedef
/** @brief 16-bit unsigned integer type @ingroup Int16Types */
typedef unsigned int                    uInt16; // 16 bit typedef
/** @brief Constant 16-bit unsigned integer type @ingroup Int16Types */
typedef const unsigned int             cuInt16; // 16 bit typedef

/******************************************************************************/

/**
 * @defgroup Int32Types 32-bit Integer Types
 * @brief 32-bit integer type definitions
 * @ingroup Types
 */

/** @brief 32-bit signed integer type @ingroup Int32Types */
typedef long int                         Int32; // 32 bit typedef
/** @brief Constant 32-bit signed integer type @ingroup Int32Types */
typedef const long int                  cInt32; // 32 bit typedef
/** @brief 32-bit unsigned integer type @ingroup Int32Types */
typedef unsigned long int               uInt32; // 32 bit typedef
/** @brief Constant 32-bit unsigned integer type @ingroup Int32Types */
typedef const unsigned long int        cuInt32; // 32 bit typedef

/******************************************************************************/

/**
 * @defgroup Int64Types 64-bit Integer Types
 * @brief 64-bit integer type definitions
 * @ingroup Types
 */

/** @brief 64-bit signed integer type @ingroup Int64Types */
typedef long long int                    Int64; // 64 bit typedef
/** @brief Constant 64-bit signed integer type @ingroup Int64Types */
typedef const long long int             cInt64; // 64 bit typedef
/** @brief 64-bit unsigned integer type @ingroup Int64Types */
typedef unsigned long long int          uInt64; // 64 bit typedef
/** @brief Constant 64-bit unsigned integer type @ingroup Int64Types */
typedef const unsigned long long int   cuInt64; // 64 bit typedef

/******************************************************************************/

/**
 * @defgroup StringTypes String Types
 * @brief String type definitions
 * @ingroup Types
 */

/** @brief Standard string type @ingroup StringTypes */
typedef std::string                     String; // typedef

/******************************************************************************/

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccTypes_h__
