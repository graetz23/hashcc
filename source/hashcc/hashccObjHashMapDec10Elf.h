/**
 * @file hashccObjHashMapDec10Elf.h
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

#ifndef __hashccObjHashMapDec10Elf_h__
#define __hashccObjHashMapDec10Elf_h__

/******************************************************************************/

#include "./hashccObjHashMapDec24.h" // HASHCC::OBJ::HashMapDec<T>

/******************************************************************************/

namespace HASHCC {

namespace OBJ {

/******************************************************************************/

#define _DEBUG_HASHCC_OBJ_HashMapDec10Elf_

/******************************************************************************/

/// class as pattern for following classes
template<typename K, typename V> class
HashMapDec10Elf : public HashMapDec24<K,V> {
 public:

  HashMapDec10Elf( void ); /// constructor
  virtual ~HashMapDec10Elf( void ); /// destructor

  V get( K key ); /// returns a stored object

  V* put( K key, V value ); /// stores an object by key;
                            /// returns an object pointer if key is occupied
 protected:

}; // class HashMapDec10Elf

/******************************************************************************/

/// constructor
template<typename K, typename V>
HashMapDec10Elf<K,V>::HashMapDec10Elf( void ) {
} // HashMapDec10Elf

/// destructor
template<typename K, typename V>
HashMapDec10Elf<K,V>::~HashMapDec10Elf( void ) {
} // ~HashMapDec10Elf

/******************************************************************************/

template<typename K, typename V> V /// returns a stored object
HashMapDec10Elf<K,V>::get( K key ) {

  String strKey = TYP::keyConv<K>( key );

  String strHash = FNC::elf10_32( strKey );
  Char* charHash = (Char*)strHash.c_str( );

  // Tree* tree = this->_tree; // GNU/g++ work around ~8>
  TreeController* treeC = this->_treeC; // GNU/g++ work around ~8>
  V value = treeC->getDec<V>( this->_tree, charHash, this->_keySize );
  // this->_tree = tree; // GNU/g++ work around ~8>

  return value;

} // HashMapDec10Elf<T>::get

template<typename K, typename V> V* /// stores an object
HashMapDec10Elf<K,V>::put( K key, V value ) {

  String strKey = TYP::keyConv<K>( key );

  String strHash = FNC::elf10_32( strKey );
  Char* charHash = (Char*)strHash.c_str( );

  // Tree* tree = this->_tree; // GNU/g++ work around ~8>
  TreeController* treeC = this->_treeC; // GNU/g++ work around ~8>
  V* pValue = treeC->storeDec<V>( this->_tree, value, charHash, this->_keySize );
  // this->_tree = tree; // GNU/g++ work around ~8>

  if( pValue != 0 ) {
    String msg( "HashMapDec10Elf::put - hash map is for key: \"" );
    msg.append( strKey );
    msg.append( "\" already occupied!" );
    throw ERR::Failure(  );
  }
  this->_noOfVal++;

  return pValue; // is null pointer if hash is not occupied

} // HashMapDec10Elf<T>::put

/******************************************************************************/

} // namespace OBJ

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccObjHashMapDec10Elf_h__
