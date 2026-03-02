# HASHCC - Template-based C++ Hash Map Library

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Overview

**HASHCC** is an object-oriented C++ hash map library based on C++ templates. It implements a [trie-like hash tree](https://en.wikipedia.org/wiki/Trie) data structure, providing efficient key-value storage with customizable hash functions.

When you push a key/object tuple into the HashMap, it builds a tree structure where:
- **Depth** equals the length of the hash
- **Width** equals the variety of hash symbols

The library supports multiple hash functions:
- **FNV** (Fowler-Noll-Vo) - 24-character decimal hash
- **Adler** - 24-character decimal hash
- **ELF** - 10-character decimal hash

This creates a massive address space (e.g., 24^10 = possible combinations) for storing objects with minimal collisions.

## Features

- Template-based generic key-value storage
- Multiple hash functions (FNV, Adler, ELF)
- Support for various key types: String, Int16, Int32, Int64, uInt16, uInt32, uInt64
- Trie-like internal tree structure for efficient storage
- Comprehensive unit tests with [Catch2](https://github.com/catchorg/Catch2)
- Performance benchmarking capabilities
- MIT Licensed

## Prerequisites

- CMake 3.10+
- Ninja build system
- C++11 compatible compiler (GCC, Clang, MSVC)

## Building

### Clone the Repository

```bash
git clone https://github.com/graetz23/hashcc.git
cd hashcc
```

### Configure and Build

```bash
mkdir -p build
cd build
cmake -G Ninja ..
ninja
```

This will create two executables:
- `./build/hashcc` - Main application
- `./build/hashcc-test` - Unit and performance tests

## Running Tests

### All Tests (Unit + Performance)

```bash
./build/hashcc-test
```

### Unit Tests Only

```bash
./build/hashcc-test "~[perf]"
```

### Performance Tests Only

```bash
./build/hashcc-test "[perf]"
```

## Benchmark Results

Tests were run on the following workstation:

| Component | Specification |
|-----------|---------------|
| **CPU** | Intel Xeon E5-2680 v4 @ 2.40GHz |
| **Cores** | 14 cores / 28 threads |
| **RAM** | 62 GB |
| **OS** | Linux |

### Unit Test Results

```
All tests passed (1,000,170 assertions in 36 test cases)
```

### Performance Benchmarks

| Operation | Entries | Time (ms) |
|-----------|---------|-----------|
| **Insert** | 1,000,000 | ~3,400 ms |
| **Insert** | 2,000,000 | ~6,300 ms |
| **Insert** | 4,000,000 | ~13,000 ms |
| **Insert** | 8,000,000 | ~27,000 ms |
| **Retrieve** | 1,000,000 | ~2,800 ms |
| **Retrieve** | 2,000,000 | ~5,900 ms |
| **Retrieve** | 4,000,000 | ~12,000 ms |
| **Retrieve** | 8,000,000 | ~25,000 ms |

*Note: Performance results may vary based on hardware and system load.*

## Usage Example

```cpp
#include "hashcc/hashcc.h"

using namespace HASHCC;

int main() {
    // Create a HashMap with FNV hash
    OBJ::HashMapBuilder builder;
    OBJ::HashMap<Int32, String>* map = builder.create<Int32, String>(OBJ::Type::Dec24Fnv);

    // Put values
    map->put(1, "first");
    map->put(2, "second");

    // Get values
    String value = map->get(1);  // returns "first"

    delete map;
    return 0;
}
```

## Author

**Christian** (graetz23@gmail.com)

## License

HASHCC is distributed under the MIT License. See the [LICENSE](LICENSE) file for full details.

---

**Copyright (c) 2008-2026 Christian (graetz23@gmail.com)**
