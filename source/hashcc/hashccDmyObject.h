/**
 * @file hashccDmyObject.h
 * @author Christian (graetz23@gmail.com)
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2018 Christian (graez23@gmail.com)
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

#ifndef __hashccDmyObject_h__
#define __hashccDmyObject_h__

/******************************************************************************/

#include "./hashccTyp.h" // HASHCC data types

/******************************************************************************/

namespace HASHCC {

namespace DMY {

/******************************************************************************/

#define _DEBUG_HASHCC_DMY_Object_

/******************************************************************************/

typedef HASHCC::String String; // namespace typedef

class /// class as pattern for following classes
Object {
 public:

  Object( void ); /// constructor
  Object( String string ); /// constructor
  virtual ~Object( void ); /// destructor

  String getString( void ); /// returns stored string
  void setString( String string ); /// stores a string

  friend std::ostream& operator << ( std::ostream& s, Object& o ); /// std::cout
  friend std::ostream& operator << ( std::ostream& s, Object* o ); /// std::cout

 protected:

   String _string;

}; // class Object

/******************************************************************************/

} // namespace DMY

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccDmyObject_h__
