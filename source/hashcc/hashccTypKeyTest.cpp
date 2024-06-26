/** 
 * @file hashccTypKeyTest.cpp
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

#include "./hashccTypKeyTest.h" // header

/******************************************************************************/

namespace HASHCC {

namespace TYP {

/******************************************************************************/

template< > void // key okay; no exception thrown
keyTest< Char >( void ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< Char* >( void ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< String >( void ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< Int16 >( void ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< Int32 >( void ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< Int64 >( void ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< uInt16 >( void ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest<uInt32>( void ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< uInt64 >( void ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< Char >( String f ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< Char* >( String f ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< String >( String f ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< Int16 >( String f ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< Int32 >( String f ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< Int64 >( String f ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< uInt16 >( String f ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< uInt32 >( String f ) {
} // keyTest

template< > void // key okay; no exception thrown
keyTest< uInt64 >( String f ) {
} // keyTest

/******************************************************************************/

} // namespace TYP

} // namespace HASHCC

/******************************************************************************/
