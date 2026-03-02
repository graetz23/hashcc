/** 
 * @file hashccTest.cpp
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

#include "./hashccTest.h"

/******************************************************************************/

namespace HASHCC {

namespace TEST {

/******************************************************************************/

void 
testStc( void ) {

  for( uChar index = 0; index < STC::Bin::size; index++ )
    std::cout << STC::Bin::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

  for( uChar index = 0; index < STC::Qud::size; index++ )
    std::cout << STC::Qud::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

  for( uChar index = 0; index < STC::Oct::size; index++ )
    std::cout << STC::Oct::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

  for( uChar index = 0; index < STC::Dec::size; index++ )
    std::cout << STC::Dec::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

  for( uChar index = 0; index < STC::Hex::size; index++ )
    std::cout << STC::Hex::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

  for( uChar index = 0; index < STC::Abc::size; index++ )
    std::cout << STC::Abc::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

  for( uChar index = 0; index < STC::Aph::size; index++ )
    std::cout << STC::Aph::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

}

/******************************************************************************/

void 
testHash( void ) {
  testHashFnv( );
  testHashAdler( );
}

/******************************************************************************/

void 
testHashFnv( void ) {

  String key = "myKey";
  String stringKey = TYP::keyConv< String >( key );
  String stringHash = FNC::fnv24_16( stringKey );
  Char* charArrayHash = (Char*)stringHash.c_str( );

  std::cout << "key: " << key << " stringKey  : " << stringKey << std::endl
      << std::flush;
  std::cout << "key: " << key << " stringHash : " << stringHash << std::endl
      << std::flush;
  std::cout << "key: " << key << " charArrayHash: " << charArrayHash << std::endl
      << std::flush;

  stringKey = TYP::keyConv< String >( key );
  stringHash = FNC::fnv24_16( stringKey );
  charArrayHash = (Char*)stringHash.c_str( );

  std::cout << "key: " << key << " stringKey  : " << stringKey << std::endl
      << std::flush;
  std::cout << "key: " << key << " stringHash : " << stringHash << std::endl
      << std::flush;
  std::cout << "key: " << key << " charArrayHash: " << charArrayHash << std::endl
      << std::flush;

  stringKey = TYP::keyConv< String >( key );
  stringHash = FNC::fnv24_16( stringKey );
  charArrayHash = (Char*)stringHash.c_str( );

  std::cout << "key: " << key << " stringKey  : " << stringKey << std::endl
      << std::flush;
  std::cout << "key: " << key << " stringHash : " << stringHash << std::endl
      << std::flush;
  std::cout << "key: " << key << " charArrayHash: " << charArrayHash << std::endl
      << std::flush;

  std::cout << std::endl << std::flush;

}

/******************************************************************************/

void 
testHashAdler( void ) {

  String key = "myKey";
  String stringKey = TYP::keyConv< String >( key );
  String stringHash = FNC::adler24_16( stringKey );
  Char* charArrayHash = (Char*)stringHash.c_str( );

  std::cout << "key: " << key << " stringKey  : " << stringKey << std::endl
      << std::flush;
  std::cout << "key: " << key << " stringHash : " << stringHash << std::endl
      << std::flush;
  std::cout << "key: " << key << " charArrayHash: " << charArrayHash << std::endl
      << std::flush;

  stringKey = TYP::keyConv< String >( key );
  stringHash = FNC::adler24_16( stringKey );
  charArrayHash = (Char*)stringHash.c_str( );

  std::cout << "key: " << key << " stringKey  : " << stringKey << std::endl
      << std::flush;
  std::cout << "key: " << key << " stringHash : " << stringHash << std::endl
      << std::flush;
  std::cout << "key: " << key << " charArrayHash: " << charArrayHash << std::endl
      << std::flush;

  stringKey = TYP::keyConv< String >( key );
  stringHash = FNC::adler24_16( stringKey );
  charArrayHash = (Char*)stringHash.c_str( );

  std::cout << "key: " << key << " stringKey  : " << stringKey << std::endl
      << std::flush;
  std::cout << "key: " << key << " stringHash : " << stringHash << std::endl
      << std::flush;
  std::cout << "key: " << key << " charArrayHash: " << charArrayHash << std::endl
      << std::flush;

  std::cout << std::endl << std::flush;

}

/******************************************************************************/

void 
testHashMap( OBJ::Type::HashMap hashMapType ) {

  try {

    OBJ::HashMapBuilder hashMapBuilder;
    String load = "walter";
    String* previousString = 0;

    OBJ::HashMap< Int16, String >* hashMapInt16Str = hashMapBuilder
        .create< Int16, String >( hashMapType );
    Int16 keyInt16 = 23;
    previousString = hashMapInt16Str->put( keyInt16, load );
    std::cout << "key: " << keyInt16 << " value: "
        << hashMapInt16Str->get( keyInt16 ) << std::endl << std::flush;
    delete hashMapInt16Str;
    std::cout << std::endl << std::flush;

    int numberOfItems = 64;
    OBJ::HashMap< Int16, Int16 >* hashMapI = hashMapBuilder
        .create< Int16, Int16 >( hashMapType );
    for( Int16 index = 0; index < numberOfItems; index++ )
      hashMapI->put( index * 17, index );
    for( Int16 index = 0; index < numberOfItems; index++ ) {
      Int16 value = hashMapI->get( index * 17 );
      std::cout << "index: " << index << " key: " << index * 17 << " value: " << value
          << std::endl << std::flush;
    }
    delete hashMapI;
    std::cout << std::endl << std::flush;

    numberOfItems = 64;
    OBJ::HashMap< Int16, DMY::Noob* >* hashMapN = hashMapBuilder
        .create< Int16, DMY::Noob* >( hashMapType );
    for( Int16 index = 0; index < numberOfItems; index++ )
      hashMapN->put( index * 7, new DMY::Noob( ) );
    for( Int16 index = 0; index < numberOfItems; index++ ) {
      DMY::Noob* value = hashMapN->get( index * 7 );
      std::cout << "index: " << index << " key: " << index * 7 << " value: " << value
          << std::endl << std::flush;
      delete value;
    }
    delete hashMapN;
    std::cout << std::endl << std::flush;

  } catch( ERR::Failure& caughtFailure ) {
    std::cout << "HASHCC::ERR::Failure:" << std::endl << std::flush;
    caughtFailure.report( );
  } catch( ERR::Error& caughtError ) {
    std::cout << "HASHCC::ERR::Error:" << std::endl << std::flush;
    caughtError.report( );
  } catch( ERR::Exception& caughtException ) {
    std::cout << "HASHCC::ERR::Exception:" << std::endl << std::flush;
    caughtException.report( );
  } catch( std::exception& caughtStdException ) {
    std::cout << "std::exception:" << std::endl << std::flush;
    std::cout << caughtStdException.what( ) << std::endl << std::flush;
  } catch( ... ) {
    std::cout << "unknown exception" << std::endl << std::flush;
  }

}

/******************************************************************************/

} // namespace TEST

} // namespace HASHCC

/******************************************************************************/
