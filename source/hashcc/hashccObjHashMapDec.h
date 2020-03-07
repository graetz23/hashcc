/** 
 * @file hashccObjHashMapDec.h
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

#ifndef __hashccObjHashMapDec_h__
#define __hashccObjHashMapDec_h__

/******************************************************************************/

#include "./hashccObjHashMap.h" // HASHCC::OBJ::HashMap<T>

/******************************************************************************/

namespace HASHCC {

namespace OBJ {

/******************************************************************************/

#define _VERSION_HASHCC_OBJ_HashMapDec_ 0.15 // 20141231
#define _DEBUG_HASHCC_OBJ_HashMapDec_

/// class as pattern for following classes
template<typename K, typename V> class 
HashMapDec : public HashMap<K,V> {
 public:

  HashMapDec( void ); /// constructor
  virtual ~HashMapDec( void ); /// destructor deletes all members for DEC

}; // class HashMapDec

/******************************************************************************/
  
template<typename K, typename V> /// constructor 
HashMapDec<K,V>::HashMapDec( void ) {
  this->_tree = 0;
} // HashMapDec

template<typename K, typename V> /// destructor deletes all members for DEC
HashMapDec<K,V>::~HashMapDec( void ) {
  if( this->_tree != 0 ) {
    TreeController* treeC = this->_treeC;
    treeC->delDec< V >( this->_tree, this->_keySize );
  } // if tree is not empty delete it
  delete this->_treeC;
} // ~HashMapDec

/******************************************************************************/

} // namespace OBJ

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccObjHashMapDec_h__

