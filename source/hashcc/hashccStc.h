/**
 * @file hashccStc.h
 * @author Christian (graetz23@gmail.com)
 *
 * HASHCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2025 Christian (graez23@gmail.com)
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

#ifndef __hashccStc_h__
#define __hashccStc_h__

/******************************************************************************/

#include "./hashccTypes.h" // used typedefs in HASHCC::

/******************************************************************************/

namespace HASHCC {

namespace STC {

/******************************************************************************/

#define _DEBUG_HASHCC_STC_

/******************************************************************************/

typedef HASHCC::Char       Char; // stc namespace typedef
typedef HASHCC::uChar     uChar; // stc namespace typedef
typedef HASHCC::cChar     cChar; // stc namespace typedef
typedef HASHCC::cuChar   cuChar; // stc namespace typedef
typedef HASHCC::String   String; // stc namespace typedef

/******************************************************************************/

struct Bin { /// binary Char set
  static cChar val[ 2 ];
  static cuChar size;
}; // struct Bin

/******************************************************************************/

struct Qud { /// quadruple char set
  static cChar val[ 4 ];
  static cuChar size;
}; // struct Qud

/******************************************************************************/

struct Oct { /// octal char set
  static cChar val[ 8 ];
  static cuChar size;
}; // struct Oct

/******************************************************************************/

struct Dec { /// decimal char set
  static cChar val[ 10 ];
  static cuChar size;
}; // struct Dec

/******************************************************************************/

struct Hex { /// hexadecimal char set
  static cChar val[ 16 ];
  static cuChar size;
}; // struct Hex

/******************************************************************************/

struct Abc { /// alphabetically char set
  static cChar val[ 26 ];
  static cuChar size;
}; // struct Abc

/******************************************************************************/

struct Aph { /// alpha numerical char set
  static cChar val[ 36 ];
  static cuChar size;
}; // struct Abc

/******************************************************************************/

} // namespace STC

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccStc_h__
