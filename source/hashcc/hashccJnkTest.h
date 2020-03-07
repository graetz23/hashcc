/** 
 * @file hashccJnkTest.h
 * @author Christian Scheiblich
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2018 Christian (graez23@gmail.com)
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

#ifndef __hashccJnkTest_h__
#define __hashccJnkTest_h__

/******************************************************************************/

#include "./hashccTyp.h" // HASHCC::TYP::
#include "./hashccErr.h" // HASHCC::ERR::
#include "./hashccFnc.h" // HASHCC::FNC::
#include "./hashccObj.h" // HASHCC::OBJ::
#include "./hashccJnk.h" // HASHCC::JNK::

/******************************************************************************/

namespace HASHCC {

namespace JNK {

/******************************************************************************/

#define _VERSION_HASHCC_JnkTest_ 0.15 // 20141231
#define _DEBUG_HASHCC_JnkTest_

void test( void ); /// tests the TreeController and the Tree

/******************************************************************************/

} // namespace TEST

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccJnkTest_h__
