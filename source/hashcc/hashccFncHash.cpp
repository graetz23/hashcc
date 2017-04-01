/** 
 * @file hashccFncHash.cpp
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
  uInt16 s1 = 1;
  uInt16 s2 = 0;
  // std::cout << std::endl << std::flush;
  for( uInt16 n = 0; n < len; n++ ) {
    uInt16 s0 = (uInt16)key[ n ]; // get to char an then cast the char
    // std::cout << "s0: " << s0 << std::endl << std::flush;
    s1 = ( s1 + s0 ) % 65521;
    // std::cout << "s1: " << s2 << std::endl << std::flush;
    s2 = ( s2 + s1 ) % 65521;
    // std::cout << "s2: " << s2 << std::endl << std::flush;
  }
  // std::cout << std::endl << std::flush;
  uInt16 hash = ( s2 << 16 ) | s1;
  return hash;
} // hashAdler16

uInt32 
hashAdler32( Char* key, uInt16 len ) {
  uInt32 s1 = 1;
  uInt32 s2 = 0;
  // std::cout << std::endl << std::flush;
  for( uInt16 n = 0; n < len; n++ ) {
    uInt32 s0 = (uInt32)key[ n ]; // get to char an then cast the char
    // std::cout << "s0: " << s0 << std::endl << std::flush;
    s1 = ( s1 + s0 ) % 65521;
    // std::cout << "s1: " << s2 << std::endl << std::flush;
    s2 = ( s2 + s1 ) % 65521;
    // std::cout << "s2: " << s2 << std::endl << std::flush;
  }
  // std::cout << std::endl << std::flush;
  uInt32 hash = ( s2 << 16 ) | s1;
  return hash;
} // hashAdler32

uInt64 
hashAdler64( Char* key, uInt16 len ) {
  uInt64 s1 = 1;
  uInt64 s2 = 0;
  // std::cout << std::endl << std::flush;
  for( uInt16 n = 0; n < len; n++ ) {
    uInt64 s0 = (uInt64)key[ n ]; // get to char an then cast the char
    // std::cout << "s0: " << s0 << std::endl << std::flush;
    s1 = ( s1 + s0 ) % 65521;
    // std::cout << "s1: " << s2 << std::endl << std::flush;
    s2 = ( s2 + s1 ) % 65521;
    // std::cout << "s2: " << s2 << std::endl << std::flush;
  }
  // std::cout << std::endl << std::flush;
  uInt64 hash = ( s2 << 16 ) | s1;
  return hash;
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
  uInt32 hash = 0;
  uInt32 x = 0;
  for( uInt32 i = 0; i < len; key++, i++ ) {
    hash = (hash << 4) + (uInt32)(*key);
    if( ( x = hash & 0xF0000000L ) != 0 ) {
      hash ^= x >> 24;
      // The ELF ABI says `h &= ~g', but this is equivalent in
      // this case and on some machines one insn instead of two.
      hash ^= x;
    } // hash
  } // i
  return hash;
} // hashELF32

/******************************************************************************/

String
blowZero( String bin, uInt16 size ) {
  String blow = "";
  uInt16 steps = size - (uInt16)bin.length();
  for( uInt16 b = 0; b < size; b++ )
    if( b < steps )
      blow.append( "0" );
  blow.append( bin );
  return blow;
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
