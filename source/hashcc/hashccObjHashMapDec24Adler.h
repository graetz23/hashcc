/** 
 * @file hashccObjHashMapDec24Adler.h
 * @author Christian Scheiblich
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2009-2016 Christian Scheiblich (cscheiblich@gmail.com)
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

#ifndef __hashccObjHashMapDec24Adler_h__
#define __hashccObjHashMapDec24Adler_h__

/******************************************************************************/

#include "./hashccObjHashMapDec24.h" // HASHCC::OBJ::HashMapDec<T>

/******************************************************************************/

namespace HASHCC {

namespace OBJ {

/******************************************************************************/

#define _VERSION_HASHCC_OBJ_HashMapDec24Adler_ 0.15 // 20141231
#define _DEBUG_HASHCC_OBJ_HashMapDec24Adler_

/******************************************************************************/

/// class as pattern for following classes
template<typename K, typename V> class 
HashMapDec24Adler : public HashMapDec24<K,V> {
 public:

  HashMapDec24Adler( void ); /// constructor
  virtual ~HashMapDec24Adler( void ); /// destructor

  V get( K key ); /// returns a stored object

  V* put( K key, V value ); /// stores an object by key; 
                            /// returns an object pointer if key is occupied
 protected:

}; // class HashMapDec24Adler

/******************************************************************************/
  
/// constructor
template<typename K, typename V>
HashMapDec24Adler<K,V>::HashMapDec24Adler( void ) {
} // HashMapDec24Adler

/// destructor
template<typename K, typename V>
HashMapDec24Adler<K,V>::~HashMapDec24Adler( void ) {
} // ~HashMapDec24Adler

/******************************************************************************/

template<typename K, typename V> V /// returns a stored object
HashMapDec24Adler<K,V>::get( K key ) {

  String strKey = TYP::keyConv<K>( key );

  String strHash = FNC::adler24_16( strKey );
  Char* charHash = (Char*)strHash.c_str( );

  // Tree* tree = this->_tree; // GNU/g++ work around ~8>
  TreeController* treeC = this->_treeC; // GNU/g++ work around ~8>
  V value = treeC->getDec<V>( this->_tree, charHash, this->_keySize );
  // this->_tree = tree; // GNU/g++ work around ~8>

  return value;

} // HashMapDec24Adler<T>::get

template<typename K, typename V> V* /// stores an object
HashMapDec24Adler<K,V>::put( K key, V value ) { 

  String strKey = TYP::keyConv<K>( key );

  String strHash = FNC::adler24_16( strKey );
  Char* charHash = (Char*)strHash.c_str( );

  // Tree* tree = this->_tree; // GNU/g++ work around ~8>
  TreeController* treeC = this->_treeC; // GNU/g++ work around ~8>
  V* pValue = treeC->storeDec<V>( this->_tree, value, charHash, this->_keySize );
  // this->_tree = tree; // GNU/g++ work around ~8>

  if( pValue != 0 ) {
    String msg( "HashMapDec24Adler::put - hash map is for key: \"" );
    msg.append( strKey );
    msg.append( "\" already occupied!" );
    throw ERR::Failure(  );
  } 
  this->_noOfVal++;

  return pValue; // is null pointer if hash is not occupied

} // HashMapDec24Adler<T>::put
               
/******************************************************************************/

} // namespace OBJ

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccObjHashMapDec24Adler_h__
