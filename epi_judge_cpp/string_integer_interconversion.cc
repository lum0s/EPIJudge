#include <string>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;

string IntToString(int x) {
  // TODO - you fill in here.
  string result;
  char new_ch;
  bool flag = false;
  long long y = (long long) x;

  if(y==0){
    result = "0";
    return result;
  }

  if(y<0){
    y=y*(-1);
    flag = true;
  }

  while(y!=0){
    new_ch = '0'+(y%10);
    result.insert(0, 1, new_ch);
    y=y/10;
  }

  if(flag){
    new_ch = '-';
    result.insert(0, 1, new_ch);
  }

  std::cout<<"int to string: "<<result<<std::endl;
  return result;
}

int StringToInt(const string& s) {
  int result=0, start=0;
  if(s[0]=='-')
    start = 1;
  else
    start=0;

  for(int i=start; i<s.size(); ++i){
    int diff = s[i]-'0';
    result = (result * 10) + diff;
//    std::cout<<"diff: "<<diff<<" result: "<<result<<std::endl;
  }

  std::cout<<"string to int "<<result<<std::endl;
  if(start==0)
    return result;
  else
    return -1*result;
}
void Wrapper(int x, const string& s) {
  if (IntToString(x) != s) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};
  return GenericTestMain(args, "string_integer_interconversion.cc",
                         "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}
