/**
 * @file hashccErrFailure.h
 * @brief Recoverable failure exception class
 * @author Christian (graetz23@gmail.com)
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2026 Christian (graez23@gmail.com)
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
 *
 * @class HASHCC::ERR::Failure
 * @brief Recoverable failure exception.
 * @ingroup ERR
 *
 * This exception class represents recoverable failures that can be
 * handled by the caller. It inherits from Exception.
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

/**
 * @class HASHCC::ERR::Failure
 * @brief Recoverable failure exception.
 * @ingroup ERR
 *
 * This exception class represents recoverable failures that can be
 * handled by the caller. It inherits from Exception.
 */
class /// class for marking a recoverable error
Failure : public Exception { // for failure 2 be handled
 public:

  /** @brief Default constructor */
  Failure( void ); 
  /** @brief Construct from std::exception */
  Failure( std::exception e ); 
  /** @brief Construct with C-string message */
  Failure( cChar* message ); 
  /** @brief Construct with String message */
  Failure( String message ); 
  /** @brief Construct with message and line number */
  Failure( String message, Int16 lineNo ); 
  /** @brief Construct with message and filename */
  Failure( String message, Char* fileName ); 
  /** @brief Construct with message, filename and line number */
  Failure( String message, Char* fileName, Int16 lineNo ); 
  /** @brief Destructor */
  virtual ~Failure( void ); 

 protected:

  /** @brief Marks the exception */
  virtual void mark( void ); 

}; // class Failure

/******************************************************************************/

} // namespace ERR

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccErrFailure_h__
