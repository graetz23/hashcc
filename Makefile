# @file Makefile
# @author Christian Scheiblich
#
# HASHCC is distributed under the MIT License (MIT); this file is part of.
#
# Copyright (c) 2008-2017 Christian Scheiblich (cscheiblich@gmail.com)
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
# HASHCC version 0.14 20120430
#
# type to your console for a test run: 
#
#   make && cd HASHCC && ./hashcc
#

CC=g++

CFLAGS=-c -Wall

LDFLAGS=

SRC=source

EXECUTABLE=hashcc

SOURCES= \
	$(SRC)/hashcc/hashccErrException.cpp \
	$(SRC)/hashcc/hashccErrFailure.cpp \
	$(SRC)/hashcc/hashccErrError.cpp \
	$(SRC)/hashcc/hashccDmyNoob.cpp \
	$(SRC)/hashcc/hashccDmyObject.cpp \
	$(SRC)/hashcc/hashccStc.cpp \
	$(SRC)/hashcc/hashccFncNoob.cpp \
	$(SRC)/hashcc/hashccFncHash.cpp \
	$(SRC)/hashcc/hashccTypKeyTest.cpp \
	$(SRC)/hashcc/hashccTypKeyConv.cpp \
	$(SRC)/hashcc/hashccTypTree.cpp \
	$(SRC)/hashcc/hashccTypTreeLimb.cpp \
	$(SRC)/hashcc/hashccTypTreeLeaf.cpp \
	$(SRC)/hashcc/hashccTypTreeController.cpp \
	$(SRC)/hashcc/hashccObjHashMap.cpp \
	$(SRC)/hashcc/hashccObjHashMapDec.cpp \
	$(SRC)/hashcc/hashccObjHashMapDec10.cpp \
	$(SRC)/hashcc/hashccObjHashMapDec10Elf.cpp \
	$(SRC)/hashcc/hashccObjHashMapDec24.cpp \
	$(SRC)/hashcc/hashccObjHashMapDec24Fnv.cpp \
	$(SRC)/hashcc/hashccObjHashMapDec24Adler.cpp \
	$(SRC)/hashcc/hashccObjHashMapBuilder.cpp \
	$(SRC)/hashcc/hashccJnk.cpp \
	$(SRC)/hashcc/hashccJnkTest.cpp \
	$(SRC)/hashcc/hashccTest.cpp \
	$(SRC)/main.cpp

OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f ./$(EXECUTABLE) $(OBJECTS)

update:
	git pull

commit:
	git commit
	git push

refresh:
	make clean
	make update
	make
