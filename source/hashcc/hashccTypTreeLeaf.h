/** 
 * @file hashccTypTreeLeaf.h
 * @author Christian Scheiblich
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2009-2017 Christian Scheiblich (cscheiblich@gmail.com)
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

#ifndef __hashccTypTreeLeaf_h__
#define __hashccTypTreeLeaf_h__

/******************************************************************************/

#include "./hashccTypTree.h" // HASHCC::TYPE::Tree

/******************************************************************************/

namespace HASHCC {

namespace TYP {

/******************************************************************************/

#define _VERSION_HASHCC_TYP_Tree_ 0.15 // 20141231
#define _DEBUG_HASHCC_TYP_Tree_

/******************************************************************************/

template<class T> struct /// multidimensional tree structure - a leaf
TreeLeaf : public Tree {
 public:

  TreeLeaf( void ); /// constructor
  TreeLeaf( T o ); /// constructor
  ~TreeLeaf( void ); /// destructor

  T* _o; /// glued object - by a pointer - to a tree lead

}; // struct Tree

/******************************************************************************/
  
template<class T> /// constructor
TreeLeaf<T>::TreeLeaf( void ) {
  _o = 0;
} // Tree

template<class T> /// constructor
TreeLeaf<T>::TreeLeaf( T o ) {
  _o = new T;
  *_o = o;
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
