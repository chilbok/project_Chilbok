#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.first < p2.first) {
		return true;
	}
	else if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	else {
		return false;
	}
}

struct Time {
	int h = 0;
	int m = 0;
	int s = 0;
	Time() {
	}
	Time(int hh, int mm, int ss) {
		h = hh;
		m = mm;
		s = ss;
	}
	int makeInteger() {
		return (h * 3600 + m * 60 + s);
	}
};

pair<Time, Time> findSE(string line) {
	int h = stoi(line.substr(11, 2)) * 1000;
	int m = stoi(line.substr(14, 2)) * 1000;
	float s_t = stof(line.substr(17, 6)) - stof(line.substr(24, line.length() - 25));
	float s = stof(line.substr(17, 6)) * 10000;
	s = s / 10;
	float t = stof(line.substr(24, line.length() - 25)) * 1000;
	int tmpTime = h * 3600 + m * 60 + s - t;
	int sh = 0;
	int sm = 0;
	int ss;
	if (tmpTime < 0) {
		ss = tmpTime;
	}
	else {
		sh = tmpTime / 3600000;
		sh = sh * 1000;
		tmpTime = tmpTime - sh * 3600;
		sm = tmpTime / 60000;
		sm = sm * 1000;
		tmpTime = tmpTime - sm * 60;
		ss = tmpTime + 1;
	}
	Time E(h, m, s);
	Time S(sh, sm, ss);
	return make_pair(S, E);
}

void printTime(int n) {
	int n_ = n;
	int h = n / 3600000;
	h = h * 1000;
	n_ = n_ - h * 3600;
	int m = n_ / 60000;
	m = m * 1000;
	n_ = n_ - m * 60;
	int s = n_;
	return;
}

int solution(vector<string> lines) {
	int answer = 0;
	vector<pair<int, int>> timeLine;
	for (int i = 0; i < lines.size(); i++) {
		pair<Time, Time> tmp = findSE(lines[i]);
		timeLine.push_back(make_pair(tmp.first.makeInteger(), tmp.second.makeInteger()));
	}
	sort(timeLine.begin(), timeLine.end(), cmp);
	int max = 1;
	for (int i = 0; i < timeLine.size(); i++) {
		for (int j = timeLine[i].first; j <= timeLine[i].second; j++) {
			int tmpMax = 0;
			for (int k = 0; k < timeLine.size(); k++) {
				if (timeLine[k].second >= j && timeLine[k].first <= j + 999) tmpMax++;
			}
			if (tmpMax > max) max = tmpMax;
		}
	}
	answer = max;
	return answer;
}