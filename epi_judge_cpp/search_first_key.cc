#include <vector>
#include <algorithm>
#include "test_framework/generic_test.h"
using std::vector;

int SearchFirstOfK(const vector<int>& A, int k) {
  // TODO - you fill in here.
	vector<int>::const_iterator it;
	// std::cout<<std::endl<<"Vector values: ";
	// for(auto a:A)
	// 	std::cout<<a<<" ";
	// std::cout<<"key "<<k<<std::endl;
	it = std::lower_bound(A.begin(), A.end(), k);
//	std::cout<<*it<<std::endl;
	int key = it - A.begin();
//	std::cout<<"Return key: "<<key<<std::endl;

	if(key<A.size() && key>=0 && A[key]== k){
		return key;
	}
	else{
		return -1;
	}

	// if element not present
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                         &SearchFirstOfK, DefaultComparator{}, param_names);
}
