#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {
  // TODO - you fill in here.
	ListNode<int>* ptr = L.get(), before_list, after_list, prev, next;
	int count = 1;
	while(count != start){
		prev = ptr;
		ptr = ptr->next;
		count++;
	}

	before_list = prev;

	prev = ptr;
	ptr = ptr->next;
	next = ptr -> next;
	count ++;

	while(count != finish){
		ptr->next = prev;
		prev = ptr;
		ptr = next;
		next = next->next;
		count++;
	}

	before_list -> next = ptr;

  return nullptr;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "start", "finish"};
  return GenericTestMain(args, "reverse_sublist.cc", "reverse_sublist.tsv",
                         &ReverseSublist, DefaultComparator{}, param_names);
}
