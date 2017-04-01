/** 
 * @file hashccTypTreeController.h
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

#define _VERSION_HASHCC_TYP_TreeController_ 0.15 // 20141231
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
  descendStore( Tree*& t, T o, Int16 s, Int16 d, Int16 p, cuChar w );

  template<typename T> T* /// function to fetch from hash tree
  descendFetch( Tree*& t, Int16 s, Int16 d, Int16 p );

  template<typename T> void /// function to crawl and delete tree
  descendDelete( Tree*& t, Int16 d, cuChar w );

}; // class TreeController

/******************************************************************************/

template<typename T> T* /// function to store in hash tree
TreeController::descendStore( Tree*& t, T o, Int16 s, Int16 d, Int16 p, cuChar w ) {
  T* f = 0;
  TreeLimb<T>* l = (TreeLimb<T>*)( t );
  if( s == d - 1 ) { // last is leaf
    if( l->_t[ p ] != 0 ) { // occupied
      TreeLeaf<T>* L = (TreeLeaf<T>*)( l->_t[ p ] );
      T O = *L->_o;
      f = new T;
      *f = O;
      *L->_o = o;
      t = (Tree*)( L );
    } else { // build leaf
      TreeLeaf<T>* L = new TreeLeaf<T>( o );
      l->_t[ p ] = (Tree*)( L );
      t = (Tree*)( L );
    } // if exists
  } else { // descend
    if( l->_t[ p ] != 0 ) { // occupied
      l = (TreeLimb<T>*)( l->_t[ p ] );
      t = (Tree*)( l );
    } else { // build limb
      l->_t[ p ] = (Tree*)( new TreeLimb<T>( w ) );
      l = (TreeLimb<T>*)( l->_t[ p ] );
      t = (Tree*)( l );
    } // if exists
  } // if leaf
  return f;
} // TreeController::descendStore

template<typename T> T* /// function to fetch from hash tree
TreeController::descendFetch( Tree*& t, Int16 s, Int16 d, Int16 p ) {
  T* f = 0;
  TreeLimb<T>* l = (TreeLimb<T>*)( t );
  if( s == d - 1 ) { // last is leaf
    if( l->_t[ p ] != 0 ) {
      TreeLeaf<T>* L = (TreeLeaf<T>*)( l->_t[ p ] );
      f = L->_o;
      t = (Tree*)L;
    } else { // hash not valid
      t = 0;
    } // if exists
  } else { // descend
    if( l->_t[ p ] != 0 ) {
      l = (TreeLimb<T>*)( l->_t[ p ] );
      t = (Tree*)l;
    } else { // hash not valid
      t = 0; 
    } // if exists
  } // if leaf
  return f;
} // TreeController::descendFetch

template<typename T> void /// function to crawl and delete tree
TreeController::descendDelete( Tree*& t, Int16 d, cuChar w ) {
  if( d > 0 ) {
    TreeLimb<T>* l = (TreeLimb<T>*)( t );
    for( uChar r = 0; r < w; r++ )
      if( l->_t[ r ] != 0 )
        descendDelete<T>( l->_t[ r ], d - 1, w );
    delete l;
  } else if( d == 0 ) {
    TreeLeaf<T>* L = (TreeLeaf<T>*)( t );
    delete L;
  } else {
    String msg( "TreeController::descendDelete - key length is negative" );
    throw Error( msg );
  } // if key length
  t = 0;
} // TreeController::descendDelete

/******************************************************************************/

template<typename T> T* /// store object by key in tree
TreeController::storeBin( Tree*& t, T o, Char* k, Int16 d ) {
  T* f = 0;
  if( t == 0 )
    t = new TreeLimb<T>( Bin::size );
  Tree* r = t;
  for( Int16 s = 0; s < d; s++ ) {
    Char c = k[ s ];
    if( c == Bin::val[ 0 ] ) { // 0
      f = descendStore( t, o, s, d, 0, Bin::size );
    } else if( c == Bin::val[ 1 ] ) { // 1
      f = descendStore( t, o, s, d, 1, Bin::size );
    } else {
      String msg( "TreeController::getBin - key val:" );
      msg.append( " " ).append( &c ).append( " " );
      msg.append( " does not match to binary key set:" );
      String set( k );
      msg.append( " " ).append( set ).append( " " );
      throw Error( msg );
    } // if
  } // s
  t = r;
  return f;
} // TreeController::storeBin

template<typename T> T /// returns an object for key or null pointer
TreeController::getBin( Tree* t, Char* k, Int16 kSize ) {
  if( t == 0 )
    throw Error( "TreeController::getBin - no Tree supported" );
  T* f = 0;
  for( Int16 i = 0; i < kSize; i++ ) {
    Char c = k[ i ];
    if( c == Bin::val[ 0 ] ) { // 0
      f = descendFetch<T>( t, i, kSize, 0 );
    } else if( c == Bin::val[ 1 ] ) { // 1
      f = descendFetch<T>( t, i, kSize, 1 );
    } else {
      String msg( "TreeController::getBin - key val:" );
      msg.append( " " ).append( &c ).append( " " );
      msg.append( " does not match to binary key set:" );
      String set( k );
      msg.append( " " ).append( set ).append( " " );
      throw Error( msg );
    } // if
    if( t == 0 ) {
      Char* pC = &c;
      String msg( "TreeController::getBin - no object available for key:" );
      msg.append( " " ).append( k ).append( " " );
      msg.append( "at symbol: " ).append( pC ).append( " " );
      msg.append( "( tree == 0 )" ).append( " " );
      throw Failure( msg );
    } // null pointer tree
  } // i
  if( f == 0 ) {
    String msg( "TreeController::getBin - no object available for key:" );
    msg.append( " " ).append( k ).append( " " );
    msg.append( "( found == 0 )" ).append( " " );
    throw Failure( msg );
  } // null pointer object
  T o = *f;
  return o;
} // TreeController::getBin

