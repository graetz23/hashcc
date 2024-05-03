/**
 * @file hashccErrFailure.h
 * @author Christian (graetz23@gmail.com)
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2024 Christian (graez23@gmail.com)
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

#ifndef __hashccErrFailure_h__
#define __hashccErrFailure_h__

/******************************************************************************/

#include "./hashccErrException.h"

/******************************************************************************/

namespace HASHCC {

namespace ERR {

/******************************************************************************/

#define _DEBUG_HASHCC_ERR_Failure_

/******************************************************************************/

class /// class for marking a recoverable error
Failure : public Exception { // for failure 2 be handled
 public:

  Failure( void ); /// constructor
  Failure( std::exception e ); /// constructor
  Failure( cChar* message ); /// constructor overloaded
  Failure( String message ); /// constructor overloaded
  Failure( String message, Int16 lineNo ); /// use __LINE__ @ lineNo
  Failure( String message, Char* fileName ); /// use __FILE__ @ fileName
  Failure( String message, Char* fileName, Int16 lineNo ); /// use __FILE__ @ fileName and __LINE__ @ lineNo
  virtual ~Failure( void ); /// destructor

 protected:

  virtual void mark( void ); /// mark an exception

}; // class Failure

/******************************************************************************/

} // namespace ERR

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccErrFailure_h__
