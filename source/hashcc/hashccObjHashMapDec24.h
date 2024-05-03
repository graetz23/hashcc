/**
 * @file hashccObjHashMapDec24.h
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

#ifndef __hashccObjHashMapDec24_h__
#define __hashccObjHashMapDec24_h__

/******************************************************************************/

#include "./hashccObjHashMapDec.h" // HASHCC::OBJ::HashMap<T>

/******************************************************************************/

namespace HASHCC {

namespace OBJ {

/******************************************************************************/

#define _DEBUG_HASHCC_OBJ_HashMapDec24_

/// class as pattern for following classes
template<typename K, typename V> class
HashMapDec24 : public HashMapDec<K,V> {
 public:

  HashMapDec24( void ); /// constructor
  virtual ~HashMapDec24( void ); /// destructor deletes all members for DEC

}; // class HashMapDec24

/******************************************************************************/

template<typename K, typename V> /// constructor
HashMapDec24<K,V>::HashMapDec24( void ) {
  this->_keySize = 24; // depth 24 symbols in tree -> 10^24 hashes
} // HashMapDec24

template<typename K, typename V> /// destructor deletes all members for DEC
HashMapDec24<K,V>::~HashMapDec24( void ) {
} // ~HashMapDec24

/******************************************************************************/

} // namespace OBJ

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccObjHashMapDec24_h__
