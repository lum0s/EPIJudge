#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include "test_framework/generic_test.h"

using namespace std;

struct Q_pair{
	int count;
	string s;
};

struct Comparator{
	bool operator()(const Q_pair& lhs, const Q_pair& rhs){
		return lhs.count<rhs.count;
	}
};

int dist(const string& s, const string& t){

	int count=0;

	if(s.length() != t.length())
		return 0;
	else{
		count = 0;
		for(int i =0; i<s.length(); ++i){
			if((s[i]-t[i])!=0)
				count++;
//			cout<<"difference "<<count<<endl;
		}

	}

	if(count==1)
		return 1;
	else 
		return 0;
}

int dijkstra(unordered_map<string, vector<string>>& m, const string& s, const string& t){

	priority_queue<Q_pair, vector<Q_pair>, Comparator> q;

	int counter = 0;
	q.push({counter, s});

	while(!q.empty()){

		Q_pair current = q.top();
		q.pop();
		cout<<"Q: str pop: "<<current.s<<" count:"<<current.count<<endl;

		if(t.compare(current.s)==0){
			return current.count;
		}
		for(auto &a: m[current.s]){
			q.push({current.count+1, a});
		}
	}

	return -1;
}

// Uses BFS to find the least steps of transformation.
int TransformString(unordered_set<string> D, const string& s, const string& t) {
  // TODO - you fill in here.
	unordered_map<string,vector<string>>m;
	// initialise the map
	// for(auto &d:D){
	// 	m[d] = {};
	// }

	//make the graph

	for(auto &e: D){
		cout<<e<<" ";
	}

	cout<<endl;

	if(s.empty() || t.empty() || D.empty())
		return -1;
	
	unordered_set<string>::iterator it1, it2;

	for(it1 = D.begin(); it1!=D.end(); ++it1){
		for(it2 = it1; it2!=D.end(); ++it2){
			if(it2==it1)
				continue;
			int x = dist(*it1, *it2);
//			cout<<*it1<<" "<<*it2<<endl;
			if(x==1){
				m[*it1].push_back(*it2);
				m[*it2].push_back(*it1);
				cout<<"Actual graph "<<*it1<<" "<<*it2<<endl;

			}
		}
	}

	cout<<"Finished making graph"<<endl;

	int res = dijkstra(m, s, t);

	cout<<"Returning from dijkstra"<<endl;

  return res;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"D", "s", "t"};
  return GenericTestMain(args, "string_transformability.cc",
                         "string_transformability.tsv", &TransformString,
                         DefaultComparator{}, param_names);
}
