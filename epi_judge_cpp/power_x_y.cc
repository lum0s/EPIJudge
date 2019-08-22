#include "test_framework/generic_test.h"
double Power(double x, int y) {
  // TODO - you fill in here.
	double res = x;
	int n=1;
	bool flag = false;

	if(y==0)
		return 1;
	else if(y<0){
		flag = true;
		y = -1 * y;
	}

	while(y>=n*2){
		res = res*res;
		n=n*2;
	}

	while(y-n>0){
		res = res*x; 
		n++;
	}

	if(flag){
		return 1/res;
	}
	else{
		return res;
	}
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "power_x_y.cc", "power_x_y.tsv", &Power,
                         DefaultComparator{}, param_names);
}
