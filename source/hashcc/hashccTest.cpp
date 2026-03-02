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

#include "./hashccTest.h" // header

/******************************************************************************/

namespace HASHCC {

namespace TEST {

/******************************************************************************/

void /// test the static look up tables from above
testStc( void ) {

  for( uChar index = 0; index < STC::Bin::size; index++ ) // HASHCC::STC::Bin
    std::cout << STC::Bin::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

  for( uChar index = 0; index < STC::Qud::size; index++ ) // HASHCC::STC::Qud
    std::cout << STC::Qud::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

  for( uChar index = 0; index < STC::Oct::size; index++ ) // HASHCC::STC::Oct
    std::cout << STC::Oct::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

  for( uChar index = 0; index < STC::Dec::size; index++ ) // HASHCC::STC::Dec
    std::cout << STC::Dec::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

  for( uChar index = 0; index < STC::Hex::size; index++ ) // HASHCC::STC::Hex
    std::cout << STC::Hex::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

  for( uChar index = 0; index < STC::Abc::size; index++ ) // HASHCC::STC::Abc
    std::cout << STC::Abc::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

  for( uChar index = 0; index < STC::Aph::size; index++ ) // HASHCC::STC::Aph
    std::cout << STC::Aph::val[ index ] << " " << std::flush;
  std::cout << std::endl << std::flush;

} // testStc

/******************************************************************************/

void // tests the available hash functions
testHash( void ) {

  testHashFnv( );
  testHashAdler( );

} // testHash

void /// tests HASHCC::FNC:: hash functions
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

} // testHash

void /// tests HASHCC::FNC:: hash functions
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

} // testHash

/******************************************************************************/

