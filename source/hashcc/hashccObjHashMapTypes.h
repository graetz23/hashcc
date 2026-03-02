/**
 * @file hashccObjHashMapTypes.h
 * @brief Hash map type enumerations
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
 * @defgroup OBJTypes Hash Map Types
 * @brief Enumerations for hash map types.
 * @ingroup OBJ
 *
 * Defines the available hash map implementations:
 * @li Dec10Elf - 10-digit decimal ELF hash
 * @li Dec24Adler - 24-digit decimal Adler hash
 * @li Dec24Fnv - 24-digit decimal FNV hash
 */

#ifndef __hashccObjHashMapTypes_h__
#define __hashccObjHashMapTypes_h__

/******************************************************************************/

namespace HASHCC {

namespace OBJ {

/******************************************************************************/

#define _DEBUG_HASHCC_OBJ_HashMapType_

/******************************************************************************/

namespace Type {

/******************************************************************************/

/**
 * @enum HASHCC::OBJ::Type::HashMap
 * @brief Hash map type enumeration
 * @ingroup OBJ
 */
enum HashMap {
  Dec10Elf,   /**< @brief 10-digit decimal ELF hash */
  Dec24Adler, /**< @brief 24-digit decimal Adler hash */
  Dec24Fnv    /**< @brief 24-digit decimal FNV hash */
}; // enum HashMap

/******************************************************************************/

} // namespace Type

/******************************************************************************/

} // namespace OBJ

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccObjHashMapTypes_h__
