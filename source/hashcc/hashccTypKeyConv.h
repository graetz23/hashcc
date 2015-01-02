/** 
 * @file hashccTypKeyConv.h
 * @author Christian Scheiblich
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2009-2015 Christian Scheiblich (cscheiblich@gmail.com)
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

#ifndef __hashccTypKeyConv_h__
#define __hashccTypKeyConv_h__

/******************************************************************************/
/**
 * Predefined templates for key conversion.
 *
 * If predefined are not available for a given input key, the template function
 * in this header is called, which always throws an exception to mark that the
 * key is not vaild for hashing. Otherwise the input type of the key is
 * converted to a std::string type.
 *
 */
/******************************************************************************/

#include "./hashccTypes.h" // HASHCC data types

/******************************************************************************/

#include "./hashccErr.h" // HASHCC::ERR::

/******************************************************************************/

namespace HASHCC {

namespace TYP {

/******************************************************************************/

#define _VERSION_HASHCC_TYP_KeyConv_ 0.15 // 20141231
#define _DEBUG_HASHCC_TYP_KeyConv_

/******************************************************************************/

// template function
template<typename K> String keyConv( K key ); // throws Error if type unkown

// specialization to used types
template< > String keyConv< Char   >( Char   key ); // character key to String
template< > String keyConv< Char*  >( Char*  key ); // charakters key to String
template< > String keyConv< String >( String key ); // string key to String
template< > String keyConv< Int16  >( Int16  key ); // Int16 key to String
template< > String keyConv< Int32  >( Int32  key ); // Int32 key to String
template< > String keyConv< Int64  >( Int64  key ); // Int64 key to String
template< > String keyConv< uInt16 >( uInt16 key ); // uInt16 key to String
template< > String keyConv< uInt32 >( uInt32 key ); // uInt32 key to String
template< > String keyConv< uInt64 >( uInt64 key ); // uInt64 key to String

/******************************************************************************/

template< typename K > String // throws Error if type of key is unkown
keyConv( K key ) {
  throw ERR::Error( "HASHCC::TYP::keyConv - data type of key not available" );
} // keyConv

/******************************************************************************/

} // namespace TYP

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccTypKeyConv_h__
