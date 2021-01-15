#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s = to_string(n);
    for(int i=s.length()-1;i>-1;i--){
        answer.push_back(s.at(i)-'0');
    }
    return answer;
}