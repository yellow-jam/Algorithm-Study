#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int> > a,
			 pair<string, pair<int, int> > b) {
	if(a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	} else {
		return a.second.first > b.second.first;
	}
}

int main(void) {
	vector<pair<int, string> > v;
	v.push_back(pair<int, string>(90, "차태양"));
	v.push_back(pair<int, string>(95, "도겨울"));
	v.push_back(pair<int, string>(75, "채민기"));
	v.push_back(pair<int, string>(80, "하유미"));
	v.push_back(pair<int, string>(87, "마희나"));
	
	sort(v.begin(), v.end());
	for (int i=0; i < v.size(); i++) {
		cout << v[i].second << ' ';  // <int, string>이 각각 first, second
	}
	 
	vector<pair<string, pair<int, int> > > v2;
	v2.push_back(pair<string, pair<int, int> >("유영주", pair<int, int>(90, 2001212)));
	v2.push_back(pair<string, pair<int, int> >("유수연", pair<int, int>(97, 20000527)));
	v2.push_back(pair<string, pair<int, int> >("김혜수", pair<int, int>(93, 20001017)));
	v2.push_back(pair<string, pair<int, int> >("황성민", pair<int, int>(91, 20000720)));
	
	sort(v2.begin(), v2.end(), compare);
	for (int i=0; i < v2.size(); i++) {
		cout << v2[i].first << ' ';  // <int, string>이 각각 first, second
	}
	return 0;
}
