#include <algorithm>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

int find_height(const unique_ptr<BinaryTreeNode<int>>& tree, bool &status){
	int left_height, right_height;
	bool left_status, right_status;

	if(tree){
		left_height = find_height(tree->left, left_status);
		right_height = find_height(tree->right, right_status);
	}
	else{
		status = true;
		return 0;
	}

	if(right_status && left_status && (abs(right_height - left_height) <=1))
		status = true;
	else
		status = false;	

	return std::max(right_height,left_height)+1;
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
	int left_height, right_height;
	bool left_status, right_status;

	if(tree){
		left_height = find_height(tree->left, left_status);
		right_height = find_height(tree->right, right_status);
	}
	else
		return true;

	if(right_status && left_status && (abs(right_height - left_height) <=1))
		return true;
	else
		return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
