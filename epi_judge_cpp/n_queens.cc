#include <algorithm>
#include <iterator>
#include <vector>
#include <algorithm>
#include "test_framework/generic_test.h"
using std::vector;

bool check_valid(vector<int>& v){
	int curr_size = v.size();
	for(int j=0; j<curr_size-1; j++){
		int k=1;
		while(j+k<curr_size){
			if((v[j]+k == v[j+k]) || (v[j]-k == v[j+k]))
				return false;
			k++;
		}

		while(j+k<curr_size){
			if(v[j]-k == v[j+k])
				return false;
			k++;
		}
	}
	return true;
}

void place(vector<int>& temp, int n, vector<vector<int>>& res){

	if(!check_valid(temp)){
		return;	
	}

	if(temp.size()==n){
		res.push_back(temp);
		return;
	}

	for(int i=0; i<n; i++){
		if(find(temp.begin(), temp.end(), i)==temp.end()){
			temp.push_back(i);
			place(temp, n, res);
			vector<int>::iterator it = find(temp.begin(), temp.end(), i);
			temp.erase(it);
		}
	}

	return ;		
}


vector<vector<int>> NQueens(int n) {
  // TODO - you fill in here.
	vector<vector<int>>res;
	for(int i=0; i<n; i++){
		vector<int> temp;
		temp.push_back(i);
		place(temp, n, res);
		vector<int>::iterator it = find(temp.begin(), temp.end(), i);
		temp.erase(it);
	}

  return res;
}
bool Comp(vector<vector<int>>& a, vector<vector<int>>& b) {
  std::sort(std::begin(a), std::end(a));
  std::sort(std::begin(b), std::end(b));
  return a == b;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "n_queens.cc", "n_queens.tsv", &NQueens, &Comp,
                         param_names);
}
