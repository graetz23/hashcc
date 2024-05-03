/**
 * @file hashccTypes.h
 * @author Christian (graetz23@gmail.com)
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2024 Christian (graez23@gmail.com)
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

//typedef __int8_t int8_t;
//typedef unsigned __int8_t uint8_t;
//typedef __int16_t int16_t;
//typedef unsigned __int16_t uint16_t;
//typedef __int32_t int32_t;
//typedef unsigned __int32_t uint32_t;
//typedef __int64_t int64_t;
//typedef unsigned __int64_t uint64_t;

/******************************************************************************/

typedef char                              Char; // char typedef
typedef const char                       cChar; // char typedef
typedef unsigned char                    uChar; // char typedef
typedef const unsigned char             cuChar; // char typedef

/******************************************************************************/

typedef int                              Int16; // 16 bit typedef
typedef const int                       cInt16; // 16 bit typedef
typedef unsigned int                    uInt16; // 16 bit typedef
typedef const unsigned int             cuInt16; // 16 bit typedef

/******************************************************************************/

typedef long int                         Int32; // 32 bit typedef
typedef const long int                  cInt32; // 32 bit typedef
typedef unsigned long int               uInt32; // 32 bit typedef
typedef const unsigned long int        cuInt32; // 32 bit typedef

/******************************************************************************/

typedef long long int                    Int64; // 64 bit typedef
typedef const long long int             cInt64; // 64 bit typedef
typedef unsigned long long int          uInt64; // 64 bit typedef
typedef const unsigned long long int   cuInt64; // 64 bit typedef

/******************************************************************************/

typedef std::string                     String; // typedef

/******************************************************************************/

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccTypes_h__