void /// testing for different keys and value types
testHashMap( OBJ::Type::HashMap hashMapType ) {

  try {

    OBJ::HashMapBuilder hashMapBuilder;

    String load = "walter";
    String* previousString = 0;

    OBJ::HashMap< String, String >* hashMapStrStr = hashMapBuilder
        .create< String, String >( hashMapType );
    String keyString = "myKey";
    previousString = hashMapStrStr->put( keyString, load );
    std::cout << "key: " << keyString << " value: " << hashMapStrStr->get( keyString )
        << std::endl << std::flush;
    delete hashMapStrStr;
    std::cout << std::endl << std::flush;

    OBJ::HashMap< Int16, String >* hashMapInt16Str = hashMapBuilder
        .create< Int16, String >( hashMapType );
    Int16 keyInt16 = 23;
    previousString = hashMapInt16Str->put( keyInt16, load );
    std::cout << "key: " << keyInt16 << " value: "
        << hashMapInt16Str->get( keyInt16 ) << std::endl << std::flush;
    delete hashMapInt16Str;
    std::cout << std::endl << std::flush;

    OBJ::HashMap< Int32, String >* hashMapInt32Str = hashMapBuilder
        .create< Int32, String >( hashMapType );
    Int32 keyInt32 = 23;
    previousString = hashMapInt32Str->put( keyInt32, load );
    std::cout << "key: " << keyInt32 << " value: "
        << hashMapInt32Str->get( keyInt32 ) << std::endl << std::flush;
    delete hashMapInt32Str;
    std::cout << std::endl << std::flush;

    OBJ::HashMap< Int64, String >* hashMapInt64Str = hashMapBuilder
        .create< Int64, String >( hashMapType );
    Int64 keyInt64 = 23;
    previousString = hashMapInt64Str->put( keyInt64, load );
    std::cout << "key: " << keyInt64 << " value: "
        << hashMapInt64Str->get( keyInt64 ) << std::endl << std::flush;
    delete hashMapInt64Str;
    std::cout << std::endl << std::flush;

    OBJ::HashMap< uInt16, String >* hashMapuInt16Str = hashMapBuilder
        .create< uInt16, String >( hashMapType );
    uInt16 keyuInt16 = 23;
    previousString = hashMapuInt16Str->put( keyuInt16, load );
    std::cout << "key: " << keyuInt16 << " value: "
        << hashMapuInt16Str->get( keyuInt16 ) << std::endl << std::flush;
    delete hashMapuInt16Str;
    std::cout << std::endl << std::flush;

    OBJ::HashMap< uInt32, String >* hashMapuInt32Str = hashMapBuilder
        .create< uInt32, String >( hashMapType );
    uInt32 keyuInt32 = 23;
    previousString = hashMapuInt32Str->put( keyuInt32, load );
    std::cout << "key: " << keyuInt32 << " value: "
        << hashMapuInt32Str->get( keyuInt32 ) << std::endl << std::flush;
    delete hashMapuInt32Str;
    std::cout << std::endl << std::flush;

    OBJ::HashMap< uInt64, String >* hashMapuInt64Str = hashMapBuilder
        .create< uInt64, String >( hashMapType );
    uInt64 keyuInt64 = 23;
    previousString = hashMapuInt64Str->put( keyuInt64, load );
    std::cout << "key: " << keyuInt64 << " value: "
        << hashMapuInt64Str->get( keyuInt64 ) << std::endl << std::flush;
    delete hashMapuInt64Str;
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
    OBJ::HashMap< Int16, std::exception* >* hashMapE = hashMapBuilder
        .create< Int16, std::exception* >( hashMapType );
    for( Int16 index = 0; index < numberOfItems; index++ )
      hashMapE->put( index * 13, new std::exception( ) );
    for( Int16 index = 0; index < numberOfItems; index++ ) {
      std::exception* value = hashMapE->get( index * 13 );
      std::cout << "index: " << index << " key: " << index * 13 << " value: " << value
          << std::endl << std::flush;
      delete value;
    }
    delete hashMapE;
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

    numberOfItems = 100000;
    OBJ::HashMap< Int16, Int16 >* hashMapLoad = hashMapBuilder
        .create< Int16, Int16 >( hashMapType );
    for( Int16 index = 0; index < numberOfItems; index++ )
      hashMapLoad->put( index, index );
    for( Int16 index = 0; index < numberOfItems; index++ ) {
      Int16 value = hashMapLoad->get( index );
      if( value != index ) // counter was stored
        throw ERR::Error( "TEST::HashMap - hashed wrong value for key" );
    } // index
    delete hashMapLoad;
    std::cout << std::endl << std::flush;

  } catch( ERR::Failure& caughtFailure ) {
    std::cout << "HASHCC::ERR::Failure:" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
    caughtFailure.report( );
  } catch( ERR::Error& caughtError ) {
    std::cout << "HASHCC::ERR::Error:" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
    caughtError.report( );
  } catch( ERR::Exception& caughtException ) {
    std::cout << "HASHCC::ERR::Exception:" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
    caughtException.report( );
  } catch( std::exception& caughtStdException ) {
    std::cout << "std::exception:" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
    std::cout << caughtStdException.what( ) << std::endl << std::flush;
  } catch( ... ) {
    std::cout << "unknown exception" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
  } // try

} // testHashMap

