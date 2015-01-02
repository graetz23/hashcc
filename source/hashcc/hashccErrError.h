/** 
 * @file hashccErrError.h
 * @author Christian Scheiblich
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2009-2015 Christian Scheiblich (cscheiblich@gmail.com)
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

#ifndef __hashccErrError_h__
#define __hashccErrError_h__

/******************************************************************************/

#include "./hashccErrException.h"

/******************************************************************************/

namespace HASHCC {

namespace ERR {

/******************************************************************************/

#define _VERSION_HASHCC_ERR_Error_ 0.15 // 20141231
#define _DEBUG_HASHCC_ERR_Error_

/******************************************************************************/

class /// class for marking a non recoverable error
Error : public Exception { // for real errors
 public:

  Error( void ); /// constructor
  Error( std::exception e ); /// constructor
  Error( cChar* message ); /// constructor overloaded
  Error( String message ); /// constructor overloaded
  Error( String message, Int16 lineNo ); /// use __LINE__ @ lineNo
  Error( String message, Char* fileName ); /// use __FILE__ @ fileName
  Error( String message, Char* fileName, Int16 lineNo ); /// use __FILE__ @ fileName and __LINE__ @ lineNo
  virtual ~Error( void ); /// destructor
  
 protected:

  virtual void mark( void ); /// mark an exception

}; // class Error

/******************************************************************************/

} // namespace HASHCC

} // namespace ERR

/******************************************************************************/

#endif // __hashccErrError_h__
