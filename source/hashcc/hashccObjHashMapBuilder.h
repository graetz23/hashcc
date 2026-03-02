/**
 * @file hashccObjHashMapBuilder.h
 * @brief Builder class for creating hash map instances
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
 * @class HASHCC::OBJ::HashMapBuilder
 * @brief Builder for creating hash map instances.
 * @ingroup OBJ
 *
 * Use this class to create hash map instances with different
 * hash function strategies.
 */

#ifndef __hashccObjHashMapBuilder_h__
#define __hashccObjHashMapBuilder_h__

/******************************************************************************/

#include "./hashccObjHashMapTypes.h" // HASHCC::OBJ::HashMapTypes
#include "./hashccObjHashMapDec10Elf.h" // HASHCC::OBJ::HashMapDec10Elf
#include "./hashccObjHashMapDec24Adler.h" // HASHCC::OBJ::HashMapDec24Adler
#include "./hashccObjHashMapDec24Fnv.h" // HASHCC::OBJ::HashMapDec24Fnv

/******************************************************************************/

namespace HASHCC {

namespace OBJ {

/******************************************************************************/

#define _DEBUG_HASHCC_OBJ_HashMapBuilder_

/**
 * @class HASHCC::OBJ::HashMapBuilder
 * @brief Builder for creating hash map instances.
 * @ingroup OBJ
 */
class HashMapBuilder {
 public:

  /** @brief Default constructor */
  HashMapBuilder( void );
  /** @brief Destructor */
  virtual ~HashMapBuilder( void );

  /** @brief Create a hash map of the specified type */
  template< typename K, typename V > HashMap< K, V >*
  create( Type::HashMap hashMapType );

}; // class HashMapBuilder

/******************************************************************************/

template< typename K, typename V > HashMap< K, V >*
HashMapBuilder::create( Type::HashMap hashMapType ) {

  TYP::keyTest<K>( "HashMapBuilder::create" ); // throws Error if key not vaild

  HashMap< K, V >* hashMap = 0;

  switch( hashMapType ) {
    case Type::Dec10Elf :
      hashMap = new HashMapDec10Elf< K, V >( );
    break;
    case Type::Dec24Adler :
      hashMap = new HashMapDec24Adler< K, V >( );
    break;
    case Type::Dec24Fnv :
      hashMap = new HashMapDec24Fnv< K, V >( );
    break;
    default:
      throw ERR::Failure( "OBJ::HashMapBuilder - unknown type of HashMap" );
    break;
  } // switch

  return hashMap;

} // HashMapBuilder::create

/******************************************************************************/

} // namespace OBJ

} // namespace HASHCC

/******************************************************************************/

#endif // __hashccObjHashMapBuilder_h__
