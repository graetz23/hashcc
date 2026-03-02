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
  String strKey = TYP::keyConv< String >( key );

  String strHash = FNC::fnv24_16( strKey );
  Char* charHash = (Char*)strHash.c_str( );

  std::cout << "key: " << key << " strKey  : " << strKey << std::endl
      << std::flush;
  std::cout << "key: " << key << " strHash : " << strHash << std::endl
      << std::flush;
  std::cout << "key: " << key << " charHash: " << charHash << std::endl
      << std::flush;

  strKey = TYP::keyConv< String >( key );

  strHash = FNC::fnv24_16( strKey );
  charHash = (Char*)strHash.c_str( );

  std::cout << "key: " << key << " strKey  : " << strKey << std::endl
      << std::flush;
  std::cout << "key: " << key << " strHash : " << strHash << std::endl
      << std::flush;
  std::cout << "key: " << key << " charHash: " << charHash << std::endl
      << std::flush;

  strKey = TYP::keyConv< String >( key );

  strHash = FNC::fnv24_16( strKey );
  charHash = (Char*)strHash.c_str( );

  std::cout << "key: " << key << " strKey  : " << strKey << std::endl
      << std::flush;
  std::cout << "key: " << key << " strHash : " << strHash << std::endl
      << std::flush;
  std::cout << "key: " << key << " charHash: " << charHash << std::endl
      << std::flush;

  std::cout << std::endl << std::flush;

} // testHash

void /// tests HASHCC::FNC:: hash functions
testHashAdler( void ) {

  String key = "myKey";

  String strKey = TYP::keyConv< String >( key );

  String strHash = FNC::adler24_16( strKey );
  Char* charHash = (Char*)strHash.c_str( );

  std::cout << "key: " << key << " strKey  : " << strKey << std::endl
      << std::flush;
  std::cout << "key: " << key << " strHash : " << strHash << std::endl
      << std::flush;
  std::cout << "key: " << key << " charHash: " << charHash << std::endl
      << std::flush;

  strKey = TYP::keyConv< String >( key );

  strHash = FNC::adler24_16( strKey );
  charHash = (Char*)strHash.c_str( );

  std::cout << "key: " << key << " strKey  : " << strKey << std::endl
      << std::flush;
  std::cout << "key: " << key << " strHash : " << strHash << std::endl
      << std::flush;
  std::cout << "key: " << key << " charHash: " << charHash << std::endl
      << std::flush;

  strKey = TYP::keyConv< String >( key );

  strHash = FNC::adler24_16( strKey );
  charHash = (Char*)strHash.c_str( );

  std::cout << "key: " << key << " strKey  : " << strKey << std::endl
      << std::flush;
  std::cout << "key: " << key << " strHash : " << strHash << std::endl
      << std::flush;
  std::cout << "key: " << key << " charHash: " << charHash << std::endl
      << std::flush;

  std::cout << std::endl << std::flush;

} // testHash

/******************************************************************************/

