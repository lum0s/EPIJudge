#include "list_node.h"
#include "test_framework/generic_test.h"

void appendNode(shared_ptr<ListNode<int>>* node, shared_ptr<ListNode<int>>* tail){
	(*tail)->next = *node;
	*tail = *node;
	*node = (*node)->next;
}

shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
  // TODO - you fill in here.
	shared_ptr<ListNode<int>> start (new ListNode<int>);
	shared_ptr<ListNode<int>> tail=NULL;

	if(L1==NULL && L2==NULL){
		return NULL;
	}
	else if(L1==NULL){
		return L2;
	}
	else if(L2==NULL){
		return L1;
	}

	else{

		tail = start;

		while(L1!=NULL && L2!=NULL){

			if(L1->data <= L2->data){
				tail->next = L1;
				tail = L1;
				L1 = L1->next;
			}
			else{
				tail->next = L2;
				tail = L2;
				L2 = L2->next;
			}
		}

		tail->next = L1 ? L1 : L2;
	}
	return start->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}
