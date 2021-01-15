#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> v;
    for(int i=0;i<s.length();i++){
        v.push_back(s.at(i));
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>-1;i--){
        answer = answer + v[i];
    }
    return answer;
}