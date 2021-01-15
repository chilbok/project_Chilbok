#include<iostream>>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int L, C;
vector<int> check;
vector<char> password;

void init() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char tmp;
		cin >> tmp;
		password.push_back(tmp);
	}
	for (int i = 0; i < L; i++) {
		check.push_back(0);
	}
	for (int i = L; i < C; i++) {
		check.push_back(1);
	}
	sort(password.begin(), password.end());
	return;
}

void findPassword() {
	do {
		string tmpStr = "";
		int consonant = 0;
		int vowel = 0;
		for (int i = 0; i < C; i++) {
			if (!check[i]) {
				if (password[i] == 'a' || password[i] == 'e'
					|| password[i] == 'i' || password[i] == 'o' || password[i] == 'u') vowel++;
				else consonant++;
				tmpStr += password[i];
			}
		}
		if (consonant >= 2 && vowel >= 1) cout << tmpStr << endl;
	} while (next_permutation(check.begin(), check.end()));
	return;
}

void run() {
	init();
	findPassword();
	return;
}

int main() {
	run();
	return 0;
}