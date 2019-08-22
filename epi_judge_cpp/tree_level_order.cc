#include <memory>
#include <vector>
#include <queue>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::shared_ptr;
using std::vector;
using std::queue;

vector<vector<int>> BinaryTreeDepthOrder(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
	vector<vector<int>> res;
	vector<int>temp;
 	queue<BinaryTreeNode<int>*> q;
 	int current_count = 0, next_count = 0;

 	if(tree.get()==NULL){
 		return res;
 	}
 	else{
 		q.push(tree.get());
 		current_count++;
 		while(!q.empty()){
 			BinaryTreeNode<int>* tmp = q.front();
 			q.pop();
 			temp.push_back(tmp->data);
 			current_count--;
 			if(tmp->left != NULL){
 				next_count++;
 				q.push(tmp->left.get());
 			}
 			if(tmp->right != NULL){
 				next_count++;
 				q.push(tmp->right.get()); 			
 			}
 			if(current_count==0){
 				current_count = next_count;
 				next_count = 0;
 				res.push_back(temp);
 				temp.clear();
 			}
 		}
 	}
  // TODO - you fill in here.
  return res;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_level_order.cc", "tree_level_order.tsv",
                         &BinaryTreeDepthOrder, DefaultComparator{},
                         param_names);
}
