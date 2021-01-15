#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int a, b, count = 0;
	vector<int> v;
	v.reserve(0);
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		count++;
		v.push_back(a + b);
	}
	for (int i = 0; i < count; i++) {
		cout << v[i]<<endl;
	}
	return 0;
}