#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <string>
#include <sstream>
#include <chrono>

#include "./hashccTyp.h"
#include "./hashccFnc.h"
#include "./hashccObj.h"
#include "./hashccDmy.h"
#include "./hashccJnk.h"
#include "./hashccStc.h"

using namespace HASHCC;

TEST_CASE("FNV hash produces consistent output", "[hash][fnv]") {
  String key = "myKey";
  String convertedKey = TYP::keyConv<String>(key);
  String hash = FNC::fnv24_16(convertedKey);

  REQUIRE(hash.length() == 24);
  REQUIRE(hash == "000000000000000354901002");
}

TEST_CASE("Adler hash produces consistent output", "[hash][adler]") {
  String key = "myKey";
  String convertedKey = TYP::keyConv<String>(key);
  String hash = FNC::adler24_16(convertedKey);

  REQUIRE(hash.length() == 24);
  REQUIRE(hash == "000000000000000103678480");
}

TEST_CASE("ELF hash produces consistent output", "[hash][elf]") {
  String key = "myKey";
  String convertedKey = TYP::keyConv<String>(key);
  String hash = FNC::elf10_32(convertedKey);

  REQUIRE(hash.length() == 10);
}

TEST_CASE("Empty string hash", "[hash][edge]") {
  String key = "";
  String convertedKey = TYP::keyConv<String>(key);
  String fnvHash = FNC::fnv24_16(convertedKey);
  String adlerHash = FNC::adler24_16(convertedKey);

  REQUIRE(fnvHash.length() == 24);
  REQUIRE(adlerHash.length() == 24);
}

TEST_CASE("Hash different string keys produce different hashes", "[hash]") {
  String key1 = "hello";
  String key2 = "world";
  String key3 = "test";

  String hash1 = FNC::fnv24_16(TYP::keyConv<String>(key1));
  String hash2 = FNC::fnv24_16(TYP::keyConv<String>(key2));
  String hash3 = FNC::fnv24_16(TYP::keyConv<String>(key3));

  REQUIRE(hash1 != hash2);
  REQUIRE(hash2 != hash3);
  REQUIRE(hash1 != hash3);
}

TEST_CASE("Hash long string", "[hash][edge]") {
  String key(1000, 'a');
  String hash = FNC::fnv24_16(TYP::keyConv<String>(key));
  REQUIRE(hash.length() == 24);
}

TEST_CASE("Hash numeric keys - Int16", "[hash][numeric]") {
  Int16 key = 42;
  String hash = FNC::fnv24_16(TYP::keyConv<Int16>(key));
  REQUIRE(hash.length() == 24);
}

TEST_CASE("Hash numeric keys - Int32", "[hash][numeric]") {
  Int32 key = 100000;
  String hash = FNC::fnv24_16(TYP::keyConv<Int32>(key));
  REQUIRE(hash.length() == 24);
}

TEST_CASE("Hash numeric keys - Int64", "[hash][numeric]") {
  Int64 key = 10000000000LL;
  String hash = FNC::fnv24_16(TYP::keyConv<Int64>(key));
  REQUIRE(hash.length() == 24);
}

TEST_CASE("HashMap put and get - Int16 key, Int16 value", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int16, Int16>* map = builder.create<Int16, Int16>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<Int16>(1), static_cast<Int16>(100));
  REQUIRE(map->get(static_cast<Int16>(1)) == 100);

  map->put(static_cast<Int16>(2), static_cast<Int16>(200));
  REQUIRE(map->get(static_cast<Int16>(2)) == 200);

  delete map;
}

TEST_CASE("HashMap put and get - Int16 key with String value", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int16, String>* map = builder.create<Int16, String>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<Int16>(42), "the answer");
  REQUIRE(map->get(static_cast<Int16>(42)) == "the answer");

  delete map;
}

TEST_CASE("HashMap put and get - Int32 key with String value", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int32, String>* map = builder.create<Int32, String>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<Int32>(1000), "thousand");
  REQUIRE(map->get(static_cast<Int32>(1000)) == "thousand");

  delete map;
}

TEST_CASE("HashMap put and get - Int64 key with String value", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int64, String>* map = builder.create<Int64, String>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<Int64>(100000), "hundred thousand");
  REQUIRE(map->get(static_cast<Int64>(100000)) == "hundred thousand");

  delete map;
}

TEST_CASE("HashMap put and get - uInt16 key", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<uInt16, String>* map = builder.create<uInt16, String>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<uInt16>(100), "hundred");
  REQUIRE(map->get(static_cast<uInt16>(100)) == "hundred");

  delete map;
}

TEST_CASE("HashMap put and get - uInt32 key", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<uInt32, String>* map = builder.create<uInt32, String>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<uInt32>(1000000), "million");
  REQUIRE(map->get(static_cast<uInt32>(1000000)) == "million");

  delete map;
}

