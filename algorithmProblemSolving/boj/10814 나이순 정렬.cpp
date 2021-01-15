#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct User {
	int age;
	string name;
};
bool compare(User a, User b);
int main() {
	int N, age;
	string name;
	cin >> N;
	User* v = new User[N];
	for (int i = 0; i < N; i++) {
		cin >> v[i].age >> v[i].name;
	}
	stable_sort(v, v+N, compare);
	for (int i = 0; i < N; i++) {
		cout << v[i].age << " " << v[i].name << "\n";
	}
	return 0;
}
bool compare(const User a, const User b) {
	if (a.age < b.age) {
		return true;
	}
	else if (a.age == b.age) {
		return a.age < b.age;
	}
	else{
		return false;
	}
}