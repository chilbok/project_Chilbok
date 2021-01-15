#include<iostream>
#include<string>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;

bool compare(string a, string b);
int main() {
	vector<string> v;
	int N;
	string word;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		v.push_back(word);
	}
	sort(v.begin(), v.end(), compare);
	vector<string>::iterator it;
	it = unique(v.begin(), v.end());
	v.erase(it, v.end());
	for (int i = 0; i < v.size(); i++) {
		cout<<v[i]<<"\n";
	}
	return 0;
}

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		if (a.compare(b) == 0) {
			return false;
		}
		else if (a.compare(b) < 0) {
			return true;
		}
		else if (a.compare(b) > 0) {
			return false;
		}
	}
	else {
		return a.length() < b.length();
	}
}