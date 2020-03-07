/** 
 * @file hashccTypKeyConv.cpp
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

#include "./hashccTypKeyConv.h" // header

/******************************************************************************/

namespace HASHCC {

namespace TYP {

/******************************************************************************/

template< > String // converts a char key to String
keyConv< Char >( Char key ) {
  String s;
  std::stringstream stream;
  stream << key;
  stream >> s;
  return s;
} // keyConv

template< > String // converts chars key to String
keyConv< Char* >( Char* key ) {
  String s;
  std::stringstream stream;
  stream << key;
  stream >> s;
  return s;
} // keyConv

template< > String // converts string key to String
keyConv< String >( String key ) {
  return key; // just return if of same type
} // keyConv

template< > String // convert a Int16 key to String
keyConv< Int16 >( Int16 key ) {
  String s;
  std::stringstream stream;
  stream << key;
  stream >> s;
  return s;
} // keyConv

template< > String // convert a Int32 key to String
keyConv< Int32 >( Int32 key ) {
  String s;
  std::stringstream stream;
  stream << key;
  stream >> s;
  return s;
} // keyConv

template< > String // convert a Int64 key to String
keyConv< Int64 >( Int64 key ) {
  String s;
  std::stringstream stream;
  stream << key;
  stream >> s;
  return s;
} // keyConv

template< > String // convert a uInt16 key to String
keyConv< uInt16 >( uInt16 key ) {
  String s;
  std::stringstream stream;
  stream << key;
  stream >> s;
  return s;
} // keyConv

template< > String // convert a uInt32 key to String
keyConv< uInt32 >( uInt32 key ) {
  String s;
  std::stringstream stream;
  stream << key;
  stream >> s;
  return s;
} // keyConv

template< > String // convert a uInt64 key to String
keyConv< uInt64 >( uInt64 key ) {
  String s;
  std::stringstream stream;
  stream << key;
  stream >> s;
  return s;
} // keyConv

/******************************************************************************/

} // namespace TYP

} // namespace HASHCC

/******************************************************************************/
