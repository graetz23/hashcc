/**
 * @file hashccErrException.h
 * @brief Base exception class for HASHCC
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
 * @class HASHCC::ERR::Exception
 * @brief Base exception class for all HASHCC exceptions.
 * @ingroup ERR
 *
 * This is the base class for all exceptions in the HASHCC library.
 * It provides basic exception handling functionality including
 * message storage, reporting, and error output.
 */

#ifndef __hashccErrException_h__
#define __hashccErrException_h__

/******************************************************************************/

#include "./hashccTypes.h" // used typedefs in HASHCC::

/******************************************************************************/

namespace HASHCC {

namespace ERR {

/******************************************************************************/

#define _DEBUG_HASHCC_ERR_Exception_

/******************************************************************************/

/**
 * @defgroup CharTypes Character Types
 * @brief Character type definitions for ERR namespace
 */

/** @brief Character type @ingroup CharTypes */
typedef HASHCC::Char       Char; // stc namespace typedef
/** @brief Constant character type @ingroup CharTypes */
typedef HASHCC::cChar     cChar; // stc namespace typedef
/** @brief String type @ingroup CharTypes */
typedef HASHCC::String   String; // stc namespace typedef

/******************************************************************************/

/**
 * @class HASHCC::ERR::Exception
 * @brief Base exception class for all HASHCC exceptions.
 * @ingroup ERR
 *
 * This is the base class for all exceptions in the HASHCC library.
 * It provides basic exception handling functionality including
 * message storage, reporting, and error output.
 */
class /// base class for errors
Exception {
 public:

  /** @brief Default constructor */
  Exception( void ); 
  /** @brief Construct from std::exception */
  Exception( std::exception stdException ); 
  /** @brief Construct with C-string message */
  Exception( cChar* message ); 
  /** @brief Construct with String message */
  Exception( String message ); 
  /** @brief Construct with message and line number */
  Exception( String message, Int16 lineNo ); 
  /** @brief Construct with message and filename */
  Exception( String message, Char* fileName ); 
  /** @brief Construct with message, filename and line number */
  Exception( String message, Char* fileName, Int16 lineNo ); 
  /** @brief Destructor */
  virtual ~Exception( void ); 

  /** @brief Returns the exception message as std::string */
  String declare( void ) const; 
  /** @brief Reports the exception message to console */
  void report( void ) const; 
  /** @brief Reports to console and waits for user input */
  void stop( void ) const; 
  /** @brief Reports and terminates the program */
  void nuke( void ) const; 

  /** @brief Stream output operator */
  friend std::ostream& operator << ( std::ostream& outputStream, Exception& exception ); 
  /** @brief Stream output operator for pointer */
  friend std::ostream& operator << ( std::ostream& outputStream, Exception* exception ); 

 protected:

  /** @brief The exception message */
  String _message; 

 private:

  /** @brief Marks the exception (internal use) */
  virtual void mark( void ); 

}; // class Exception

/******************************************************************************/

} // namespace ERR

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccErrException_h__
