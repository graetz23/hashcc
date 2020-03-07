## HASHCC

### C++ hash map library

[![Build Status](https://travis-ci.org/cscheiblich/hashcc.svg?branch=master)](https://travis-ci.org/cscheiblich/hashcc) on travis-ci.com

### Introduction

**HASHCC is an object-oiented C++ hash map library** based on C++ templates classes. By pushing some key, object tuple into it, **it builds a tree structure**. The tree gets **as deep as the length and as wide as varitey of symbols of the hash**. **The necessary hash** to build up each path to some pushed object, **can be exchanged**. **By default hashCC uses** the *adler* hash function to generate a length of 24 and 10 defferent symbols {0-9}; the build tree builds up **a space of dimension 24^10**. = 1000 0000 0000 0000 0000 0000 possibilities. However this is strongly dependent on the collision freeness of the hash function, its collision quality, respectively **.. have fun.**

### Notes

I adapted this hashmap library in 2007 from Java's HashMap< Key, Object >( ) class, comeing around as System's library. However, I brainstormed the internal by myself and the implementation insisde this library is more like **[a Trie, a hash tree)(https://en.wikipedia.org/wiki/Trie)**, respectively.

### Getting Started

For getting started with hashCC have a look at [the (unit) test file](https://github.com/cscheiblich/hashcc/blob/master/source/hashcc/hashccTest.cpp#L173) (line 323= that is available.

Using some unix or GNU/Linux, try:
**git clone https://github.com/cscheiblich/hashcc.git && cd hashcc && make**

### License ###

**HASHCC is distributed under the MIT License (MIT); this file is part of.**

**Copyright (c) 2008-2020 Christian (graetz23@gmail.com)**

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

### Version ###

**HASHCC Version 0.16 20160215**

### Change Log ###

201XXXXX version 0. :
- changing copyright and contact to new email address,
- updated readme file

20160106 version 0.16 :
- updated years of the Copyright to 2009-2018

20141231 version 0.15 :
- changed to the MIT License (MIT)
- pushed to https://github.com/cscheiblich/hashcc for development

20120430 version 0.14 :
- updated copyright towards 2012
- removed old email address

20100727 version 0.13 :
- added HashMap object Dec24Adler for testing the adler hashing function
- added HashMap object Dec10Elf for testing the ELF hashing function
- created namespace JNK:: as a source junkyard and for testing stuff
- created namespace DMY:: for having dummy objects for testing stuff
- add comments to several files for explanation
- moved the defines for compiler to the right place
- created second Microsoft Visual Studio 2005 project called 'Example' keeping
  the main.cpp with several tests
- changed main project to be compiled to a static .lib file and then linked

20100116 version 0.12 :
- changed indention of main
- new release, due to CHAR_BIT bug for g++ compiler
- fixed conversion bugs

20091021 version 0.11 :
- renamed hashccTypeDefs.h to hashccTypes.h and moved to root dir in MS VS project solution
- supporting release as tar.gz file

20091014 version 0.10 :
- rebuild namespace HASHCC::TEST::
 - moved functions there
 - splitted the common test function
- splitted file hashccTypConvert.h of HASHCC::TYP::
 - one file keeps the tests for a valid key
 - one file keeps the converting functions for the key
- splitted file hashccTypTree.h of HASHCC::TYP::
 - one file for base struct; kept name
 - one file for limbs; hashccTypLimb.{h,cpp}
 - one file for leaves; hashccTypLeaf.{h,cpp}
- fixed bug in HASHCC::STC:: set Aph was not of size 36; 26 before
- reordered main method
- reordered test for HashMap and added a enum to test different HashMaps
- rebuild Makefile
- debugged false hashing on linux using GNU/g++; type conversion failed
- template HashMap<K,V> is working
 - key type is checked; keys are alle numerical and character types
 - builder class casts HashMap<K,V> object to base class
 - HashMap is using a decimal key set; [0-9]
 - Hash symbols are between 16 to 22 symbols for an hash;
 - various hash lengths are blown to 24 symbols
 - Tree depth is 24 symbols which allows for storing 10^24 for a perfect hash
   (kidding ~8>)
- tested the HashMapDec24Fnv on following plattforms:
 - MS Windows Vista 32 bit MS VisualStudio 2005 8.0
 - GNU/linux red hat, kernel 2.6.23.15 and GNU/g++ 4.1.2
 - GNU/linux ubuntu, kernel 2.6.24 and GNU/g++ 4.2.4
- package is available from the tags directory as version 0.10 Deeann Lampel

20091013 version 0.08 :
- implemented HashMapDec24Fnv<K,V> class
 - added hashing function with a lot of conversions form char* to string
 - put function is working
 - get function is working
 - size function not tested yet; but that easy should work
 - set up test function for HashMap storing strings by different keys:
  - keys are: String, Int16, Int32, Int64, uInt16, uInt32, uInt64
  - added function to check to key to types above, if not exception is thrown
 - delete function is working to delete the tree
- added template function and its spezializations to convert the key types
- added builder class for building the correct HashMap by enum
 - specialized to the used hash
 - specialized to the used key width
- removed unnecessary objects Hash and HashBin form HASHCC::OBJ::
- implemented several test for different keys and for storing 10k objetcs

20091012 version 0.07 :
- added template class HashMap< K, V >
 - added class HashMapDec< k, V > for hashes of decimal characters
 - added class HashMap24Fnv< K, V > for hashes of size 24 using FNV hashing func
 - added functions:
  - added size( ); returns no of stored objects or values
  - added V get( K ); returns a value or an object if stored
  - added V put( K, V ); return null and stores object / value or returns a
    pointer to an object / a value if the hash used is already accoupied, in
    case the the new objects replaces the old one; do not forget to delete
    the pointer

20091011 version 0.06 :
- cleaned code
 - comments are removed
 - files are renamed
- added function for hashs of decimal symbols [0-9]
 - test for hashes of size 24 yet; allows for storing 24^10 objects

20091010 version 0.05 :
- added hash functions
 - added adler32 hash for decimal hashing
 - added fnv hash function for decimal hahshing
- extended storeBin<T> function by a return type for collision detection
 - if a hash is already used the stored object is encapsulated and returned
 - the new object is stored for that hash
 - one has to delete the returned pointer

20091008 version 0.04 :
- added first load test function for binary hashing;
 - size of key set to 16 bits so 2^16 elements can be stored
 - 2^16 fetches took on Intel Atom 1.6 GHz about 2 secs
 - memory is about 11.0  MByte for storing empty Strings (std::string( "" );)
 - memory is about 16.0  MByte for storing Strings of   16 letters
 - memory is about 16.0  MByte for storing Strings of   32 letters
 - memory is about 18.4  MByte for storing Strings of   64 letters
 - memory is about 22.5  MByte for storing Strings of  128 letters
 - memory is about 30.6  MByte for storing Strings of  256 letters
 - memory is about 46.6  MByte for storing Strings of  512 letters
 - memory is about 79.4  MByte for storing Strings of 1024 letters
 - memory is about 144.9 MByte for storing Strings of 2048 letters
 - memory is about 275.3 MByte for storing Strings of 4096 letters

20091007 version 0.03 :
- changed tree struct to class yet, due to errors by dynamic_cast<T> function
 - but already removed dynamic_cast<T> cause not working like this; design error
- added TreeController class
 - added template function for binary hash storage
 - added template function for binary hash restore
 - added delete function for automatically deleting binary tree
- added TreeControllerTest class
 - added test for running a storage
 - added test for running a restore of stored data
 - added test for deleting the tree
- Yet there is no design for collision handling
- Yet if a key is used twice storeage goes wrong
- At all first values can be hashed by a unique binary hash of any size

20090927 version 0.02 :
- added namespace FNC::
 - added struct Noob as pattern for other files in namespace
 - should be later used for global functions and/or static functions
- added namespace OBJ::
 - added class Noob as pattern for other files in namespace
 - should be used for objects like search classes or stuff
- added namespace STC::
 - added header files for including all types of HASHCC
 - added struct Tree as base struct for a multi dimensional tree
 - added struct TreeLimb as limbs of the Tree storing other limbs
 - added struct TreeLeaf as end limb of the Tree for storing an object pointer
 - added static char list for having look up tables for later hash functions
 - should be used for static stuff that is in memory after running the lib
- added namespace ERR::
 - added class Exception as base class for exceptions
 - added class Failure to mark recoverable exceptions
 - added class Error to mark non-recoverable exceptions
 - extended class' constructors for taking std::exception class
- reorderd the includes in each files
- extended and rehacked Makefile
- fixed bug in template programming, that is not checked by MSVS 2005 compiler

20090926 version 0.01 :
- created Microsoft Visual Studio 2005 Project
 - added main.cpp
 - added hashcc/hashcc.h
- added Makefile for GNU/Make

/******************************************************************************/
