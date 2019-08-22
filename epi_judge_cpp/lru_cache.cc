#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"

using namespace std;
class LruCache {
 public:
  LruCache(size_t capacity) {
    cache_capacity = capacity;
  }

  int Lookup(int isbn) {
    unordered_map<int, pair<list<int>::iterator, int>>::iterator it;

    it = m.find(isbn);
    if(it!=m.end()){
      cache.erase((it->second).first);
      cache.push_front(isbn);
      (it->second).first = cache.begin(); 
      return (it->second).second;
    }
    else{
      return -1;
    }
    // TODO - you fill in here.
    return 0;
  }
  void Insert(int isbn, int price) {
    unordered_map<int, pair<list<int>::iterator, int>>::iterator it;

    it = m.find(isbn);
    if(it!=m.end()){
      cache.erase((it->second).first);
      cache.push_front(isbn);
      (it->second).first = cache.begin(); 
    }
    else{
      if(m.size()<cache_capacity){
        cache.push_front(isbn);
        m[isbn] = {begin(cache), price};
      }
      else{
        int temp_isbn = cache.back();
        m.erase(temp_isbn);
        cache.pop_back();
        cache.push_front(isbn);
        m[isbn] = {begin(cache), price};
      }
    }

    return;
  }
  bool Erase(int isbn) {
    unordered_map<int, pair<list<int>::iterator, int>>::iterator it;

    it = m.find(isbn);
    if(it!=m.end()){
      cache.erase((it->second).first);
      m.erase(it);
      return true; 
    }
    else{
      return false;
    }
  }

private:
  
  unordered_map<int, pair<list<int>::iterator, int>>m;
  int cache_capacity;
  list<int> cache;
};
struct Op {
  std::string code;
  int arg1;
  int arg2;
};

template <>
struct SerializationTraits<Op> : UserSerTraits<Op, std::string, int, int> {};

void RunTest(const std::vector<Op>& commands) {
  if (commands.empty() || commands[0].code != "LruCache") {
    throw std::runtime_error("Expected LruCache as first command");
  }
  LruCache cache(commands[0].arg1);

  for (int i = 1; i < commands.size(); i++) {
    auto& cmd = commands[i];
    if (cmd.code == "lookup") {
      int result = cache.Lookup(cmd.arg1);
      if (result != cmd.arg2) {
        throw TestFailure("Lookup: expected " + std::to_string(cmd.arg2) +
                          ", got " + std::to_string(result));
      }
    } else if (cmd.code == "insert") {
      cache.Insert(cmd.arg1, cmd.arg2);
    } else if (cmd.code == "erase") {
      bool result = cache.Erase(cmd.arg1);
      if (result != cmd.arg2) {
        throw TestFailure("Erase: expected " + std::to_string(cmd.arg2) +
                          ", got " + std::to_string(result));
      }
    } else {
      throw std::runtime_error("Unexpected command " + cmd.code);
    }
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"commands"};
  return GenericTestMain(args, "lru_cache.cc", "lru_cache.tsv", &RunTest,
                         DefaultComparator{}, param_names);
}
