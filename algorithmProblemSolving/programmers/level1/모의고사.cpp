#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<vector<int>>supo = { { 1,2,3,4,5 },{ 2, 1, 2, 3, 2, 4, 2, 5 },{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 } };
	vector<int> score;
	
	int tmp_s = 0;
	for (int i = 0; i < supo.size(); i++) {
		tmp_s = 0;
		for (int j = 0; j < answers.size(); j++) {
			if (answers[j] == supo[i][j%supo[i].size()]) tmp_s++;
		}
		score.push_back(tmp_s);
	}
	vector<int> max_v = score;
	sort(score.begin(), score.end());
	int max = score[score.size() - 1];
	for (int i = 0; i < score.size(); i++) {
		if (max_v[i] == max) answer.push_back(i + 1);
	}

	return answer;
}