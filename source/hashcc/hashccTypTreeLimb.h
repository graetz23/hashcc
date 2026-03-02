/**
 * @file hashccTypTreeLimb.h
 * @brief Tree limb/branch node template for tree structure
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
 * @class HASHCC::TYP::TreeLimb
 * @brief Branch node template for the tree structure.
 * @ingroup TYP
 *
 * TreeLimb is an intermediate node that contains child nodes,
 * representing a digit position in the hash.
 *
 * @tparam T The type of objects stored in leaf nodes
 */

#ifndef __hashccTypTreeLimb_h__
#define __hashccTypTreeLimb_h__

/******************************************************************************/

#include "./hashccTypTree.h" // HASHCC::TYP::Tree

/******************************************************************************/

namespace HASHCC {

namespace TYP {

/******************************************************************************/

#define _DEBUG_HASHCC_TYP_Tree_

/******************************************************************************/

/**
 * @struct HASHCC::TYP::TreeLimb
 * @brief Branch node template for tree structure.
 * @ingroup TYP
 *
 * @tparam T The type of objects stored in leaf nodes
 */
template<class T> struct TreeLimb : public Tree {
 public:

  /** @brief Default constructor */
  TreeLimb( void );
  /** @brief Construct with number of child trees */
  TreeLimb( cuChar numberOfTrees );
  /** @brief Destructor */
  ~TreeLimb( void );

  /** @brief Array of child tree pointers */
  Tree** _t;

}; // struct Tree

/******************************************************************************/

template<class T> /// constructor
TreeLimb<T>::TreeLimb( void ) {
  _t = 0;
} // Tree

template<class T> /// constructor
TreeLimb<T>::TreeLimb( cuChar numberOfTrees ) {
  _t = new Tree*[ numberOfTrees ];
  for( uChar index = 0; index < numberOfTrees; index++ )
    _t[ index ] = 0;
} // Tree

template<class T> /// destructor
TreeLimb<T>::~TreeLimb( void ) {
  delete [ ] _t;
} // ~Tree

/******************************************************************************/

} // namespace TYP

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccTypTreeLimb_h__
