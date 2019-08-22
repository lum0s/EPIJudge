#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

void MergeTwoSortedArrays(vector<int>& A, int m, const vector<int>& B, int n) {
  // TODO - you fill in here.
  int marker_A = m-1;;
  int marker_B = n-1;
  int marker_final = m+n-1;

  while(marker_final != marker_A && marker_A>=0 && marker_B>=0){
    if(A[marker_A]>B[marker_B]){
      A[marker_final] = A[marker_A];
      marker_final--;
      marker_A--;
    }
    else{
      A[marker_final] = B[marker_B];
      marker_final--;
      marker_B--;      
    }
  }

  while(marker_B!=-1){
    A[marker_final] = B[marker_B];
    marker_final--;
    marker_B--; 
  }

  return;
}
vector<int> MergeTwoSortedArraysWrapper(vector<int> A, int m,
                                        const vector<int>& B, int n) {
  MergeTwoSortedArrays(A, m, B, n);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "m", "B", "n"};
  return GenericTestMain(
      args, "two_sorted_arrays_merge.cc", "two_sorted_arrays_merge.tsv",
      &MergeTwoSortedArraysWrapper, DefaultComparator{}, param_names);
}
