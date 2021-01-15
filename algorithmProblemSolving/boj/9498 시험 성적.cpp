#include <iostream>
#include <string>
using namespace std;

int main() {
	int grade = 0;
	cin >> grade;
	grade = grade / 10;
	switch (grade) {
		case 10:
		case 9:
			cout << "A";
			break;
		case 8:
			cout << "B";
			break;
		case 7:
			cout << "C";
			break;
		case 6:
			cout << "D";
			break;
		default :
			cout << "F";
			break;
	}
		
	return 0;
}