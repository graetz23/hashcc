#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <string>

#include "./hashccTyp.h"
#include "./hashccFnc.h"
#include "./hashccObj.h"
#include "./hashccDmy.h"

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

TEST_CASE("Empty string hash", "[hash][edge]") {
  String key = "";
  String convertedKey = TYP::keyConv<String>(key);
  String fnvHash = FNC::fnv24_16(convertedKey);
  String adlerHash = FNC::adler24_16(convertedKey);

  REQUIRE(fnvHash.length() == 24);
  REQUIRE(adlerHash.length() == 24);
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

TEST_CASE("HashMap put and get - Int16 key", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int16, String>* map = builder.create<Int16, String>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<Int16>(42), "the answer");
  REQUIRE(map->get(static_cast<Int16>(42)) == "the answer");

  delete map;
}

TEST_CASE("HashMap put and get - Int32 key", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int32, String>* map = builder.create<Int32, String>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<Int32>(1000), "thousand");
  REQUIRE(map->get(static_cast<Int32>(1000)) == "thousand");

  delete map;
}

TEST_CASE("HashMap put and get - Int64 key", "[hashmap]") {
  OBJ::HashMapBuilder builder;
  OBJ::HashMap<Int64, String>* map = builder.create<Int64, String>(OBJ::Type::Dec24Fnv);

  map->put(static_cast<Int64>(100000), "hundred thousand");
  REQUIRE(map->get(static_cast<Int64>(100000)) == "hundred thousand");

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

TEST_CASE("STC lookup tables are accessible", "[stc]") {
  REQUIRE(STC::Bin::size > 0);
  REQUIRE(STC::Qud::size > 0);
  REQUIRE(STC::Oct::size > 0);
  REQUIRE(STC::Dec::size > 0);
  REQUIRE(STC::Hex::size > 0);
  REQUIRE(STC::Abc::size > 0);
  REQUIRE(STC::Aph::size > 0);
}

TEST_CASE("Key conversion produces valid output", "[typ]") {
  String input = "hello";
  String converted = TYP::keyConv<String>(input);
  REQUIRE(converted == input);

  String empty = "";
  String convertedEmpty = TYP::keyConv<String>(empty);
  REQUIRE(convertedEmpty.empty());
}
