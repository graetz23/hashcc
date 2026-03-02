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
  String hash;
  std::stringstream sstr;
  uInt32 intHash = hashAdler32( (Char*)key.c_str( ), (uInt16)key.length( ) );
  sstr << intHash;
  sstr >> hash;
  String hash24 = blowZero( hash, 10 );
  return hash24;
} // elf10_16

String
adler24_16( String key  ) {
  String hash;
  std::stringstream sstr;
  uInt16 intHash = hashAdler16( (Char*)key.c_str( ), (uInt16)key.length( ) );
  sstr << intHash;
  sstr >> hash;
  String hash24 = blowZero( hash, 24 );
  return hash24;
} // adler24

String
adler24_32( String key  ) {
  String hash;
  std::stringstream sstr;
  uInt32 intHash = hashAdler32( (Char*)key.c_str( ), (uInt16)key.length( ) );
  sstr << intHash;
  sstr >> hash;
  String hash24 = blowZero( hash, 24 );
  return hash24;
} // adler24

String
adler24_64( String key  ) {
  String hash;
  std::stringstream sstr;
  uInt64 intHash = hashAdler64( (Char*)key.c_str( ), (uInt16)key.length( ) );
  sstr << intHash;
  sstr >> hash;
  String hash24 = blowZero( hash, 24 );
  return hash24;
} // adler24

String
fnv24_16( String key ) {
  String hash;
  std::stringstream sstr;
  uInt16 intHash = hashFNV16( (Char*)key.c_str( ), (uInt16)key.length( ) );
  sstr << intHash;
  sstr >> hash;
  String hash24 = blowZero( hash, 24 );
  return hash24;
} // fnv24

String
fnv24_32( String key ) {
  String hash;
  std::stringstream sstr;
  uInt32 intHash = hashFNV32( (Char*)key.c_str( ), (uInt16)key.length( ) );
  sstr << intHash;
  sstr >> hash;
  String hash24 = blowZero( hash, 24 );
  return hash24;
} // fnv24

String
fnv24_64( String key ) {
  String hash;
  std::stringstream sstr;
  uInt64 intHash = hashFNV64( (Char*)key.c_str( ), (uInt16)key.length( ) );
  sstr << intHash;
  sstr >> hash;
  String hash24 = blowZero( hash, 24 );
  return hash24;
} // fnv24

/******************************************************************************/

uInt16
hashAdler16( Char* key, uInt16 len ) {
  uInt16 adlerSum1 = 1;
  uInt16 adlerSum2 = 0;
  // std::cout << std::endl << std::flush;
  for( uInt16 index = 0; index < len; index++ ) {
    uInt16 charValue = (uInt16)key[ index ]; // get to char an then cast the char
    // std::cout << "charValue: " << charValue << std::endl << std::flush;
    adlerSum1 = ( adlerSum1 + charValue ) % 65521;
    // std::cout << "adlerSum1: " << adlerSum1 << std::endl << std::flush;
    adlerSum2 = ( adlerSum2 + adlerSum1 ) % 65521;
    // std::cout << "adlerSum2: " << adlerSum2 << std::endl << std::flush;
  }
  // std::cout << std::endl << std::flush;
  uInt16 hashResult = ( adlerSum2 << 16 ) | adlerSum1;
  return hashResult;
} // hashAdler16

uInt32 
hashAdler32( Char* key, uInt16 len ) {
  uInt32 adlerSum1 = 1;
  uInt32 adlerSum2 = 0;
  // std::cout << std::endl << std::flush;
  for( uInt16 index = 0; index < len; index++ ) {
    uInt32 charValue = (uInt32)key[ index ]; // get to char an then cast the char
    // std::cout << "charValue: " << charValue << std::endl << std::flush;
    adlerSum1 = ( adlerSum1 + charValue ) % 65521;
    // std::cout << "adlerSum1: " << adlerSum1 << std::endl << std::flush;
    adlerSum2 = ( adlerSum2 + adlerSum1 ) % 65521;
    // std::cout << "adlerSum2: " << adlerSum2 << std::endl << std::flush;
  }
  // std::cout << std::endl << std::flush;
  uInt32 hashResult = ( adlerSum2 << 16 ) | adlerSum1;
  return hashResult;
} // hashAdler32

