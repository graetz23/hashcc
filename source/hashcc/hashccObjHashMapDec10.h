/** 
 * @file hashccObjHashMapDec10.h
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

#ifndef __hashccObjHashMapDec10_h__
#define __hashccObjHashMapDec10_h__

/******************************************************************************/

#include "./hashccObjHashMapDec.h" // HASHCC::OBJ::HashMap<T>

/******************************************************************************/

namespace HASHCC {

namespace OBJ {

/******************************************************************************/

#define _VERSION_HASHCC_OBJ_HashMapDec10_ 0.15 // 20141231
#define _DEBUG_HASHCC_OBJ_HashMapDec10_

/// class as pattern for following classes
template<typename K, typename V> class 
HashMapDec10 : public HashMapDec<K,V> {
 public:

  HashMapDec10( void ); /// constructor
  virtual ~HashMapDec10( void ); /// destructor deletes all members for DEC

}; // class HashMapDec10

/******************************************************************************/
  
template<typename K, typename V> /// constructor 
HashMapDec10<K,V>::HashMapDec10( void ) {
  this->_keySize = 10; // depth 24 symbols in tree -> 10^24 hashes
} // HashMapDec10

template<typename K, typename V> /// destructor deletes all members for DEC
HashMapDec10<K,V>::~HashMapDec10( void ) {
} // ~HashMapDec10

/******************************************************************************/

} // namespace OBJ

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccObjHashMapDec10_h__

