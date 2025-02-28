#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
  // TODO - you fill in here.
	int start = 0;
	double max = 0;

	for(int i=1; i<prices.size(); ++i){
		if(prices[i]<prices[start]){
			start = i;
			continue;
		}
		double diff = prices[i]-prices[start];
		if(diff>max)
			max = diff;

	}
  return max;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
