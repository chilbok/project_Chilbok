#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int count = 0;
	for (int i = 0; i<prices.size(); i++) {
		count = prices.size()-i-1;
		for (int j = i; j < prices.size(); j++) {
			if (prices[i] > prices[j]) {
				count = j - i;
				break;
			}
		}
        answer.push_back(count);
	}
	return answer;
}