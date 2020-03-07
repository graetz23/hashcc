/** 
 * @file hashccTypKeyTest.h
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

#ifndef __hashccTypKeyTest_h__
#define __hashccTypKeyTest_h__

/******************************************************************************/
/**
 * Tests the data type of the key to be valid.
 *
 * Predefined empty template function for a set data type are called for the
 * input type of the key. If the type is valid the template function does
 * nothing. Otherwise the common template function in the header is called
 * which throws an exception to mark, that the key is not valid for hashing.
 */
/******************************************************************************/

#include "./hashccTypes.h" // HASHCC data types

/******************************************************************************/

#include "./hashccErr.h" // HASHCC::ERR::

/******************************************************************************/

namespace HASHCC {

namespace TYP {

/******************************************************************************/

#define _VERSION_HASHCC_TYP_KeyTest_ 0.15 // 20141231
#define _DEBUG_HASHCC_TYP_KeyTest_

/******************************************************************************/

  // template function
template<typename K> void keyTest( void ); // throws Error if type unkown

template<typename K> void keyTest( String f ); // throws Error if type unkown

// specialization to used types
template< > void keyTest< Char   >( void ); // character key to String
template< > void keyTest< Char*  >( void ); // charakters key to String
template< > void keyTest< String >( void ); // string key to String
template< > void keyTest< Int16  >( void ); // Int16 key to String
template< > void keyTest< Int32  >( void ); // Int32 key to String
template< > void keyTest< Int64  >( void ); // Int64 key to String
template< > void keyTest< uInt16 >( void ); // uInt16 key to String
template< > void keyTest< uInt32 >( void ); // uInt32 key to String
template< > void keyTest< uInt64 >( void ); // uInt64 key to String
template< > void keyTest< Char   >( String f ); // character key to String
template< > void keyTest< Char*  >( String f ); // charakters key to String
template< > void keyTest< String >( String f ); // string key to String
template< > void keyTest< Int16  >( String f ); // Int16 key to String
template< > void keyTest< Int32  >( String f ); // Int32 key to String
template< > void keyTest< Int64  >( String f ); // Int64 key to String
template< > void keyTest< uInt16 >( String f ); // uInt16 key to String
template< > void keyTest< uInt32 >( String f ); // uInt32 key to String
template< > void keyTest< uInt64 >( String f ); // uInt64 key to String

/******************************************************************************/

template< typename K > void /// throws Error if type unkown
keyTest( void ) {
  throw ERR::Error( "HASHCC::TYP::keyTest - key data type of not valid" );
} // keyTest

template< typename K > void /// throws Error if type unkown
keyTest( String f ) {
  throw ERR::Error( f.append( " - TYP::keyTest - key data type not valid" ) );
} // keyTest

/******************************************************************************/

} // namespace TYP

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccTypKey_h__
