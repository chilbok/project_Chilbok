#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long X = x;
    answer.push_back(X);
    for(int i=1;i<n;i++){
        answer.push_back(X+answer[i-1]);
    }
    return answer;
}