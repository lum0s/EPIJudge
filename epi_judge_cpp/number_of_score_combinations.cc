#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int NumCombinationsForFinalScore(int final_score,
                                 const vector<int>& individual_play_scores) {
  // TODO - you fill in here.
	int res = individual_play_scores.size();
	int cache[res][final_score+1];

	if(final_score==0){
		return 1;
	}
	else if(individual_play_scores.size()==0)
		return 0;
	else{
		for(int j=0; j<individual_play_scores.size(); ++j){
			for(int i=0; i<=final_score; ++i){
				if(j==0){
					if((i%individual_play_scores[0])==0){
						cache[j][i] = 1;
					}
					else{
						cache[j][i] = 0;
					}					
				}
				else{
					if((i- individual_play_scores[j]) < 0){
//						std::cout<<"i "<< i << " j: "<<j<<" Indi: "<<individual_play_scores[j]<<std::endl;
						cache[j][i] = cache[j-1][i];
					}
					else{
						cache[j][i] = cache[j-1][i] + cache[j][i- individual_play_scores[j]];
//						std::cout<<"i "<< i << " j: "<<j<<" Indi: "<<individual_play_scores[j]<<" cache: "<< cache[j][i]<<std::endl;
					}
				}
			}
		}
	}

 return cache[ res -1][final_score];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"final_score", "individual_play_scores"};
  return GenericTestMain(args, "number_of_score_combinations.cc",
                         "number_of_score_combinations.tsv",
                         &NumCombinationsForFinalScore, DefaultComparator{},
                         param_names);
}
