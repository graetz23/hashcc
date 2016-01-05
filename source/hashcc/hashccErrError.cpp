/** 
 * @file hashccErrError.cpp
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

#include "./hashccErrError.h"

/******************************************************************************/

namespace HASHCC {

namespace ERR {

/******************************************************************************/

Error::Error( void ) : Exception( ) {
} // Error

Error::Error( std::exception e ) : Exception( e ) {
} // Error

Error::Error( cChar* message ) : Exception( message ) {
} // Error

Error::Error( String message ) : Exception( message ) {
} // Error

Error::Error( String message, Int16 lineNo ) : Exception( message, lineNo ) {
} // Error

Error::Error( String message, Char* fileName ) : Exception( message, fileName ) {
} // Error

Error::Error( String message, Char* fileName, Int16 lineNo ) : Exception( message, fileName, lineNo ) {
} // Error

Error::~Error( void ) {
} // ~Error

/******************************************************************************/

void /// mark exception
Error::mark( void ) {
  String tmp = "HASHCC::ERR::Error - ";
  tmp.append( _message );
  _message = tmp;
} // Error::mark

/******************************************************************************/

} // namespace ERR

} // namespace HASHCC

/******************************************************************************/
