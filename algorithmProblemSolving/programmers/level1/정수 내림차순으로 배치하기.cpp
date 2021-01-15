#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    string s = to_string(n);
    for(int i=s.length()-1;i>-1;i--){
        v.push_back(s.at(i)-'0');
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>-1;i--){
        answer = answer*10;
        answer = answer+v[i];
    }
    return answer;
}