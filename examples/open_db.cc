#include <cassert>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

#include "leveldb/db.h"
#include "leveldb/options.h"

int main(int argc, char** argv) {
  std::cout << "hello leveldb" << std::endl;

  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
  if (!status.ok()) std::cerr << status.ToString() << std::endl;
  assert(status.ok());

  auto const read_options = leveldb::ReadOptions();

  std::string value;
  leveldb::Status s = db->Get(read_options, "foo", &value);
  if (!s.ok()) {
    std::cerr << s.ToString() << std::endl;
    std::cout << "Not found key: foo" << std::endl;
    s = db->Put(leveldb::WriteOptions(), "foo", "bar");
    if (!s.ok()) {
      std::cerr << s.ToString() << std::endl;
      abort();
    }
    s = db->Get(read_options, "foo", &value);
  }
  if (s.ok()) {
    std::cout << "the value of 'foo': " << value << std::endl;
    // s = db->Delete(leveldb::WriteOptions(), "foo");
  }

  delete db;
  return 0;
}
