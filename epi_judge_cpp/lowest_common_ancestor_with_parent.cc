#include <unordered_set>
#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {

  // TODO - you fill in here.
  if(node0==nullptr || node1==nullptr)
    return nullptr;

  BinaryTreeNode<int>* ptr1 = node0.get();
  BinaryTreeNode<int>* ptr2 = node1.get();
  std::unordered_set<BinaryTreeNode<int>*> m;

  while(ptr1!=NULL){
    m.emplace(ptr1);
    ptr1 = ptr1->parent;
  }

  while(ptr2!=NULL){
    if(m.find(ptr2)!=m.end())
      return ptr2;
    else{
      ptr2=ptr2->parent;
    }
  }


  return nullptr;
}
int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return LCA(node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor_with_parent.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
