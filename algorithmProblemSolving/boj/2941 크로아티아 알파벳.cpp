#include <iostream>
#include <cstring>
using namespace std;
#define null NULL;
int main() {
	int count = 0;
	char* alp = new char[101];
	cin >> alp;
	int size = strlen(alp);
	for (int i = 0; i < size; i++) {
		switch (alp[i]) {
		case 'c':
			if (alp[i + 1] == '=') {
				count++;
				//i++;
			}
			else if (alp[i + 1] == '-') {
				count++;
				//i++;
			}
			break;
		case 'd':
			if (alp[i + 1] == 'z') {
				if (alp[i + 2] == '=') count+=2;
			}
			else if (alp[i + 1] == '-') {
				count++;
				//i++;
			}
			break;
		case 'l':
			if (alp[i + 1] == 'j') {
				count++;
				//i++;
			}
			break;
		case 'n':
			if (alp[i + 1] == 'j') {
				count++;
				//i++;
			}
			break;
		case 's':
			if (alp[i + 1] == '=') {
				count++;
				//i++;
			}
			break;
		case 'z':
			if (alp[i + 1] == '='&&alp[i-1]!='d') {
				count++;
				//i++;
			}
			break;
		default:
			break;
		}
	}
	cout << size-count;
	delete[] alp;
	alp = null;
	return 0;
}