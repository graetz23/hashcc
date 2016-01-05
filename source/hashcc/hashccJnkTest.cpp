/** 
 * @file hashccJnkTest.cpp
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

#include "./hashccJnkTest.h" // header

/******************************************************************************/

namespace HASHCC {

namespace JNK {

/******************************************************************************/

void /// tests the TreeController and the Tree
test( void ) {
  
  try {

    for( Int16 i = 0; i < 8; i++ ) {
      std::cout << i << " decimal == " << HASHCC::FNC::blowZero( HASHCC::JNK::xxx_to_bin( i ), 8 ) 
                << " binary" << std::endl << std::flush;;
    }
    std::cout << std::endl << std::flush;

  } catch( ERR::Failure f ) {
    std::cout << "HASHCC::ERR::Failure:" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
    f.report( );
  } catch( ERR::Error e ) {
    std::cout << "HASHCC::ERR::Error:" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
    e.report( );
  } catch( ERR::Exception e ) {
    std::cout << "HASHCC::ERR::Exception:" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
    e.report( );
  } catch( std::exception e ) {
    std::cout << "std::exception:" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
    std::cout << e.what( ) << std::endl << std::flush;
  } catch( ... ) {
    std::cout << "unknown exception" << std::endl << std::flush;
    std::cout << std::endl << std::flush;
  } // try

} // testTreeController

/******************************************************************************/

} // namespace JNK

} // namespace HASHCC

/******************************************************************************/