TEST_CASE("HashMap put and get - uInt64 key", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<uInt64, String>* map = builder.create<uInt64, String>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<uInt64>(10000000000ULL), "billion");
  REQUIRE(map->get(static_cast<uInt64>(10000000000ULL)) == "billion");

  delete map;
}

TEST_CASE("HashMap multiple entries", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int16, Int16>* map = builder.create<Int16, Int16>(OBJ::Type::Dec24Fnv);

  int count = 100;
  for (Int16 i = 0; i < count; i++) {
    map->put(i, i * 2);
  }

  for (Int16 i = 0; i < count; i++) {
    REQUIRE(map->get(i) == i * 2);
  }

  delete map;
}

TEST_CASE("HashMap returns stored value after multiple puts", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int16, Int16>* map = builder.create<Int16, Int16>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<Int16>(1), static_cast<Int16>(100));
  map->put(static_cast<Int16>(2), static_cast<Int16>(200));
  map->put(static_cast<Int16>(3), static_cast<Int16>(300));

  REQUIRE(map->get(static_cast<Int16>(1)) == 100);
  REQUIRE(map->get(static_cast<Int16>(2)) == 200);
  REQUIRE(map->get(static_cast<Int16>(3)) == 300);

  delete map;
}

TEST_CASE("HashMap with Dec24Adler", "[hashmap][adler]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int16, Int16>* map = builder.create<Int16, Int16>(OBJ::Type::Dec24Adler);

  map->put(static_cast<Int16>(10), static_cast<Int16>(100));
  REQUIRE(map->get(static_cast<Int16>(10)) == 100);

  delete map;
}

TEST_CASE("HashMap with DMY::Noob value", "[hashmap][dummy]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int16, DMY::Noob*>* map = builder.create<Int16, DMY::Noob*>(OBJ::Type::Dec24Fnv);

  DMY::Noob* noob = new DMY::Noob();
  map->put(static_cast<Int16>(1), noob);

  REQUIRE(map->get(static_cast<Int16>(1)) == noob);

  delete noob;
  delete map;
}

TEST_CASE("HashMap large dataset stress test", "[hashmap][stress]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int16, Int16>* map = builder.create<Int16, Int16>(OBJ::Type::Dec24Fnv);

  int count = 1000000;
  for (Int16 i = 0; i < count; i++) {
    map->put(i, i * i);
  }

  for (Int16 i = 0; i < count; i++) {
    REQUIRE(map->get(i) == i * i);
  }

  delete map;
}

TEST_CASE("HashMap data integrity - verify stored values", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int16, String>* map = builder.create<Int16, String>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<Int16>(0), "zero");
  map->put(static_cast<Int16>(1), "one");
  map->put(static_cast<Int16>(-1), "minus one");
  map->put(static_cast<Int16>(100), "hundred");
  map->put(static_cast<Int16>(-100), "minus hundred");

  REQUIRE(map->get(static_cast<Int16>(0)) == "zero");
  REQUIRE(map->get(static_cast<Int16>(1)) == "one");
  REQUIRE(map->get(static_cast<Int16>(-1)) == "minus one");
  REQUIRE(map->get(static_cast<Int16>(100)) == "hundred");
  REQUIRE(map->get(static_cast<Int16>(-100)) == "minus hundred");

  delete map;
}

TEST_CASE("STC lookup tables are accessible", "[stc]") {
  REQUIRE(STC::Bin::size > 0);
  REQUIRE(STC::Qud::size > 0);
  REQUIRE(STC::Oct::size > 0);
  REQUIRE(STC::Dec::size > 0);
  REQUIRE(STC::Hex::size > 0);
  REQUIRE(STC::Abc::size > 0);
  REQUIRE(STC::Aph::size > 0);
}

TEST_CASE("STC Bin table contents", "[stc]") {
  REQUIRE(STC::Bin::val[0] == '0');
  REQUIRE(STC::Bin::val[1] == '1');
}

TEST_CASE("STC Dec table contents", "[stc]") {
  REQUIRE(STC::Dec::val[0] == '0');
  REQUIRE(STC::Dec::val[9] == '9');
}

TEST_CASE("STC Hex table contents", "[stc]") {
  REQUIRE(STC::Hex::val[0] == '0');
  REQUIRE(STC::Hex::val[9] == '9');
  REQUIRE(STC::Hex::val[10] == 'a');
  REQUIRE(STC::Hex::val[15] == 'f');
}

TEST_CASE("Key conversion produces valid output", "[typ]") {
  String input = "hello";
  String converted = TYP::keyConv<String>(input);
  REQUIRE(converted == input);

  String empty = "";
  String convertedEmpty = TYP::keyConv<String>(empty);
  REQUIRE(convertedEmpty.empty());
}

