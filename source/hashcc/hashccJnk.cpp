/** 
 * @file hashccJnk.cpp
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

#include "./hashccJnk.h" // header

/******************************************************************************/

namespace HASHCC {

namespace JNK {

/******************************************************************************/
  
String 
cvt_binary( uInt16 input ) {
  if( input == 0 )
    return "0"; // trivial case
  String result;
  for( Int16 i = std::numeric_limits<uInt16>::digits - 1; i >= 0; --i) {
    if(input & (1 << i))
      result += "1";
    else
      if( !result.empty( ) ) 
        result += "0";
  }
  return result;
} // cvt_binary

/******************************************************************************/

#define BITS_FOR_CHAR 8

String
char2bit( Char c ) {
  String s;
  std::bitset<BITS_FOR_CHAR> byte;
  byte |= c;
  std::stringstream b;
  b << byte;
  b >> s;
  return s;
}

String
int2bit( uChar c ) {
  String s;
  std::bitset<BITS_FOR_CHAR * sizeof(uChar)> byte;
  byte |= c;
  std::stringstream b;
  b << byte;
  b >> s;
  return s;
}

String
int2bit( Int16 a ) {
  String s;
  std::bitset<BITS_FOR_CHAR * sizeof(Int16)> byte;
  byte |= a;
  std::stringstream b;
  b << byte;
  b >> s;
  return s;
}

String
int2bit( uInt16 a ) {
  String s;
  std::bitset<BITS_FOR_CHAR * sizeof(uInt16)> byte;
  byte |= a;
  std::stringstream b;
  b << byte;
  b >> s;
  return s;
}

String
int2bit( Int32 a ) {
  String s;
  std::bitset<BITS_FOR_CHAR * sizeof(Int32)> byte;
  byte |= a;
  std::stringstream b;
  b << byte;
  b >> s;
  return s;
}

String
int2bit( uInt32 a ) {
  String s;
  std::bitset<BITS_FOR_CHAR * sizeof(uInt32)> byte;
  byte |= a;
  std::stringstream b;
  b << byte;
  b >> s;
  return s;
}

String
int2bit( Int64 a ) {
  String s;
  std::bitset<BITS_FOR_CHAR * sizeof(Int64)> byte;
  byte |= (unsigned long)a;
  std::stringstream b;
  b << byte;
  b >> s;
  return s;
}

String
int2bit( uInt64 a ) {
  String s;
  std::bitset<BITS_FOR_CHAR * sizeof(uInt64)> byte;
  byte |= (unsigned long)a;
  std::stringstream b;
  b << byte;
  b >> s;
  return s;
}

String
dec2hex2( Int16 dec ) {
  String hex;
  for( int i = 2 * sizeof( int ) - 1; i >= 0; i-- )
    hex.append( (Char*)("0123456789ABCDEF"[ ( ( dec >> i * 4 ) & 0xF ) ]) );
  return hex;
} // dec2hex2

/******************************************************************************/

} // namespace JNK

} // namespace HASHCC

/******************************************************************************/
