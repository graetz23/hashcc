/**
 * @file hashccErrError.h
 * @brief Non-recoverable error exception class
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
 * @class HASHCC::ERR::Error
 * @brief Non-recoverable error exception.
 * @ingroup ERR
 *
 * This exception class represents non-recoverable errors that should
 * cause the program to terminate. It inherits from Exception.
 */

#ifndef __hashccErrError_h__
#define __hashccErrError_h__

/******************************************************************************/

#include "./hashccErrException.h"

/******************************************************************************/

namespace HASHCC {

namespace ERR {

/******************************************************************************/

#define _DEBUG_HASHCC_ERR_Error_

/******************************************************************************/

/**
 * @class HASHCC::ERR::Error
 * @brief Non-recoverable error exception.
 * @ingroup ERR
 *
 * This exception class represents non-recoverable errors that should
 * cause the program to terminate. It inherits from Exception.
 */
class /// class for marking a non recoverable error
Error : public Exception { // for real errors
 public:

  /** @brief Default constructor */
  Error( void ); 
  /** @brief Construct from std::exception */
  Error( std::exception e ); 
  /** @brief Construct with C-string message */
  Error( cChar* message ); 
  /** @brief Construct with String message */
  Error( String message ); 
  /** @brief Construct with message and line number */
  Error( String message, Int16 lineNo ); 
  /** @brief Construct with message and filename */
  Error( String message, Char* fileName ); 
  /** @brief Construct with message, filename and line number */
  Error( String message, Char* fileName, Int16 lineNo ); 
  /** @brief Destructor */
  virtual ~Error( void ); 

 protected:

  /** @brief Marks the exception */
  virtual void mark( void ); 

}; // class Error

/******************************************************************************/

} // namespace HASHCC

} // namespace ERR

/******************************************************************************/

#endif // __hashccErrError_h__