TEST_CASE("Key conversion Int16", "[typ]") {
  Int16 key = 42;
  String converted = TYP::keyConv<Int16>(key);
  REQUIRE(!converted.empty());
}

TEST_CASE("Key conversion Int32", "[typ]") {
  Int32 key = 12345;
  String converted = TYP::keyConv<Int32>(key);
  REQUIRE(!converted.empty());
}

TEST_CASE("Key conversion Int64", "[typ]") {
  Int64 key = 1234567890123LL;
  String converted = TYP::keyConv<Int64>(key);
  REQUIRE(!converted.empty());
}

TEST_CASE("JNK xxx_to_bin for small values", "[jnk]") {
  REQUIRE(JNK::xxx_to_bin<Int16>(0) == "0");
  REQUIRE(JNK::xxx_to_bin<Int16>(1) == "1");
  REQUIRE(JNK::xxx_to_bin<Int16>(2) == "10");
  REQUIRE(JNK::xxx_to_bin<Int16>(7) == "111");
  REQUIRE(JNK::xxx_to_bin<Int16>(8) == "1000");
}

TEST_CASE("JNK int2bit returns valid output", "[jnk]") {
  String bits = JNK::int2bit(static_cast<Int32>(0));
  REQUIRE(bits.length() > 0);

  bits = JNK::int2bit(static_cast<Int32>(1));
  REQUIRE(bits.length() > 0);

  bits = JNK::int2bit(static_cast<Int32>(255));
  REQUIRE(bits.length() > 0);
}

TEST_CASE("JNK char2bit converts correctly", "[jnk]") {
  String bits = JNK::char2bit('a');
  REQUIRE(bits.length() == 8);

  bits = JNK::char2bit('0');
  REQUIRE(bits.length() == 8);
}

TEST_CASE("FNC blowZero pads correctly", "[fnc]") {
  String input = "101";
  String result = FNC::blowZero(input, 8);
  REQUIRE(result.length() == 8);
  REQUIRE(result == "00000101");

  result = FNC::blowZero(input, 4);
  REQUIRE(result.length() == 4);
  REQUIRE(result == "0101");
}

TEST_CASE("HashMap handles negative keys", "[hashmap][edge]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int16, String>* map = builder.create<Int16, String>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<Int16>(-1), "negative one");
  map->put(static_cast<Int16>(-100), "negative hundred");
  map->put(static_cast<Int16>(0), "zero");

  REQUIRE(map->get(static_cast<Int16>(-1)) == "negative one");
  REQUIRE(map->get(static_cast<Int16>(-100)) == "negative hundred");
  REQUIRE(map->get(static_cast<Int16>(0)) == "zero");

  delete map;
}

TEST_CASE("HashMap zero key", "[hashmap][edge]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int16, String>* map = builder.create<Int16, String>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<Int16>(0), "zero value");

  REQUIRE(map->get(static_cast<Int16>(0)) == "zero value");

  delete map;
}

