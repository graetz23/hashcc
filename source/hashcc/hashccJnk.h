/** 
 * @file hashccJnk.h
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

#ifndef __hashccJnk_h__
#define __hashccJnk_h__

/******************************************************************************/

#include "./hashccTypes.h" // used typedefs in HASHCC::

/******************************************************************************/
/**
 *
 * HASHCC::JNK - Junkyard for out sourced source code ~8>
 *
 */
/******************************************************************************/

namespace HASHCC {

namespace JNK {

/******************************************************************************/

#define _VERSION_HASHCC_JNK_ 0.15 // 20141231
#define _DEBUG_HASHCC_JNK_

/******************************************************************************/

typedef HASHCC::Char       Char; // stc namespace typedef
typedef HASHCC::uChar     uChar; // stc namespace typedef
typedef HASHCC::cChar     cChar; // stc namespace typedef
typedef HASHCC::cuChar   cuChar; // stc namespace typedef
typedef HASHCC::String   String; // stc namespace typedef

/******************************************************************************/

String cvt_binary( uInt16 input );

/******************************************************************************/

String int2str(  Int16 dec ); // convert DEC to String
String int2str(  Int32 dec ); // convert DEC to String
String int2str(  Int64 dec ); // convert DEC to String
String dec2hex(  Int16 dec ); // convert DEC to HEX
String char2bit( Char ch );
String int2bit(  Int16 a );
String int2bit(  uInt16 a );
String int2bit(  Int32 a );
String int2bit(  uInt32 a );
String int2bit(  Int64 a );
String int2bit(  uInt64 a );

/******************************************************************************/

template<typename T> String
xxx_to_bin( const T& value ) {

  const std::bitset< std::numeric_limits<T>::digits + 1 > bs( value );

  const String s( bs.to_string( ) );

  const String::size_type pos( s.find_first_not_of( '0' ) );

  return pos == String::npos ? "0" : s.substr( pos );
  
} // xxx_to_bin

template< typename T >
inline T highbit( T& t ) {
  return t = ( ( ( T )( -1 ) ) >> 1 ) + 1;
}

template < typename T >
String bin( T& value ) {
  std::stringstream b;
  T bit = highbit( bit );
  for( bit; bit; bit >>= 1 )
    b << ( ( value & bit ) ? '1' : '0' );
  String s;
  b >> s;
  return s;
} // bin

/******************************************************************************/

} // namespace JNK

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccJnk_h__
