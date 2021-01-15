#include <iostream>
#include <string>
using namespace std;
int main() {
	int month[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	string dow[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

	int x, y, date=0;
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		date += month[i];
	}
	date = date + y - 1;
	cout << dow[date % 7];
	
	return 0;
}