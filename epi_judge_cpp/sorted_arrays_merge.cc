#include <vector>
#include <queue>
#include "test_framework/generic_test.h"
using std::vector;

struct s{
	int val;
	int array_number;
	int array_index;
};

struct mycomparison
{
  bool operator() (const s& n1, const s& n2) const {
		return n1.val>=n2.val;
	}
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
  // TODO - you fill in here.
	vector<int> result;

	std::priority_queue<s, vector<s>, mycomparison> min_heap;

	for(int i =0; i<sorted_arrays.size(); ++i){
		s temp;
		temp.val = sorted_arrays[i][0];
		temp.array_index = 0;
		temp.array_number = i;
		min_heap.push(temp);
	}

	while(!min_heap.empty()){
		s temp = min_heap.top();
		min_heap.pop();
		result.push_back(temp.val);
		temp.array_index+=1;
		if(temp.array_index < sorted_arrays[temp.array_number].size()){
			temp.val = sorted_arrays[temp.array_number][temp.array_index];
			min_heap.push(temp);
		}
	}

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  return GenericTestMain(args, "sorted_arrays_merge.cc",
                         "sorted_arrays_merge.tsv", &MergeSortedArrays,
                         DefaultComparator{}, param_names);
}
