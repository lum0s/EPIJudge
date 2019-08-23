#include <string>
#include <unordered_map>
#include "test_framework/generic_test.h"
using namespace std;

string ConvertBase(const string& num_as_string, int b1, int b2) {
  // TODO - you fill in here.
	long long num_10 = 0;
	string res;
	std::unordered_map<int,string> d;
	for(int i=0; i<=9; ++i){
		d[i]=i+'0';
	}

	for(int i=10; i<=15; ++i){
		d[i]='A'+i-10;
	}

	if(num_as_string.empty()){
		return res;
	}

	int terminal = 0;
	if(num_as_string[0]=='-'){
		terminal = 1;
	}

	int n = num_as_string.length() - 1;

	for(int i= n; i>=terminal; i--){
		std::cout<<num_10<<endl;
		cout<<"Power: pow(b1, n-1): "<< pow(b1, n-i)<<" num_as_string: "<<num_as_string[i]<<endl;

		if(num_as_string[i]>= 48 && num_as_string[i]<= 57)
			num_10 = num_10+((num_as_string[i]-'0')*pow(b1, n-i));
		else if(num_as_string[i]>= 65 && num_as_string[i]<= 70)
			num_10 = num_10+((num_as_string[i]-'A'+10)*pow(b1, n-i));
	}
	std::cout<<"My calculation: "<<num_10<<std::endl;
	int n1=num_10;
	string m;

	if(n1==0){
		res.append("0");
	}
	else{
		while(n1!=0){
			m = d[n1%b2];
			res.append(m);
			n1 = n1/b2;
		}
	}

	if(terminal)
		res.append("-");

	reverse(res.begin(), res.end());

  return res;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_as_string", "b1", "b2"};
  return GenericTestMain(args, "convert_base.cc", "convert_base.tsv",
                         &ConvertBase, DefaultComparator{}, param_names);
}
