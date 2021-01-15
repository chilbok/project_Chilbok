#include <string>
#include <vector>
#include <iostream>
using namespace std;

int distance(char b) {
	//A:65, Z:90
	//아스키 값으로 N이 13번 이동값
	vector<int> n(26);
	for (int i = 0; i < 14; i++) {
		n[i] = i;
	}
	for (int i = 14; i < 26; i++) {
		n[i] = 26 - i;
	}
	return n[(int)b - 65];
}
int checkA(string name, int idx, int dx) {
	int answer = 0;
	if (dx == -1) return -1;
	for (int i = idx; i < name.length(); i++) {
		if (name.at(i) == 'A') {
			answer++;
		}
		else {
			return answer;
		}
	}
	return answer;
}
int solution(string name) {
	int answer = 0;
	string tmp = "";
	for (int i = 0; i < name.length(); i++) {
		tmp += "A";
	}
	int idx = 0; //현재 커서가 가리키고 있는 위치
	int dx = 1; //커서의 이동방향 (1: 정방향 -1:역방향)
	while (name != tmp) {
		if (idx == name.length()) {
            break;
		}
		else {
            answer += distance(name.at(idx));
			tmp.at(idx) = name.at(idx);
            //현재 커서 위치에서 원하는 문자로 변환시 이동 값
			//문자 설정 후 커서 이동 결정
			if (idx + dx == name.length()) {
				break;
			}
			else {
				if (name.at(idx + dx) == 'A' && dx==1) {
					//다음 문자가 A라면 역방향에 대한 고려
					if (checkA(name, idx + dx, dx) >= idx) {
						dx = -1;
                        answer += (idx + 1);
						idx = name.length() - 1;
						//역방향 진행
					}
					else {
						idx += dx;
                        answer++;
					}
				}
				else {
					//그렇지 않다면 진행
					idx += dx;
                    answer++;//커서 이동에 따른 문자 입력값 증가
				}
			}
		}
	}
    if(dx==-1) answer--;
	return answer;
}