void /// tests the TreeController and the Tree
test( void ) {

  try {

    TYP::TreeController* treeController = new TYP::TreeController( );

    Int16 keySize = 16;
    Char* key1 = (Char*)"0110001010101011";
    Char* key2 = (Char*)"0110001010101010"; // same as key1 till last bit
    Char* key3 = (Char*)"1110001010101011";
    Char* key4 = (Char*)"1110001010101010"; // same as key3 till last bit

    String emptyString( "" );
    String dummyString( "DUMMY LOAD" );
    String string1( "Hash me, hash me once" );
    String string2( "Hash me, hash me a second time" );
    String string3( "Hash me, hash me again and again" );
    String string4( "Hash me, hash me over and over again" );
    String string5( "Hash me, hash me over and over again forever" );

    TYP::Tree* tree = 0;

    uInt16 bufferSize = 1;

    // int hash //
    for( Int16 intValue = -10; intValue < 10; intValue++ ) {
      uInt16* buffer = new uInt16[ bufferSize ];
      for( uInt16 bufferIndex = 0; bufferIndex < bufferSize; bufferIndex++ )
        buffer[ bufferIndex ] = intValue;
      std::cout << intValue << " decimal == "
          << FNC::hashAdler16( (Char*)buffer, bufferSize ) << " binary"
          << std::endl << std::flush;
      delete[ ] buffer;
    }
    std::cout << std::endl << std::flush;

    // char hash //
    for( uChar charValue = 0; charValue < 10; charValue++ ) {
      Char* buffer = new Char[ bufferSize ];
      for( uChar bufferIndex = 0; bufferIndex < bufferSize; bufferIndex++ )
        buffer[ bufferIndex ] = charValue;
      std::cout << charValue << " decimal == " << FNC::hashAdler32( buffer, bufferSize )
          << " binary" << std::endl << std::flush;
      std::cout << charValue << " decimal == " << FNC::hashFNV32( buffer, bufferSize )
          << " binary" << std::endl << std::flush;
      delete[ ] buffer;
    }
    std::cout << std::endl << std::flush;

    // adler 32 //
    for( Int16 intValue = -10; intValue < 10; intValue++ ) {
      Char* buffer = new Char[ bufferSize ];
      for( uInt16 bufferIndex = 0; bufferIndex < bufferSize; bufferIndex++ )
        buffer[ bufferIndex ] = (Char)intValue;
      uInt16 fnvHashInteger = FNC::hashFNV16( buffer, bufferSize );
      std::stringstream stream;
      stream << fnvHashInteger;
      String fnvHashString;
      stream >> fnvHashString;
      std::cout << intValue << " decimal == " << fnvHashString << " binary" << std::endl
          << std::flush;

      treeController->storeDec< String >( tree, dummyString, (Char*)fnvHashString.c_str( ), 24 );
      std::cout << intValue << " fetched == "
          << treeController->getDec< String >( tree, (Char*)fnvHashString.c_str( ), 24 )
          << std::endl << std::flush;

      delete[ ] buffer;
    }
    treeController->delDec< String >( tree, 24 );
    tree = 0;
    std::cout << std::endl << std::flush;

    String* previousValue = 0;
    std::cout << "key: " << key1 << "\t" << "value: " << string1 << std::endl
        << std::flush;
    previousValue = treeController->storeBin< String >( tree, string1, key1, keySize );
    String result1 = treeController->getBin< String >( tree, key1, keySize );
    std::cout << "key: " << key1 << "\t" << "value: " << result1 << std::endl
        << std::flush;
    std::cout << std::endl << std::flush;

    std::cout << "key: " << key2 << "\t" << "value: " << string2 << std::endl
        << std::flush;
    previousValue = treeController->storeBin< String >( tree, string2, key2, keySize );
    String result2 = treeController->getBin< String >( tree, key2, keySize );
    std::cout << "key: " << key2 << "\t" << "value: " << result2 << std::endl
        << std::flush;
    std::cout << std::endl << std::flush;

    std::cout << "key: " << key3 << "\t" << "value: " << string3 << std::endl
        << std::flush;
    previousValue = treeController->storeBin< String >( tree, string3, key3, keySize );
    String result3 = treeController->getBin< String >( tree, key3, keySize );
    std::cout << "key: " << key3 << "\t" << "value: " << result3 << std::endl
        << std::flush;
    std::cout << std::endl << std::flush;

    std::cout << "key: " << key4 << "\t" << "value: " << string4 << std::endl
        << std::flush;
    previousValue = treeController->storeBin< String >( tree, string4, key4, keySize );
    if( previousValue != 0 ) {
      String stringPreviousValue = *previousValue;
      delete previousValue;
      std::cout << "previousValue: " << stringPreviousValue << "\t" << "value: " << string4 << std::endl
          << std::flush;
    }
    std::cout << std::endl << std::flush;

    std::cout << "key: " << key4 << "\t" << "value: " << string4 << std::endl
        << std::flush;
    previousValue = treeController->storeBin< String >( tree, string5, key4, keySize );
    if( previousValue != 0 ) {
      String stringPreviousValue = *previousValue;
      delete previousValue;
      std::cout << "previousValue: " << stringPreviousValue << "\t" << "value: " << string5 << std::endl
          << std::flush;
    }
    String result4 = treeController->getBin< String >( tree, key4, keySize );
    std::cout << "key: " << key4 << "\t" << "value: " << result4 << std::endl
        << std::flush;
    std::cout << std::endl << std::flush;

    treeController->delBin< String >( tree, keySize );

    tree = 0;
    keySize = 16;
    Int16 range = (Int16)pow( 2., (double)keySize );
    for( Int16 hashIndex = 0; hashIndex < range; hashIndex++ ) {

      String hashString = HASHCC::FNC::blowZero( HASHCC::JNK::xxx_to_bin( hashIndex ),
        keySize );
      cChar* keyChars = hashString.c_str( );
      String loadString = hashString; // 16
      //loadString = emptyString;
      loadString.append( loadString ); // 32
      loadString.append( loadString ); // 64
      //loadString.append( loadString ); // 128
      //loadString.append( loadString ); // 256
      //loadString.append( loadString ); // 512
      //loadString.append( loadString ); // 1024
      //loadString.append( loadString ); // 2048
      //loadString.append( loadString ); // 4096
      treeController->storeBin< String >( tree, loadString, (Char*)keyChars, keySize );

    } // hashIndex

    for( Int16 hashIndex = 0; hashIndex < range; hashIndex++ ) {

      String hashString = HASHCC::FNC::blowZero( HASHCC::JNK::xxx_to_bin( hashIndex ),
        keySize );
      cChar* keyChars = hashString.c_str( );
      String resultString = treeController->getBin< String >( tree, (Char*)keyChars, keySize );
      // std::cout << resultString << std::endl << std::flush;

    } // hashIndex

    Char* search1 = (Char*)"0101010101010101";
    std::cout << treeController->getBin< String >( tree, search1, keySize ) << std::endl
        << std::flush;
    Char* search2 = (Char*)"0000000000000000";
    std::cout << treeController->getBin< String >( tree, search2, keySize ) << std::endl
        << std::flush;
    Char* search3 = (Char*)"1111111111111111";
    std::cout << treeController->getBin< String >( tree, search3, keySize ) << std::endl
        << std::flush;
    Char* search4 = (Char*)"1010101010101010";
    std::cout << treeController->getBin< String >( tree, search4, keySize ) << std::endl
        << std::flush;
    Char* search5 = (Char*)"0000111100001111";
    std::cout << treeController->getBin< String >( tree, search5, keySize ) << std::endl
        << std::flush;

    treeController->delBin< String >( tree, keySize );

    delete treeController;

  } catch( ERR::Failure caughtFailure ) {
    std::cout << "HASHCC::ERR::Failure:" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
    caughtFailure.report( );
  } catch( ERR::Error caughtError ) {
    std::cout << "HASHCC::ERR::Error:" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
    caughtError.report( );
  } catch( ERR::Exception caughtException ) {
    std::cout << "HASHCC::ERR::Exception:" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
    caughtException.report( );
  } catch( std::exception caughtStdException ) {
    std::cout << "std::exception:" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
    std::cout << caughtStdException.what( ) << std::endl << std::flush;
  } catch( ... ) {
    std::cout << "unknown exception" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
  } // try

} // testTreeController

/******************************************************************************/

} // namespace TEST

} // namespace HASHCC

/******************************************************************************/
