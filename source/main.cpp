/**
 * @file main.cpp
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

#ifndef __cplusplus
#error compiler is not a C++ one
#endif

/******************************************************************************/

#include "./hashcc/hashcc.h" // HASHCC::

/******************************************************************************/

int // main
main( int argc, char** argv ) {

  argc = 0;            // due 2 W4 - MSVS annoys me if not used
  argv = 0;            // due 2 W4 - MSVS annoys me if not used

  try { // try everything ~8>

    std::cout << "HASHCC::" << std::endl << std::flush;

    std::cout << "package" << " " << _HASHCC_PACKAGE_ << std::endl
        << std::flush;

    std::cout << "version" << " " << _HASHCC_VERSION_NO_ << " "
        << _HASHCC_VERSION_DATE_ << std::endl << std::flush;

    std::cout << "built  " << " " << _HASHCC_BUILT_DATE_ << " "
        << _HASHCC_BUILT_TIME_ << std::endl << std::flush;

    std::cout << std::endl << std::flush;

    // /// //// HASHCC::TEST //// /// //
    HASHCC::TEST::testStc( );
    std::cout << std::endl << std::flush;

    // /// //// HASHCC::TEST //// /// //
    std::cout << "testing hashes ... " << std::flush;
    HASHCC::TEST::testHash( );
    std::cout << "done" << std::endl << std::flush;
    std::cout << std::endl << std::flush;

    // /// //// HASHCC::TEST //// /// //
    // HASHCC::TEST::testHashMap( HASHCC::OBJ::Type::Dec10Elf );
    // std::cout << std::endl << std::flush;

    // /// //// HASHCC::TEST //// /// //
    // HASHCC::TEST::testHashMap( HASHCC::OBJ::Type::Dec24Adler );
    // std::cout << std::endl << std::flush;

    // /// //// HASHCC::TEST //// /// //
    HASHCC::TEST::testHashMap( HASHCC::OBJ::Type::Dec24Fnv );
    std::cout << std::endl << std::flush;

    // /// //// HASHCC::TEST //// /// //
    // HASHCC::TEST::test( );
    // std::cout << std::endl << std::flush;

    std::cout << "done" << std::endl << std::flush;

  }                    // HASHCC exception class
  catch( HASHCC::ERR::Exception& e ) {
    e.report( );       // break it down
  }                    // standard exception class
  catch( std::exception& e ) {
    std::cout << "std::exception caught:" << std::endl << std::flush;
    std::cout << e.what( ) << std::endl << std::flush;
  }                    // any other exception thrown
  catch( ... ) {
    std::cout << "Strange exception caught:" << std::endl << std::flush;
  } // try

  return 0;

} // main

/****************************************************************************/
