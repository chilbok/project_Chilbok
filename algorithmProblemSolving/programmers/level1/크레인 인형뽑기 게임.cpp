#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> boards, vector<int> moves) {
	int answer = 0;
	vector<vector<int>> board(boards.size(), vector<int>());
	vector<int> basket;
	for (int i = boards.size()-1; i>-1; i--) {
		for (int j = 0; j<boards.size(); j++) {
			if (boards[i][j] != 0) {
				board[j].push_back(boards[i][j]);
			}
		}
	}
	for (int i = 0; i<moves.size(); i++) {
		int idx = moves[i] - 1;
		int doll = -1;
		if (!board[idx].empty()) {
			doll = board[idx].back();
			board[idx].pop_back();
			answer++;
		}
		if (doll == -1) continue;
		if (basket.empty()) {
			basket.push_back(doll);
		}
		else {
			if (basket.back() == doll) {
				basket.pop_back();;
			}
			else {
				basket.push_back(doll);
			}
		}
	}
	answer = answer - basket.size();
	return answer;
}