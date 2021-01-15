#include<iostream>
using namespace std;
struct Body {
	int w, h, rank=1;
	//weight, height, rank

};
int main() {
	int N, tmp_w, tmp_h;
	cin >> N;
	Body* arr = new Body[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i].h >> arr[i].w;
	}
	for (int i = 0; i < N; i++) {
		tmp_w = arr[i].w;
		tmp_h = arr[i].h;
		for (int j = 0; j < N; j++) {
			if ((tmp_w < arr[j].w) && (tmp_h < arr[j].h)) arr[i].rank++;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i].rank << " ";
	}
	return 0;
}