uInt64 
hashAdler64( Char* key, uInt16 len ) {
  uInt64 adlerSum1 = 1;
  uInt64 adlerSum2 = 0;
  // std::cout << std::endl << std::flush;
  for( uInt16 index = 0; index < len; index++ ) {
    uInt64 charValue = (uInt64)key[ index ]; // get to char an then cast the char
    // std::cout << "charValue: " << charValue << std::endl << std::flush;
    adlerSum1 = ( adlerSum1 + charValue ) % 65521;
    // std::cout << "adlerSum1: " << adlerSum1 << std::endl << std::flush;
    adlerSum2 = ( adlerSum2 + adlerSum1 ) % 65521;
    // std::cout << "adlerSum2: " << adlerSum2 << std::endl << std::flush;
  }
  // std::cout << std::endl << std::flush;
  uInt64 hashResult = ( adlerSum2 << 16 ) | adlerSum1;
  return hashResult;
} // hashAdler64

uInt16
hashFNV16( Char* key, uInt16 len ) {
  uInt64 nHashVal    = 0xcbf29ce484222325ULL;
  uInt64 nMagicPrime = 0x00000100000001b3ULL;
  uChar* pFirst = ( uChar* )( key );
  uChar* pLast  = pFirst + len;
  while( pFirst < pLast ) {
   nHashVal ^= (uInt64)(*pFirst++); // get to char an then cast the char
   nHashVal *= nMagicPrime;
  }
  uInt16 nHashValTrunk = (uInt16)nHashVal;
  return nHashValTrunk;
} // hashFNVint16

uInt32 
hashFNV32( Char* key, uInt16 len ) {
  uInt64 nHashVal    = 0xcbf29ce484222325ULL;
  uInt64 nMagicPrime = 0x00000100000001b3ULL;
  uChar* pFirst = ( uChar* )( key );
  uChar* pLast  = pFirst + len;
  while( pFirst < pLast ) {
   nHashVal ^= (uInt64)(*pFirst++); // get to char an then cast the char
   nHashVal *= nMagicPrime;
  }
  uInt32 nHashValTrunk = (uInt32)nHashVal;
  return nHashValTrunk;
} // hashFNVint32

uInt64 
hashFNV64( Char* key, uInt16 len ) {
  uInt64 nHashVal    = 0xcbf29ce484222325ULL;
  uInt64 nMagicPrime = 0x00000100000001b3ULL;
  uChar* pFirst = ( uChar* )( key );
  uChar* pLast  = pFirst + len;
  while( pFirst < pLast ) {
   nHashVal ^= (uInt64)(*pFirst++); // get to char an then cast the char
   nHashVal *= nMagicPrime;
  }
  return nHashVal;
} // hashFNVint64

/******************************************************************************/

uInt32 // ELF hash algorithm
hashELF32( Char* key, uInt16 len ) {
  uInt32 hashValue = 0;
  uInt32 highBitMask = 0;
  for( uInt32 index = 0; index < len; key++, index++ ) {
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

//String // convert DEC to Char
//int2str( Int16 dec ) {
//  String s;
//  std::stringstream stream;
//  stream << dec;
//  stream >> s;
//  return s;
//} // int2str

//String // convert DEC to Char
//int2str( Int32 dec ) {
//  String s;
//  std::stringstream stream;
//  stream << dec;
//  stream >> s;
//  return s;
//} // int2str

//String // convert DEC to String
//int2str( Int64 dec ) {
//  String s;
//  std::stringstream stream;
//  stream << dec;
//  stream >> s;
//  return s;
//} // int2str

/******************************************************************************/

//String 
//dec2hex( Int16 dec ) {
//  Int16 i = 0;
//  std::stack<Int16> remainder;
//  String hex, temp;
//  Char* hexDigits = { "0123456789ABCDEF" };
//  while( dec != 0 ) {
//    remainder.push( dec % 16 );
//    dec /= 16;
//    ++i;
//  } // while
//  while( i != 0 ) {
//    if( remainder.top( ) > 15 ) {
//      temp = dec2hex( remainder.top( ) );
//      hex += temp;
//    }
//    hex.push_back( hexDigits[ remainder.top( ) ] );
//    remainder.pop( );
//    --i;
//  } // while
//  return hex;
//} // dec2hex

/******************************************************************************/

} // namespace FNC

} // namespace HASHCC

/******************************************************************************/