void /// testing for different keys and value types
testHashMap( OBJ::Type::HashMap hashMapType ) {

  try {

    OBJ::HashMapBuilder hashMapBuilder;

    String load = "walter";
    String* pStr = 0;

    OBJ::HashMap< String, String >* hashMapStrStr = hashMapBuilder
        .create< String, String >( hashMapType );
    String keyStr = "myKey";
    pStr = hashMapStrStr->put( keyStr, load );
    std::cout << "key: " << keyStr << " value: " << hashMapStrStr->get( keyStr )
        << std::endl << std::flush;
    delete hashMapStrStr;
    std::cout << std::endl << std::flush;

    OBJ::HashMap< Int16, String >* hashMapInt16Str = hashMapBuilder
        .create< Int16, String >( hashMapType );
    Int16 keyInt16 = 23;
    pStr = hashMapInt16Str->put( keyInt16, load );
    std::cout << "key: " << keyInt16 << " value: "
        << hashMapInt16Str->get( keyInt16 ) << std::endl << std::flush;
    delete hashMapInt16Str;
    std::cout << std::endl << std::flush;

    OBJ::HashMap< Int32, String >* hashMapInt32Str = hashMapBuilder
        .create< Int32, String >( hashMapType );
    Int32 keyInt32 = 23;
    pStr = hashMapInt32Str->put( keyInt32, load );
    std::cout << "key: " << keyInt32 << " value: "
        << hashMapInt32Str->get( keyInt32 ) << std::endl << std::flush;
    delete hashMapInt32Str;
    std::cout << std::endl << std::flush;

    OBJ::HashMap< Int64, String >* hashMapInt64Str = hashMapBuilder
        .create< Int64, String >( hashMapType );
    Int64 keyInt64 = 23;
    pStr = hashMapInt64Str->put( keyInt64, load );
    std::cout << "key: " << keyInt64 << " value: "
        << hashMapInt64Str->get( keyInt64 ) << std::endl << std::flush;
    delete hashMapInt64Str;
    std::cout << std::endl << std::flush;

    OBJ::HashMap< uInt16, String >* hashMapuInt16Str = hashMapBuilder
        .create< uInt16, String >( hashMapType );
    uInt16 keyuInt16 = 23;
    pStr = hashMapuInt16Str->put( keyuInt16, load );
    std::cout << "key: " << keyuInt16 << " value: "
        << hashMapuInt16Str->get( keyuInt16 ) << std::endl << std::flush;
    delete hashMapuInt16Str;
    std::cout << std::endl << std::flush;

    OBJ::HashMap< uInt32, String >* hashMapuInt32Str = hashMapBuilder
        .create< uInt32, String >( hashMapType );
    uInt32 keyuInt32 = 23;
    pStr = hashMapuInt32Str->put( keyuInt32, load );
    std::cout << "key: " << keyuInt32 << " value: "
        << hashMapuInt32Str->get( keyuInt32 ) << std::endl << std::flush;
    delete hashMapuInt32Str;
    std::cout << std::endl << std::flush;

    OBJ::HashMap< uInt64, String >* hashMapuInt64Str = hashMapBuilder
        .create< uInt64, String >( hashMapType );
    uInt64 keyuInt64 = 23;
    pStr = hashMapuInt64Str->put( keyuInt64, load );
    std::cout << "key: " << keyuInt64 << " value: "
        << hashMapuInt64Str->get( keyuInt64 ) << std::endl << std::flush;
    delete hashMapuInt64Str;
    std::cout << std::endl << std::flush;

    int noOf = 64;
    OBJ::HashMap< Int16, Int16 >* hashMapI = hashMapBuilder
        .create< Int16, Int16 >( hashMapType );
    for( Int16 index = 0; index < noOf; index++ )
      hashMapI->put( index * 17, index );
    for( Int16 index = 0; index < noOf; index++ ) {
      Int16 value = hashMapI->get( index * 17 );
      std::cout << "index: " << index << " key: " << index * 17 << " value: " << value
          << std::endl << std::flush;
    }
    delete hashMapI;
    std::cout << std::endl << std::flush;

    noOf = 64;
    OBJ::HashMap< Int16, std::exception* >* hashMapE = hashMapBuilder
        .create< Int16, std::exception* >( hashMapType );
    for( Int16 index = 0; index < noOf; index++ )
      hashMapE->put( index * 13, new std::exception( ) );
    for( Int16 index = 0; index < noOf; index++ ) {
      std::exception* value = hashMapE->get( index * 13 );
      std::cout << "index: " << index << " key: " << index * 13 << " value: " << value
          << std::endl << std::flush;
      delete value;
    }
    delete hashMapE;
    std::cout << std::endl << std::flush;

    noOf = 64;
    OBJ::HashMap< Int16, DMY::Noob* >* hashMapN = hashMapBuilder
        .create< Int16, DMY::Noob* >( hashMapType );
    for( Int16 index = 0; index < noOf; index++ )
      hashMapN->put( index * 7, new DMY::Noob( ) );
    for( Int16 index = 0; index < noOf; index++ ) {
      DMY::Noob* value = hashMapN->get( index * 7 );
      std::cout << "index: " << index << " key: " << index * 7 << " value: " << value
          << std::endl << std::flush;
      delete value;
    }
    delete hashMapN;
    std::cout << std::endl << std::flush;

    noOf = 100000;
    OBJ::HashMap< Int16, Int16 >* hashMapLoad = hashMapBuilder
        .create< Int16, Int16 >( hashMapType );
    for( Int16 index = 0; index < noOf; index++ )
      hashMapLoad->put( index, index );
    for( Int16 index = 0; index < noOf; index++ ) {
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

    // should throw exception
    //OBJ::HashMap<bool, String>* hashMapuBoolStr = hashMapBuilder.create<bool, String>( OBJ::Type::Dec24 );
    //uInt64 keyBool = true;
    //pStr = hashMapuBoolStr->put( keyBool, load );
    //std::cout << "key: " << keyBool << " value: " << hashMapuBoolStr->get( keyBool ) << std::endl << std::flush;
    //delete hashMapuBoolStr;

    TYP::TreeController* treeC = new TYP::TreeController( );

    Int16 keySize = 16;
    Char* key1 = (Char*)"0110001010101011";
    Char* key2 = (Char*)"0110001010101010"; // same as key1 till last bit
    Char* key3 = (Char*)"1110001010101011";
    Char* key4 = (Char*)"1110001010101010"; // same as key3 till last bit

    //Int16 keySize = 2;
    //Char* key1 = "00";
    //Char* key2 = "01";
    //Char* key3 = "10";
    //Char* key4 = "11";

    String emptyString( "" );
    String str( "DUMMY LOAD" );
    String str1( "Hash me, hash me once" );
    String str2( "Hash me, hash me a second time" );
    String str3( "Hash me, hash me again and again" );
    String str4( "Hash me, hash me over and over again" );
    String str5( "Hash me, hash me over and over again forever" );

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
      uInt16 fnvHashInt = FNC::hashFNV16( buffer, bufferSize );
      std::stringstream stream;
      stream << fnvHashInt;
      String fnvHash;
      stream >> fnvHash;
      std::cout << intValue << " decimal == " << fnvHash << " binary" << std::endl
          << std::flush;

      treeC->storeDec< String >( tree, str, (Char*)fnvHash.c_str( ), 24 );
      std::cout << intValue << " fetched == "
          << treeC->getDec< String >( tree, (Char*)fnvHash.c_str( ), 24 )
          << std::endl << std::flush;

      delete[ ] buffer;
    }
    treeC->delDec< String >( tree, 24 );
    tree = 0;
    std::cout << std::endl << std::flush;

    String* par = 0;
    std::cout << "key: " << key1 << "\t" << "value: " << str1 << std::endl
        << std::flush;
    par = treeC->storeBin< String >( tree, str1, key1, keySize );
    String res1 = treeC->getBin< String >( tree, key1, keySize );
    std::cout << "key: " << key1 << "\t" << "value: " << res1 << std::endl
        << std::flush;
    std::cout << std::endl << std::flush;

    std::cout << "key: " << key2 << "\t" << "value: " << str2 << std::endl
        << std::flush;
    par = treeC->storeBin< String >( tree, str2, key2, keySize );
    String res2 = treeC->getBin< String >( tree, key2, keySize );
    std::cout << "key: " << key2 << "\t" << "value: " << res2 << std::endl
        << std::flush;
    std::cout << std::endl << std::flush;

    std::cout << "key: " << key3 << "\t" << "value: " << str3 << std::endl
        << std::flush;
    par = treeC->storeBin< String >( tree, str3, key3, keySize );
    String res3 = treeC->getBin< String >( tree, key3, keySize );
    std::cout << "key: " << key3 << "\t" << "value: " << res3 << std::endl
        << std::flush;
    std::cout << std::endl << std::flush;

    std::cout << "key: " << key4 << "\t" << "value: " << str4 << std::endl
        << std::flush;
    par = treeC->storeBin< String >( tree, str4, key4, keySize );
    if( par != 0 ) {
      String sPar = *par;
      delete par;
      std::cout << "par: " << sPar << "\t" << "value: " << str4 << std::endl
          << std::flush;
    }
    //String res4 = treeC->getBin<String>( tree, key4, keySize );
    //std::cout << "key: " << key4 << "\t" << "value: " << res4 << std::endl << std::flush;
    std::cout << std::endl << std::flush;

    std::cout << "key: " << key4 << "\t" << "value: " << str4 << std::endl
        << std::flush;
    par = treeC->storeBin< String >( tree, str5, key4, keySize );
    if( par != 0 ) {
      String sPar = *par;
      delete par;
      std::cout << "par: " << sPar << "\t" << "value: " << str5 << std::endl
          << std::flush;
    }
    String res4 = treeC->getBin< String >( tree, key4, keySize );
    std::cout << "key: " << key4 << "\t" << "value: " << res4 << std::endl
        << std::flush;
    std::cout << std::endl << std::flush;

    treeC->delBin< String >( tree, keySize );

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
      treeC->storeBin< String >( tree, loadString, (Char*)keyChars, keySize );

    } // hashIndex

    for( Int16 hashIndex = 0; hashIndex < range; hashIndex++ ) {

      String hashString = HASHCC::FNC::blowZero( HASHCC::JNK::xxx_to_bin( hashIndex ),
        keySize );
      cChar* keyChars = hashString.c_str( );
      String resultString = treeC->getBin< String >( tree, (Char*)keyChars, keySize );
      // std::cout << resultString << std::endl << std::flush;

    } // hashIndex

    Char* search1 = (Char*)"0101010101010101";
    std::cout << treeC->getBin< String >( tree, search1, keySize ) << std::endl
        << std::flush;
    Char* search2 = (Char*)"0000000000000000";
    std::cout << treeC->getBin< String >( tree, search2, keySize ) << std::endl
        << std::flush;
    Char* search3 = (Char*)"1111111111111111";
    std::cout << treeC->getBin< String >( tree, search3, keySize ) << std::endl
        << std::flush;
    Char* search4 = (Char*)"1010101010101010";
    std::cout << treeC->getBin< String >( tree, search4, keySize ) << std::endl
        << std::flush;
    Char* search5 = (Char*)"0000111100001111";
    std::cout << treeC->getBin< String >( tree, search5, keySize ) << std::endl
        << std::flush;

    treeC->delBin< String >( tree, keySize );

    delete treeC;

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
