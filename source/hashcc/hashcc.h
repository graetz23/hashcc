/** 
 * @file hashcc.h
 * @author Christian Scheiblich
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2009-2018 Christian Scheiblich (cscheiblich@gmail.com)
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
#include "./hashccTest.h"  // HASHCC::TEST::

/******************************************************************************/

namespace HASHCC {

/// use and share by the MIT License (MIT)
#define _HASHCC_LICENSE_ "MIT"

/// from http://www.kleimo.com/random/name.cfm female, 1, 99
// Pauletta Freshley 20090926 0.00
#define _HASHCC_PACKAGE_ "Deeaan Lampel" // since 20091014

/// first load test are done for prototype of binary hash function and tree
#define _HASHCC_VERSION_NO_ "0.16"
#define _HASHCC_VERSION_DATE_ 20160106

} // namespace HASHCC

/******************************************************************************/

#endif // ___hashcc_h__
