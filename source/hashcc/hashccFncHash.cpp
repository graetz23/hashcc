/** 
 * @file hashccFncHash.cpp
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

#include "./hashccFncHash.h" // header

/******************************************************************************/

namespace HASHCC {

namespace FNC {

/******************************************************************************/

String // returns a hash of 10 decimal symbols
elf10_32( String key ) {
  String hashString;
  std::stringstream stringStream;
  uInt32 integerHash = hashAdler32( (Char*)key.c_str( ), (uInt16)key.length( ) );
  stringStream << integerHash;
  stringStream >> hashString;
  String paddedHashString = blowZero( hashString, 10 );
  return paddedHashString;
} // elf10_16

String
adler24_16( String key ) {
  String hashString;
  std::stringstream stringStream;
  uInt16 integerHash = hashAdler16( (Char*)key.c_str( ), (uInt16)key.length( ) );
  stringStream << integerHash;
  stringStream >> hashString;
  String paddedHashString = blowZero( hashString, 24 );
  return paddedHashString;
} // adler24

String
adler24_32( String key ) {
  String hashString;
  std::stringstream stringStream;
  uInt32 integerHash = hashAdler32( (Char*)key.c_str( ), (uInt16)key.length( ) );
  stringStream << integerHash;
  stringStream >> hashString;
  String paddedHashString = blowZero( hashString, 24 );
  return paddedHashString;
} // adler24

String
adler24_64( String key ) {
  String hashString;
  std::stringstream stringStream;
  uInt64 integerHash = hashAdler64( (Char*)key.c_str( ), (uInt16)key.length( ) );
  stringStream << integerHash;
  stringStream >> hashString;
  String paddedHashString = blowZero( hashString, 24 );
  return paddedHashString;
} // adler24

String
fnv24_16( String key ) {
  String hashString;
  std::stringstream stringStream;
  uInt16 integerHash = hashFNV16( (Char*)key.c_str( ), (uInt16)key.length( ) );
  stringStream << integerHash;
  stringStream >> hashString;
  String paddedHashString = blowZero( hashString, 24 );
  return paddedHashString;
} // fnv24

String
fnv24_32( String key ) {
  String hashString;
  std::stringstream stringStream;
  uInt32 integerHash = hashFNV32( (Char*)key.c_str( ), (uInt16)key.length( ) );
  stringStream << integerHash;
  stringStream >> hashString;
  String paddedHashString = blowZero( hashString, 24 );
  return paddedHashString;
} // fnv24

String
fnv24_64( String key ) {
  String hashString;
  std::stringstream stringStream;
  uInt64 integerHash = hashFNV64( (Char*)key.c_str( ), (uInt16)key.length( ) );
  stringStream << integerHash;
  stringStream >> hashString;
  String paddedHashString = blowZero( hashString, 24 );
  return paddedHashString;
} // fnv24

/******************************************************************************/

uInt16
hashAdler16( Char* key, uInt16 length ) {
  uInt16 adlerSum1 = 1;
  uInt16 adlerSum2 = 0;
  for( uInt16 index = 0; index < length; index++ ) {
    uInt16 charValue = (uInt16)key[ index ]; // get to char an then cast the char
    adlerSum1 = ( adlerSum1 + charValue ) % 65521;
    adlerSum2 = ( adlerSum2 + adlerSum1 ) % 65521;
  }
  uInt16 hashResult = ( adlerSum2 << 16 ) | adlerSum1;
  return hashResult;
} // hashAdler16

uInt32
hashAdler32( Char* key, uInt16 length ) {
  uInt32 adlerSum1 = 1;
  uInt32 adlerSum2 = 0;
  for( uInt16 index = 0; index < length; index++ ) {
    uInt32 charValue = (uInt32)key[ index ]; // get to char an then cast the char
    adlerSum1 = ( adlerSum1 + charValue ) % 65521;
    adlerSum2 = ( adlerSum2 + adlerSum1 ) % 65521;
  }
  uInt32 hashResult = ( adlerSum2 << 16 ) | adlerSum1;
  return hashResult;
} // hashAdler32

uInt64
hashAdler64( Char* key, uInt16 length ) {
  uInt64 adlerSum1 = 1;
  uInt64 adlerSum2 = 0;
  for( uInt16 index = 0; index < length; index++ ) {
    uInt64 charValue = (uInt64)key[ index ]; // get to char an then cast the char
    adlerSum1 = ( adlerSum1 + charValue ) % 65521;
    adlerSum2 = ( adlerSum2 + adlerSum1 ) % 65521;
  }
  uInt64 hashResult = ( adlerSum2 << 16 ) | adlerSum1;
  return hashResult;
} // hashAdler64

uInt16
hashFNV16( Char* key, uInt16 length ) {
  uInt64 hashValue    = 0xcbf29ce484222325ULL;
  uInt64 magicPrime   = 0x00000100000001b3ULL;
  uChar* firstBytePointer = ( uChar* )( key );
  uChar* lastBytePointer  = firstBytePointer + length;
  while( firstBytePointer < lastBytePointer ) {
    hashValue ^= (uInt64)(*firstBytePointer++); // get to char an then cast the char
    hashValue *= magicPrime;
  }
  uInt16 truncatedHashValue = (uInt16)hashValue;
  return truncatedHashValue;
} // hashFNVint16

uInt32
hashFNV32( Char* key, uInt16 length ) {
  uInt64 hashValue    = 0xcbf29ce484222325ULL;
  uInt64 magicPrime   = 0x00000100000001b3ULL;
  uChar* firstBytePointer = ( uChar* )( key );
  uChar* lastBytePointer  = firstBytePointer + length;
  while( firstBytePointer < lastBytePointer ) {
    hashValue ^= (uInt64)(*firstBytePointer++); // get to char an then cast the char
    hashValue *= magicPrime;
  }
  uInt32 truncatedHashValue = (uInt32)hashValue;
  return truncatedHashValue;
} // hashFNVint32

uInt64
hashFNV64( Char* key, uInt16 length ) {
  uInt64 hashValue    = 0xcbf29ce484222325ULL;
  uInt64 magicPrime   = 0x00000100000001b3ULL;
  uChar* firstBytePointer = ( uChar* )( key );
  uChar* lastBytePointer  = firstBytePointer + length;
  while( firstBytePointer < lastBytePointer ) {
    hashValue ^= (uInt64)(*firstBytePointer++); // get to char an then cast the char
    hashValue *= magicPrime;
  }
  return hashValue;
} // hashFNVint64

/******************************************************************************/

uInt32 // ELF hash algorithm
hashELF32( Char* key, uInt16 length ) {
  uInt32 hashValue  = 0;
  uInt32 highBitMask = 0;
  for( uInt32 index = 0; index < length; key++, index++ ) {
    hashValue = (hashValue << 4) + (uInt32)(*key);
    if( ( highBitMask = hashValue & 0xF0000000L ) != 0 ) {
      hashValue ^= highBitMask >> 24;
      // The ELF ABI says `h &= ~g', but this is equivalent in
      // this case and on some machines one insn instead of two.
      hashValue ^= highBitMask;
    } // hashValue
  } // index
  return hashValue;
} // hashELF32

/******************************************************************************/

String
blowZero( String binaryString, uInt16 size ) {
  String paddedString = "";
  uInt16 zeroPadCount = size - (uInt16)binaryString.length();
  for( uInt16 index = 0; index < size; index++ )
    if( index < zeroPadCount )
      paddedString.append( "0" );
  paddedString.append( binaryString );
  return paddedString;
} // blowZero

/******************************************************************************/

} // namespace FNC

} // namespace HASHCC

/******************************************************************************/
