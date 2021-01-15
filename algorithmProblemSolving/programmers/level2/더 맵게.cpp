#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int mix(int a, int b) {
	return a + b * 2;
}
int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>>food;
	for (int i = 0; i < scoville.size(); i++) {
		food.push(scoville[i]);
	}
	int a, b;
	while (true) {
		if (food.top() >= K) return answer;
		else {
			if (food.size() > 1) {
				a = food.top();
				food.pop();
				b = food.top();
				food.pop();
				food.push(mix(a, b));
				answer++;
			}
			else {
				return -1;
			}
			
		}
	}
	return answer;
}