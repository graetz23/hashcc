/**
 * @file hashccObjHashMap.h
 * @brief Base hash map class template
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
 * @class HASHCC::OBJ::HashMap
 * @brief Base hash map class template.
 * @ingroup OBJ
 *
 * @tparam K The key type
 * @tparam V The value type
 *
 * Provides the base interface for hash map implementations.
 */

#ifndef __hashccObjHashMap_h__
#define __hashccObjHashMap_h__

/******************************************************************************/

#include "./hashccTyp.h" // HASHCC data types

/******************************************************************************/

namespace HASHCC {

namespace OBJ {

/******************************************************************************/

#define _DEBUG_HASHCC_OBJ_HashMap_

/******************************************************************************/

typedef HASHCC::TYP::Tree           Tree;           // namespace typedef
typedef HASHCC::TYP::TreeController TreeController; // namespace typedef

/******************************************************************************/

/**
 * @class HASHCC::OBJ::HashMap
 * @brief Base hash map class template.
 * @ingroup OBJ
 *
 * @tparam K The key type
 * @tparam V The value type
 */
template<typename K, typename V>
class HashMap {
 public:

  /** @brief Default constructor */
  HashMap( void );
  /** @brief Destructor */
  virtual ~HashMap( void );

  /** @brief Returns the number of stored objects */
  Int32 size( void );

  /** @brief Returns a stored object for the given key */
  virtual V get( K key ) = 0;

  /** @brief Stores an object by key; returns pointer if key exists */
  virtual V* put( K key, V value ) = 0;

 protected:

  /** @brief Number of stored objects */
  Int32  _numberOfValues;
  /** @brief The key size */
  uInt16 _keySize;
  /** @brief The tree structure */
  Tree*  _tree;
  /** @brief The tree controller */
  TreeController* _treeController;

}; // class HashMap

/******************************************************************************/

template<typename K, typename V> /// constructor
HashMap< K, V >::HashMap( void ) {
  TYP::keyTest<K>( ); // throws ERR::Error if key data type is not available
  this->_numberOfValues = 0; // set number of stored data objects to zero
  this->_treeController = new TreeController( ); // create a the tree controller
} // HashMap

template<typename K, typename V> /// destructor
HashMap< K, V >::~HashMap( void ) {
  // member _treeC is deleted in heritating destructor
} // ~HashMap

/******************************************************************************/

template<typename K, typename V>
Int32 /// returns the no of stored objects
HashMap< K, V >::size( void ) {
  return this->_numberOfValues;
} // HashMap<T>::size

/******************************************************************************/

} // namespace OBJ

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccObjHashMap_h__
