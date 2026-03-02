/**
 * @file hashcc.h
 * @brief Main include file for HASHCC library
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
 * @defgroup HASHCC HASHCC Library
 * @brief Template-based C++ Hash Map Library
 *
 * HASHCC is an object-oriented C++ hash map library based on C++ templates.
 * It implements a trie-like hash tree data structure, providing efficient
 * key-value storage with customizable hash functions.
 *
 * @li @ref Types - Core type definitions
 * @li @ref STC - Static character tables
 * @li @ref TYP - Type system and tree structures
 * @li @ref ERR - Error handling
 * @li @ref FNC - Hash functions
 * @li @ref DMY - Dummy/placeholder objects
 * @li @ref OBJ - Hash map objects
 */

#ifndef __hashcc_h__
#define __hashcc_h__

/******************************************************************************/

#include "./hashccTypes.h" // HASHCC:: used data types
#include "./hashccStc.h"   // HASHCC::STC::
#include "./hashccTyp.h"   // HASHCC::TYP::
#include "./hashccErr.h"   // HASHCC::TYP::
#include "./hashccFnc.h"   // HASHCC::FNC::
#include "./hashccDmy.h"   // HASHCC::DMY::
#include "./hashccObj.h"   // HASHCC::OBJ::

/******************************************************************************/

namespace HASHCC {

/** @brief License identifier */
#define _HASHCC_LICENSE_ "MIT"

/**
 * @brief Package name
 * @details From http://www.kleimo.com/random/name.cfm female, 1, 99
 * - Pauletta Freshley 20090926 0.00
 * - Deeaan Lampel 20160106 0.10
 */
#define _HASHCC_PACKAGE_ "Agnes Newton"

/** @brief Version number */
#define _HASHCC_VERSION_NO_ "0.20"

/** @brief Version date (YYYYMMDD) */
#define _HASHCC_VERSION_DATE_ 20200307

} // namespace HASHCC

/******************************************************************************/

#endif // ___hashcc_h__
