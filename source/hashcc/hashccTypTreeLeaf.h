/**
 * @file hashccTypTreeLeaf.h
 * @brief Tree leaf node template for storing objects
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
 * @class HASHCC::TYP::TreeLeaf
 * @brief Leaf node template for storing objects in the tree.
 * @ingroup TYP
 *
 * TreeLeaf is a terminal node that stores an actual object (value)
 * at the end of a hash path.
 */

#ifndef __hashccTypTreeLeaf_h__
#define __hashccTypTreeLeaf_h__

/******************************************************************************/

#include "./hashccTypTree.h" // HASHCC::TYPE::Tree

/******************************************************************************/

namespace HASHCC {

namespace TYP {

/******************************************************************************/

#define _DEBUG_HASHCC_TYP_Tree_

/******************************************************************************/

/**
 * @struct HASHCC::TYP::TreeLeaf
 * @brief Leaf node template for storing objects.
 * @ingroup TYP
 *
 * @tparam T The type of object to store
 */
template<class T> struct TreeLeaf : public Tree {
 public:

  /** @brief Default constructor */
  TreeLeaf( void );
  /** @brief Construct with object */
  TreeLeaf( T object );
  /** @brief Destructor */
  ~TreeLeaf( void );

  /** @brief Pointer to the stored object */
  T* _o;

}; // struct Tree

/******************************************************************************/

template<class T> /// constructor
TreeLeaf<T>::TreeLeaf( void ) {
  _o = 0;
} // Tree

template<class T> /// constructor
TreeLeaf<T>::TreeLeaf( T object ) {
  _o = new T;
  *_o = object;
} // Tree

template<class T> /// destructor
TreeLeaf<T>::~TreeLeaf( void ) {
  if( _o != 0 )
    delete _o;
} // ~Tree

/******************************************************************************/

} // namespace TYP

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccTypTreeLeaf_h__
