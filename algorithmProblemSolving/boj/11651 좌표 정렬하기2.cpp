#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Locate {
public:
	int x, y;
	Locate(int x, int y) :x(x), y(y) {}
};
void print(vector<Locate> &v);
bool compare(Locate x, Locate y);
int main() {
	cin.tie(NULL);
	int N, tmp_x, tmp_y;
	cin >> N;
	vector<Locate> v;
	for (int i = 0; i < N; i++) {
		cin >> tmp_x >> tmp_y;
		v.push_back(Locate(tmp_x, tmp_y));
	}
	sort(v.begin(), v.end(), compare);
	// 좌표 입력
	print(v);
	return 0;
}
void print(vector<Locate> &v) {
	int size = v.size();
	for (int i = 0; i < size; i++) {
		cout << v[i].x << " " << v[i].y << "\n";
	}
}
bool compare(Locate a, Locate b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}