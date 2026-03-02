/**
 * @file hashccTypTreeController.h
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

#ifndef __hashccTypTreeController_h__
#define __hashccTypTreeController_h__

/******************************************************************************/

#include "./hashccTypTree.h"     // HASHCC::TYP::Tree
#include "./hashccTypTreeLimb.h" // HASHCC::TYP::TreeLimb
#include "./hashccTypTreeLeaf.h" // HASHCC::TYP::TreeLeaf

/******************************************************************************/

#include "./hashccFnc.h" // HASHCC::FNC::

/******************************************************************************/

#include "./hashccErr.h" // HASHCC::ERR::

/******************************************************************************/

namespace HASHCC {

namespace TYP {

/******************************************************************************/

#define _DEBUG_HASHCC_TYP_TreeController_

typedef STC::Bin Bin; // namespace typedef
typedef STC::Qud Qud; // namespace typedef
typedef STC::Oct Oct; // namespace typedef
typedef STC::Dec Dec; // namespace typedef
typedef STC::Hex Hex; // namespace typedef
typedef STC::Abc Abc; // namespace typedef

typedef ERR::Failure Failure; // namespace typedef
typedef ERR::Error   Error; // namespace typedef

class /// class as pattern for following classes
TreeController {
 public:

  TreeController( void ); /// constructor
  virtual ~TreeController( void ); /// destructor

  // /// //// BINARY TREE //// /// //
  template<typename T>
  T* storeBin( Tree*& tree, T obj, Char* key, Int16 keySize ); /// store object by key in tree

  template<typename T>
  T getBin( Tree* tree, Char* key, Int16 keySize ); /// returns an object for key or null pointer

  template<typename T>
  void delBin( Tree* tree, Int16 keySize ); /// deletes an hash tree
  // /// //// BINARY TREE //// /// //

  // /// //// DECIMAL TREE //// /// //
  template<typename T>
  T* storeDec( Tree*& tree, T obj, Char* key, Int16 keySize ); /// store object by key in tree

  template<typename T>
  T getDec( Tree* tree, Char* key, Int16 keySize ); /// returns an object for key or null pointer

  template<typename T>
  void delDec( Tree* tree, Int16 keySize ); /// deletes an hash tree
  // /// //// DECIMAL TREE //// /// //

  //template<class T>
  //void storeQud( Tree<T>* t, T* o, Char* k ); /// store object by key in tree
  //template<class T>
  //void storeOct( Tree<T>* t, T* o, Char* k ); /// store object by key in tree
  //template<class T>
  //void storeDec( Tree<T>* t, T* o, Char* k ); /// store object by key in tree
  //template<class T>
  //void storeHex( Tree<T>* t, T* o, Char* k ); /// store object by key in tree
  //template<class T>
  //void storeAbc( Tree<T>* t, T* o, Char* k ); /// store object by key in tree

 protected:

  template<typename T> T* /// function to store in hash tree
  descendStore( Tree*& tree, T inputObject, Int16 currentDepth, Int16 totalDepth, Int16 position, cuChar width );

  template<typename T> T* /// function to fetch from hash tree
  descendFetch( Tree*& tree, Int16 currentDepth, Int16 totalDepth, Int16 position );

  template<typename T> void /// function to crawl and delete tree
  descendDelete( Tree*& tree, Int16 totalDepth, cuChar width );

}; // class TreeController

/******************************************************************************/

template<typename T> T* /// function to store in hash tree
TreeController::descendStore( Tree*& tree, T inputObject, Int16 currentDepth, Int16 totalDepth, Int16 position, cuChar width ) {
  T* returnValue = 0;
  TreeLimb<T>* treeLimb = (TreeLimb<T>*)( tree );
  if( currentDepth == totalDepth - 1 ) { // last is leaf
    if( treeLimb->_t[ position ] != 0 ) { // occupied
      TreeLeaf<T>* treeLeaf = (TreeLeaf<T>*)( treeLimb->_t[ position ] );
      T previousObject = *treeLeaf->_o;
      returnValue = new T;
      *returnValue = previousObject;
      *treeLeaf->_o = inputObject;
      tree = (Tree*)( treeLeaf );
    } else { // build leaf
      TreeLeaf<T>* treeLeaf = new TreeLeaf<T>( inputObject );
      treeLimb->_t[ position ] = (Tree*)( treeLeaf );
      tree = (Tree*)( treeLeaf );
    } // if exists
  } else { // descend
    if( treeLimb->_t[ position ] != 0 ) { // occupied
      treeLimb = (TreeLimb<T>*)( treeLimb->_t[ position ] );
      tree = (Tree*)( treeLimb );
    } else { // build limb
      treeLimb->_t[ position ] = (Tree*)( new TreeLimb<T>( width ) );
      treeLimb = (TreeLimb<T>*)( treeLimb->_t[ position ] );
      tree = (Tree*)( treeLimb );
    } // if exists
  } // if leaf
  return returnValue;
} // TreeController::descendStore

template<typename T> T* /// function to fetch from hash tree
TreeController::descendFetch( Tree*& tree, Int16 currentDepth, Int16 totalDepth, Int16 position ) {
  T* returnValue = 0;
  TreeLimb<T>* treeLimb = (TreeLimb<T>*)( tree );
  if( currentDepth == totalDepth - 1 ) { // last is leaf
    if( treeLimb->_t[ position ] != 0 ) {
      TreeLeaf<T>* treeLeaf = (TreeLeaf<T>*)( treeLimb->_t[ position ] );
      returnValue = treeLeaf->_o;
      tree = (Tree*)treeLeaf;
    } else { // hash not valid
      tree = 0;
    } // if exists
  } else { // descend
    if( treeLimb->_t[ position ] != 0 ) {
      treeLimb = (TreeLimb<T>*)( treeLimb->_t[ position ] );
      tree = (Tree*)treeLimb;
    } else { // hash not valid
      tree = 0;
    } // if exists
  } // if leaf
  return returnValue;
} // TreeController::descendFetch

template<typename T> void /// function to crawl and delete tree
TreeController::descendDelete( Tree*& tree, Int16 totalDepth, cuChar width ) {
  if( totalDepth > 0 ) {
    TreeLimb<T>* treeLimb = (TreeLimb<T>*)( tree );
    for( uChar index = 0; index < width; index++ )
      if( treeLimb->_t[ index ] != 0 )
        descendDelete<T>( treeLimb->_t[ index ], totalDepth - 1, width );
    delete treeLimb;
  } else if( totalDepth == 0 ) {
    TreeLeaf<T>* treeLeaf = (TreeLeaf<T>*)( tree );
    delete treeLeaf;
  } else {
    String msg( "TreeController::descendDelete - key length is negative" );
    throw Error( msg );
  } // if key length
  tree = 0;
} // TreeController::descendDelete

/******************************************************************************/

template<typename T> T* /// store object by key in tree
TreeController::storeBin( Tree*& tree, T inputObject, Char* key, Int16 totalDepth ) {
  T* returnValue = 0;
  if( tree == 0 )
    tree = new TreeLimb<T>( Bin::size );
  Tree* rootTree = tree;
  for( Int16 currentDepth = 0; currentDepth < totalDepth; currentDepth++ ) {
    Char keyChar = key[ currentDepth ];
    if( keyChar == Bin::val[ 0 ] ) { // 0
      returnValue = descendStore( tree, inputObject, currentDepth, totalDepth, 0, Bin::size );
    } else if( keyChar == Bin::val[ 1 ] ) { // 1
      returnValue = descendStore( tree, inputObject, currentDepth, totalDepth, 1, Bin::size );
    } else {
      String msg( "TreeController::getBin - key val:" );
      msg.append( " " ).append( &keyChar ).append( " " );
      msg.append( " does not match to binary key set:" );
      String set( key );
      msg.append( " " ).append( set ).append( " " );
      throw Error( msg );
    } // if
  } // currentDepth
  tree = rootTree;
  return returnValue;
} // TreeController::storeBin

template<typename T> T /// returns an object for key or null pointer
TreeController::getBin( Tree* tree, Char* key, Int16 keySize ) {
  if( tree == 0 )
    throw Error( "TreeController::getBin - no Tree supported" );
  T* returnValue = 0;
  for( Int16 index = 0; index < keySize; index++ ) {
    Char keyChar = key[ index ];
    if( keyChar == Bin::val[ 0 ] ) { // 0
      returnValue = descendFetch<T>( tree, index, keySize, 0 );
    } else if( keyChar == Bin::val[ 1 ] ) { // 1
      returnValue = descendFetch<T>( tree, index, keySize, 1 );
    } else {
      String msg( "TreeController::getBin - key val:" );
      msg.append( " " ).append( &keyChar ).append( " " );
      msg.append( " does not match to binary key set:" );
      String set( key );
      msg.append( " " ).append( set ).append( " " );
      throw Error( msg );
    } // if
    if( tree == 0 ) {
      Char* pKeyChar = &keyChar;
      String msg( "TreeController::getBin - no object available for key:" );
      msg.append( " " ).append( key ).append( " " );
      msg.append( "at symbol: " ).append( pKeyChar ).append( " " );
      msg.append( "( tree == 0 )" ).append( " " );
      throw Failure( msg );
    } // null pointer tree
  } // index
  if( returnValue == 0 ) {
    String msg( "TreeController::getBin - no object available for key:" );
    msg.append( " " ).append( key ).append( " " );
    msg.append( "( found == 0 )" ).append( " " );
    throw Failure( msg );
  } // null pointer object
  T result = *returnValue;
  return result;
} // TreeController::getBin

template<typename T> void /// deletes an hash tree
TreeController::delBin( Tree* tree, Int16 keySize ) {
  descendDelete<T>( tree, keySize, Bin::size );
} // TreeController::delBin

/******************************************************************************/

template<typename T> T* /// store object by key in tree
TreeController::storeDec( Tree*& tree, T inputObject, Char* key, Int16 totalDepth ) {
  T* returnValue = 0;
  if( tree == 0 )
    tree = new TreeLimb<T>( Dec::size );
  Tree* rootTree = tree;
  for( Int16 currentDepth = 0; currentDepth < totalDepth; currentDepth++ ) {
    Char keyChar = key[ currentDepth ];
    if( keyChar == Dec::val[ 0 ] ) { // 0
      returnValue = descendStore( tree, inputObject, currentDepth, totalDepth, 0, Dec::size );
    } else if( keyChar == Dec::val[ 1 ] ) { // 1
      returnValue = descendStore( tree, inputObject, currentDepth, totalDepth, 1, Dec::size );
    } else if( keyChar == Dec::val[ 2 ] ) { // 2
      returnValue = descendStore( tree, inputObject, currentDepth, totalDepth, 2, Dec::size );
    } else if( keyChar == Dec::val[ 3 ] ) { // 3
      returnValue = descendStore( tree, inputObject, currentDepth, totalDepth, 3, Dec::size );
    } else if( keyChar == Dec::val[ 4 ] ) { // 4
      returnValue = descendStore( tree, inputObject, currentDepth, totalDepth, 4, Dec::size );
    } else if( keyChar == Dec::val[ 5 ] ) { // 5
      returnValue = descendStore( tree, inputObject, currentDepth, totalDepth, 5, Dec::size );
    } else if( keyChar == Dec::val[ 6 ] ) { // 6
      returnValue = descendStore( tree, inputObject, currentDepth, totalDepth, 6, Dec::size );
    } else if( keyChar == Dec::val[ 7 ] ) { // 7
      returnValue = descendStore( tree, inputObject, currentDepth, totalDepth, 7, Dec::size );
    } else if( keyChar == Dec::val[ 8 ] ) { // 8
      returnValue = descendStore( tree, inputObject, currentDepth, totalDepth, 8, Dec::size );
    } else if( keyChar == Dec::val[ 9 ] ) { // 9
      returnValue = descendStore( tree, inputObject, currentDepth, totalDepth, 9, Dec::size );
    } else {
      String msg( "TreeController::getDec - key val:" );
      msg.append( " " ).append( &keyChar ).append( " " );
      msg.append( " does not match to binary key set:" );
      String set( key );
      msg.append( " " ).append( set ).append( " " );
      throw Error( msg );
    } // if
  } // currentDepth
  tree = rootTree;
  return returnValue;
} // TreeController::storeDec

template<typename T> T /// returns an object for key or null pointer
TreeController::getDec( Tree* tree, Char* key, Int16 keySize ) {
  if( tree == 0 )
    throw Error( "TreeController::getDec - no Tree supported" );
  T* returnValue = 0;
  for( Int16 index = 0; index < keySize; index++ ) {
    Char keyChar = key[ index ];
    if( keyChar == Dec::val[ 0 ] ) { // 0
      returnValue = descendFetch<T>( tree, index, keySize, 0 );
    } else if( keyChar == Dec::val[ 1 ] ) { // 1
      returnValue = descendFetch<T>( tree, index, keySize, 1 );
    } else if( keyChar == Dec::val[ 2 ] ) { // 2
      returnValue = descendFetch<T>( tree, index, keySize, 2 );
    } else if( keyChar == Dec::val[ 3 ] ) { // 3
      returnValue = descendFetch<T>( tree, index, keySize, 3 );
    } else if( keyChar == Dec::val[ 4 ] ) { // 4
      returnValue = descendFetch<T>( tree, index, keySize, 4 );
    } else if( keyChar == Dec::val[ 5 ] ) { // 5
      returnValue = descendFetch<T>( tree, index, keySize, 5 );
    } else if( keyChar == Dec::val[ 6 ] ) { // 6
      returnValue = descendFetch<T>( tree, index, keySize, 6 );
    } else if( keyChar == Dec::val[ 7 ] ) { // 7
      returnValue = descendFetch<T>( tree, index, keySize, 7 );
    } else if( keyChar == Dec::val[ 8 ] ) { // 8
      returnValue = descendFetch<T>( tree, index, keySize, 8 );
    } else if( keyChar == Dec::val[ 9 ] ) { // 9
      returnValue = descendFetch<T>( tree, index, keySize, 9 );
    } else {
      String msg( "TreeController::getDec - key val:" );
      msg.append( " " ).append( &keyChar ).append( " " );
      msg.append( " does not match to binary key set:" );
      String set( key );
      msg.append( " " ).append( set ).append( " " );
      throw Error( msg );
    } // if
    if( tree == 0 ) {
      Char* pKeyChar = &keyChar;
      String msg( "TreeController::getDec - no object available for key:" );
      msg.append( " " ).append( key ).append( " " );
      msg.append( "at symbol: " ).append( pKeyChar ).append( " " );
      msg.append( "( tree == 0 )" ).append( " " );
      throw Failure( msg );
    } // null pointer tree
  } // index
  if( returnValue == 0 ) {
    String msg( "TreeController::getDec - no object available for key:" );
    msg.append( " " ).append( key ).append( " " );
    msg.append( "( found == 0 )" ).append( " " );
    throw Failure( msg );
  } // null pointer object
  T result = *returnValue;
  return result;
} // TreeController::getDec

template<typename T> void /// deletes an hash tree
TreeController::delDec( Tree* tree, Int16 keySize ) {
  descendDelete<T>( tree, keySize, Dec::size );
} // TreeController::delDec

/******************************************************************************/

} // namespace TYP

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccTypTreeController_h__
