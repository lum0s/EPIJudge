#include <memory>
#include <bits/stdc++.h> 
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;

void helper(const unique_ptr<BinaryTreeNode<int>>& tree, std::vector<int>& res){
	// call left subtree
	if(tree->left != NULL)
		helper(tree->left, res);

	// make note of the data value
	res.push_back(tree->data);
	// call right subtree 
	if(tree->right != NULL)
		helper(tree->right, res); 

	return ;
}

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {

	std::vector<int> res;

	if(tree==NULL)
		return true;
	
	// call left subtree
	if(tree->left != NULL)
		helper(tree->left, res);

	// make note of the data value
	res.push_back(tree->data);
	// call right subtree 
	if(tree->right != NULL)
		helper(tree->right, res); 

	// Check if values sorted
	int a_prev = INT_MIN;

	for(auto a:res){
		if(a<a_prev)
			return false;
		a_prev = a;
	}

  	return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_a_bst.cc", "is_tree_a_bst.tsv",
                         &IsBinaryTreeBST, DefaultComparator{}, param_names);
}
