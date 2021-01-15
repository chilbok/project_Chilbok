#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> clothes(n+2,1);
    for (int i = 0; i < reserve.size(); i++) {
        clothes[reserve[i]]++;
    }
    for (int i = 0; i < lost.size(); i++) {
        clothes[lost[i]]--;
    }
    for (int i = 1; i < clothes.size() - 1; ++i) {
        if (clothes[i] > 1) {
            //여벌의 옷이 있다면
            if (clothes[i - 1] == 0) {
                clothes[i - 1]++;
            }
            else if (clothes[i + 1] == 0) {
                clothes[i + 1]++;
            }
        }
    }
    for (int i = 1; i < clothes.size() - 1; i++) {
        if (clothes[i] > 0) answer++;
    }
    return answer;
}