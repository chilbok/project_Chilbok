#include <string>
#include <vector>
using namespace std;

vector<char> chV = { '0','1','2','4' };

string makeNum(int n) {
	int N = n;
	vector<char> cV;
	string result = "";
	while (N != 0) {
		int r = N % 3;
		if (r == 0) r = 3;
		cV.push_back(chV[r]);
		N = (N-r) / 3;
	}
	for (int i = cV.size()-1; i >-1; i--) {
		result += cV[i];
	}
	return result;
}


string solution(int n) {
	return makeNum(n);
}