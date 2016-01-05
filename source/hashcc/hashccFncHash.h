/** 
 * @file hashccFncHash.h
 * @author Christian Scheiblich
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2009-2016 Christian Scheiblich (cscheiblich@gmail.com)
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

#ifndef __hashccFncHash_h__
#define __hashccFncHash_h__

/******************************************************************************/

#include "./hashccTyp.h" // HASHCC data types

/******************************************************************************/

namespace HASHCC {

namespace FNC {

/******************************************************************************/

#define _VERSION_HASHCC_FNC_Hash_ 0.15 // 20141231
#define _DEBUG_HASHCC_FNC_Hash_

/******************************************************************************/

String elf10_32( String key ); /// returns a hash of 10 decimal symbols

String adler24_16( String key ); /// returns a hash of 24 decimal symbols
String adler24_32( String key ); /// returns a hash of 24 decimal symbols
String adler24_64( String key ); /// returns a hash of 24 decimal symbols

String fnv24_16( String key ); /// returns a hash of 24 decimal symbols
String fnv24_32( String key ); /// returns a hash of 24 decimal symbols
String fnv24_64( String key ); /// returns a hash of 24 decimal symbols

/******************************************************************************/

uInt16 hashAdler16( Char* key, uInt16 len );
uInt32 hashAdler32( Char* key, uInt16 len );
uInt64 hashAdler64( Char* key, uInt16 len );

uInt16 hashFNV16( Char* key, uInt16 len );
uInt32 hashFNV32( Char* key, uInt16 len );
uInt64 hashFNV64( Char* key, uInt16 len ); 

/******************************************************************************/

uInt32 // ELF hash function using int
hashELF32( Char* key, uInt16 len );

/******************************************************************************/

String blowZero( String str, uInt16 size );
 
/******************************************************************************/

//String dec2hex2( Int16 dec ); // convert DEC to HEX

/******************************************************************************/

} // namespace FNC

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccFncHash_h__
