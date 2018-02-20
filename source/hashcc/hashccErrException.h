/** 
 * @file hashccErrException.h
 * @author Christian Scheiblich
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2009-2018 Christian Scheiblich (cscheiblich@gmail.com)
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

#ifndef __hashccErrException_h__
#define __hashccErrException_h__

/******************************************************************************/

#include "./hashccTypes.h" // used typedefs in HASHCC::

/******************************************************************************/

namespace HASHCC {

namespace ERR {

/******************************************************************************/

#define _VERSION_HASHCC_ERR_Exception_ 0.15 // 20141231
#define _DEBUG_HASHCC_ERR_Exception_

/******************************************************************************/

typedef HASHCC::Char       Char; // stc namespace typedef
typedef HASHCC::cChar     cChar; // stc namespace typedef
typedef HASHCC::String   String; // stc namespace typedef

/******************************************************************************/

class /// base class for errors
Exception {
 public:

  Exception( void ); /// constructor
  Exception( std::exception e ); /// constructor
  Exception( cChar* message ); /// constructor overloaded
  Exception( String message ); /// constructor overloaded
  Exception( String message, Int16 lineNo ); /// use __LINE__ @ lineNo
  Exception( String message, Char* fileName ); /// use __FILE__ @ fileName
  Exception( String message, Char* fileName, Int16 lineNo ); /// use __FILE__ @ fileName and __LINE__ @ lineNo
  virtual ~Exception( void ); /// destructor

  String declare( void ) const; /// returns message as std::string
  void report( void ) const; /// message to console
  void stop( void ) const; /// message to console and wait for enter
  void nuke( void ) const; /// do a nuke and melt down afterwards

  friend std::ostream& operator << ( std::ostream& s, Exception& e ); /// cout
  friend std::ostream& operator << ( std::ostream& s, Exception* e ); /// cout

 protected:

  String _message; /// the generated exception message  

 private:

  virtual void mark( void ); /// mark exception

}; // class Exception

/******************************************************************************/

} // namespace ERR

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccErrException_h__
