#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
  // TODO - you fill in here.
	std::vector<int>::const_iterator it1=A.begin();
	std::vector<int>::const_iterator it2=B.begin();

	vector<int>res;

	if(A.empty() || B.empty())
		return res;

	while(it1!=A.end() && it2!= B.end()){
		if(it1!=A.begin() && *it1==*(it1-1)){
			while(it1!=A.end() && *it1==*(it1-1))
				++it1;
			continue;
		}

		if(it2!=B.begin() && *it2==*(it2-1)){
			while(it2!=B.end() && *it2==*(it2-1))
				++it2;
			continue;
		}

		if(*it1==*it2){
			res.push_back(*it1);
			++it1;
			++it2;
		}
		else if(*it1<*it2){
			++it1;
		}
		else{
			++it2;
		}
	}

  return res;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(
      args, "intersect_sorted_arrays.cc", "intersect_sorted_arrays.tsv",
      &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
}
