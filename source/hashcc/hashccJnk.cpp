/** 
 * @file hashccJnk.cpp
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
  for( Int16 bitPosition = std::numeric_limits<uInt16>::digits - 1; bitPosition >= 0; --bitPosition) {
    if(input & (1 << bitPosition))
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
char2bit( Char character ) {
  String bitString;
  std::bitset<BITS_FOR_CHAR> bitsetValue;
  bitsetValue |= character;
  std::stringstream stream;
  stream << bitsetValue;
  stream >> bitString;
  return bitString;
}

String
int2bit( uChar value ) {
  String bitString;
  std::bitset<BITS_FOR_CHAR * sizeof(uChar)> bitsetValue;
  bitsetValue |= value;
  std::stringstream stream;
  stream << bitsetValue;
  stream >> bitString;
  return bitString;
}

String
int2bit( Int16 value ) {
  String bitString;
  std::bitset<BITS_FOR_CHAR * sizeof(Int16)> bitsetValue;
  bitsetValue |= value;
  std::stringstream stream;
  stream << bitsetValue;
  stream >> bitString;
  return bitString;
}

String
int2bit( uInt16 value ) {
  String bitString;
  std::bitset<BITS_FOR_CHAR * sizeof(uInt16)> bitsetValue;
  bitsetValue |= value;
  std::stringstream stream;
  stream << bitsetValue;
  stream >> bitString;
  return bitString;
}

String
int2bit( Int32 value ) {
  String bitString;
  std::bitset<BITS_FOR_CHAR * sizeof(Int32)> bitsetValue;
  bitsetValue |= value;
  std::stringstream stream;
  stream << bitsetValue;
  stream >> bitString;
  return bitString;
}

String
int2bit( uInt32 value ) {
  String bitString;
  std::bitset<BITS_FOR_CHAR * sizeof(uInt32)> bitsetValue;
  bitsetValue |= value;
  std::stringstream stream;
  stream << bitsetValue;
  stream >> bitString;
  return bitString;
}

String
int2bit( Int64 value ) {
  String bitString;
  std::bitset<BITS_FOR_CHAR * sizeof(Int64)> bitsetValue;
  bitsetValue |= (unsigned long)value;
  std::stringstream stream;
  stream << bitsetValue;
  stream >> bitString;
  return bitString;
}

String
int2bit( uInt64 value ) {
  String bitString;
  std::bitset<BITS_FOR_CHAR * sizeof(uInt64)> bitsetValue;
  bitsetValue |= (unsigned long)value;
  std::stringstream stream;
  stream << bitsetValue;
  stream >> bitString;
  return bitString;
}

String
dec2hex2( Int16 decimalValue ) {
  String hexString;
  const char* hexChars = "0123456789ABCDEF";
  for( int bitPosition = 2 * sizeof( int ) - 1; bitPosition >= 0; bitPosition-- ) {
    char digit = hexChars[ ( ( decimalValue >> bitPosition * 4 ) & 0xF ) ];
    hexString.append( 1, digit );
  }
  return hexString;
} // dec2hex2

/******************************************************************************/

} // namespace JNK

} // namespace HASHCC

/******************************************************************************/