TEST_CASE("HashMap performance 1M inserts with DMY::Object", "[hashmap][perf][insert]") {
  std::cout << "\n  [PERF] Starting 1M insert test..." << std::endl;
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int32, DMY::Object*>* map = builder.create<Int32, DMY::Object*>(OBJ::Type::Dec24Fnv);

  auto start = std::chrono::high_resolution_clock::now();

  for (Int32 i = 0; i < 1000000; i++) {
    DMY::Object* obj = new DMY::Object("test");
    map->put(i, obj);
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "\n  [PERF] Insert 1M objects (FNV): " << duration.count() << " ms" << std::endl;

  for (Int32 i = 0; i < 1000000; i++) {
    delete map->get(i);
  }
  delete map;
}

TEST_CASE("HashMap performance 2M inserts with DMY::Object", "[hashmap][perf][insert]") {
  std::cout << "\n  [PERF] Starting 2M insert test..." << std::endl;
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int32, DMY::Object*>* map = builder.create<Int32, DMY::Object*>(OBJ::Type::Dec24Fnv);

  auto start = std::chrono::high_resolution_clock::now();

  for (Int32 i = 0; i < 2000000; i++) {
    DMY::Object* obj = new DMY::Object("test");
    map->put(i, obj);
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "\n  [PERF] Insert 2M objects (FNV): " << duration.count() << " ms" << std::endl;

  for (Int32 i = 0; i < 2000000; i++) {
    delete map->get(i);
  }
  delete map;
}

TEST_CASE("HashMap performance 4M inserts with DMY::Object", "[hashmap][perf][insert]") {
  std::cout << "\n  [PERF] Starting 4M insert test..." << std::endl;
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int32, DMY::Object*>* map = builder.create<Int32, DMY::Object*>(OBJ::Type::Dec24Fnv);

  auto start = std::chrono::high_resolution_clock::now();

  for (Int32 i = 0; i < 4000000; i++) {
    DMY::Object* obj = new DMY::Object("test");
    map->put(i, obj);
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "\n  [PERF] Insert 4M objects (FNV): " << duration.count() << " ms" << std::endl;

  for (Int32 i = 0; i < 4000000; i++) {
    delete map->get(i);
  }
  delete map;
}

TEST_CASE("HashMap performance 8M inserts with DMY::Object", "[hashmap][perf][insert]") {
  std::cout << "\n  [PERF] Starting 8M insert test..." << std::endl;
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int32, DMY::Object*>* map = builder.create<Int32, DMY::Object*>(OBJ::Type::Dec24Fnv);

  auto start = std::chrono::high_resolution_clock::now();

  for (Int32 i = 0; i < 8000000; i++) {
    DMY::Object* obj = new DMY::Object("test");
    map->put(i, obj);
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "\n  [PERF] Insert 8M objects (FNV): " << duration.count() << " ms" << std::endl;

  for (Int32 i = 0; i < 8000000; i++) {
    delete map->get(i);
  }
  delete map;
}

TEST_CASE("HashMap performance retrieve 1M objects", "[hashmap][perf][retrieve]") {
  std::cout << "\n  [PERF] Starting retrieve 1M test..." << std::endl;
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int32, DMY::Object*>* map = builder.create<Int32, DMY::Object*>(OBJ::Type::Dec24Fnv);

  for (Int32 i = 0; i < 1000000; i++) {
    DMY::Object* obj = new DMY::Object("test");
    map->put(i, obj);
  }

  auto start = std::chrono::high_resolution_clock::now();

  for (Int32 i = 0; i < 1000000; i++) {
    DMY::Object* retrieved = map->get(i);
    (void)retrieved;
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "\n  [PERF] Retrieve 1M objects: " << duration.count() << " ms" << std::endl;

  for (Int32 i = 0; i < 1000000; i++) {
    delete map->get(i);
  }
  delete map;
}

TEST_CASE("HashMap performance retrieve 2M objects", "[hashmap][perf][retrieve]") {
  std::cout << "\n  [PERF] Starting retrieve 2M test..." << std::endl;
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int32, DMY::Object*>* map = builder.create<Int32, DMY::Object*>(OBJ::Type::Dec24Fnv);

  for (Int32 i = 0; i < 2000000; i++) {
    DMY::Object* obj = new DMY::Object("test");
    map->put(i, obj);
  }

  auto start = std::chrono::high_resolution_clock::now();

  for (Int32 i = 0; i < 2000000; i++) {
    DMY::Object* retrieved = map->get(i);
    (void)retrieved;
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "\n  [PERF] Retrieve 2M objects: " << duration.count() << " ms" << std::endl;

  for (Int32 i = 0; i < 2000000; i++) {
    delete map->get(i);
  }
  delete map;
}

TEST_CASE("HashMap performance retrieve 4M objects", "[hashmap][perf][retrieve]") {
  std::cout << "\n  [PERF] Starting retrieve 4M test..." << std::endl;
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int32, DMY::Object*>* map = builder.create<Int32, DMY::Object*>(OBJ::Type::Dec24Fnv);

  for (Int32 i = 0; i < 4000000; i++) {
    DMY::Object* obj = new DMY::Object("test");
    map->put(i, obj);
  }

  auto start = std::chrono::high_resolution_clock::now();

  for (Int32 i = 0; i < 4000000; i++) {
    DMY::Object* retrieved = map->get(i);
    (void)retrieved;
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "\n  [PERF] Retrieve 4M objects: " << duration.count() << " ms" << std::endl;

  for (Int32 i = 0; i < 4000000; i++) {
    delete map->get(i);
  }
  delete map;
}

TEST_CASE("HashMap performance retrieve 8M objects", "[hashmap][perf][retrieve]") {
  std::cout << "\n  [PERF] Starting retrieve 8M test..." << std::endl;
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int32, DMY::Object*>* map = builder.create<Int32, DMY::Object*>(OBJ::Type::Dec24Fnv);

  for (Int32 i = 0; i < 8000000; i++) {
    DMY::Object* obj = new DMY::Object("test");
    map->put(i, obj);
  }

  auto start = std::chrono::high_resolution_clock::now();

  for (Int32 i = 0; i < 8000000; i++) {
    DMY::Object* retrieved = map->get(i);
    (void)retrieved;
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "\n  [PERF] Retrieve 8M objects: " << duration.count() << " ms" << std::endl;

  for (Int32 i = 0; i < 8000000; i++) {
    delete map->get(i);
  }
  delete map;
}
