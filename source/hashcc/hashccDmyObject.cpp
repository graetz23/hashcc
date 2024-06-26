/** 
 * @file hashccDmyObject.cpp
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

#include "./hashccDmyObject.h" // header

/******************************************************************************/

namespace HASHCC {

namespace DMY {

/******************************************************************************/
  
/// constructor
Object::Object( void ) {
  _string = "null";
} // Object

/// constructor
Object::Object( String string ) {
  _string = string;
} // Object

/// destructor
Object::~Object( void ) {
} // ~Object

/******************************************************************************/

String /// returns stored string
Object::getString( void ) {
  return _string;
} // Object::getString

void /// stores a string
Object::setString( String string ) {
  _string = string;
} // Object::setString

/******************************************************************************/

std::ostream& // for std::cout
operator << ( std::ostream& s, Object& o ) {
  s << o._string << std::endl << std::flush;
  return s;
} // Exception::operator << 

std::ostream& // for std::cout
operator << ( std::ostream& s, Object* o ) {
  s << o->_string << std::endl << std::flush;
  return s;
} // Exception::operator << 

/******************************************************************************/
} // namespace DMY

} // namespace HASHCC

/******************************************************************************/