template<typename T> void /// deletes an hash tree
TreeController::delBin( Tree* t, Int16 kSize ) {
  descendDelete<T>( t, kSize, Bin::size );
} // TreeController::delBin

/******************************************************************************/

template<typename T> T* /// store object by key in tree
TreeController::storeDec( Tree*& t, T o, Char* k, Int16 d ) {
  T* f = 0;
  if( t == 0 )
    t = new TreeLimb<T>( Dec::size );
  Tree* r = t;
  for( Int16 s = 0; s < d; s++ ) {
    Char c = k[ s ];
    if( c == Dec::val[ 0 ] ) { // 0
      f = descendStore( t, o, s, d, 0, Dec::size );
    } else if( c == Dec::val[ 1 ] ) { // 1
      f = descendStore( t, o, s, d, 1, Dec::size );
    } else if( c == Dec::val[ 2 ] ) { // 2
      f = descendStore( t, o, s, d, 2, Dec::size );
    } else if( c == Dec::val[ 3 ] ) { // 3
      f = descendStore( t, o, s, d, 3, Dec::size );
    } else if( c == Dec::val[ 4 ] ) { // 4
      f = descendStore( t, o, s, d, 4, Dec::size );
    } else if( c == Dec::val[ 5 ] ) { // 5
      f = descendStore( t, o, s, d, 5, Dec::size );
    } else if( c == Dec::val[ 6 ] ) { // 6
      f = descendStore( t, o, s, d, 6, Dec::size );
    } else if( c == Dec::val[ 7 ] ) { // 7
      f = descendStore( t, o, s, d, 7, Dec::size );
    } else if( c == Dec::val[ 8 ] ) { // 8
      f = descendStore( t, o, s, d, 8, Dec::size );
    } else if( c == Dec::val[ 9 ] ) { // 9
      f = descendStore( t, o, s, d, 9, Dec::size );
    } else {
      String msg( "TreeController::getDec - key val:" );
      msg.append( " " ).append( &c ).append( " " );
      msg.append( " does not match to binary key set:" );
      String set( k );
      msg.append( " " ).append( set ).append( " " );
      throw Error( msg );
    } // if
  } // s
  t = r;
  return f;
} // TreeController::storeDec

template<typename T> T /// returns an object for key or null pointer
TreeController::getDec( Tree* t, Char* k, Int16 kSize ) {
  if( t == 0 )
    throw Error( "TreeController::getDec - no Tree supported" );
  T* f = 0;
  for( Int16 i = 0; i < kSize; i++ ) {
    Char c = k[ i ];
    if( c == Dec::val[ 0 ] ) { // 0
      f = descendFetch<T>( t, i, kSize, 0 );
    } else if( c == Dec::val[ 1 ] ) { // 1
      f = descendFetch<T>( t, i, kSize, 1 );
    } else if( c == Dec::val[ 2 ] ) { // 2
      f = descendFetch<T>( t, i, kSize, 2 );
    } else if( c == Dec::val[ 3 ] ) { // 3
      f = descendFetch<T>( t, i, kSize, 3 );
    } else if( c == Dec::val[ 4 ] ) { // 4
      f = descendFetch<T>( t, i, kSize, 4 );
    } else if( c == Dec::val[ 5 ] ) { // 5
      f = descendFetch<T>( t, i, kSize, 5 );
    } else if( c == Dec::val[ 6 ] ) { // 6
      f = descendFetch<T>( t, i, kSize, 6 );
    } else if( c == Dec::val[ 7 ] ) { // 7
      f = descendFetch<T>( t, i, kSize, 7 );
    } else if( c == Dec::val[ 8 ] ) { // 8
      f = descendFetch<T>( t, i, kSize, 8 );
    } else if( c == Dec::val[ 9 ] ) { // 9
      f = descendFetch<T>( t, i, kSize, 9 );
    } else {
      String msg( "TreeController::getDec - key val:" );
      msg.append( " " ).append( &c ).append( " " );
      msg.append( " does not match to binary key set:" );
      String set( k );
      msg.append( " " ).append( set ).append( " " );
      throw Error( msg );
    } // if
    if( t == 0 ) {
      Char* pC = &c;
      String msg( "TreeController::getDec - no object available for key:" );
      msg.append( " " ).append( k ).append( " " );
      msg.append( "at symbol: " ).append( pC ).append( " " );
      msg.append( "( tree == 0 )" ).append( " " );
      throw Failure( msg );
    } // null pointer tree
  } // i
  if( f == 0 ) {
    String msg( "TreeController::getDec - no object available for key:" );
    msg.append( " " ).append( k ).append( " " );
    msg.append( "( found == 0 )" ).append( " " );
    throw Failure( msg );
  } // null pointer object
  T o = *f;
  return o;
} // TreeController::getDec

template<typename T> void /// deletes an hash tree
TreeController::delDec( Tree* t, Int16 kSize ) {
  descendDelete<T>( t, kSize, Dec::size );
} // TreeController::delDec

/******************************************************************************/

} // namespace TYP

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccTypTreeController_h__
