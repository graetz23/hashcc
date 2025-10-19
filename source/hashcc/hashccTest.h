/**
 * @file hashccTest.h
 * @author Christian (graetz23@gmail.com)
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2025 Christian (graez23@gmail.com)
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

#ifndef __hashccTest_h__
#define __hashccTest_h__

/******************************************************************************/

#include "./hashccTyp.h" // HASHCC::TYP::
#include "./hashccErr.h" // HASHCC::ERR::
#include "./hashccFnc.h" // HASHCC::FNC::
#include "./hashccDmy.h" // HASHCC::DMY::
#include "./hashccObj.h" // HASHCC::OBJ::
#include "./hashccJnk.h" // HASHCC::JNK::
#include "./hashccTypTreeController.h" // HASHCC::TYP::TreeController

/******************************************************************************/

namespace HASHCC {

namespace TEST {

/******************************************************************************/

#define _DEBUG_HASHCC_Test_

void test( void ); /// tests the TreeController and the Tree
void testStc( void ); /// tests HASHCC::STC:: statics
void testHash( void ); // testing all hashing function
void testHashFnv( void ); /// tests HASHCC::FNC:: hash functions
void testHashAdler( void ); /// tests HASHCC::FNC:: hash functions
void testHashMap( OBJ::Type::HashMap hashMapType ); /// testing for different keys and value types

/******************************************************************************/

} // namespace TEST

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccTest_h__
