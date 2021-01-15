#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string &a, string &b){
    if(a+b>b+a) return true;
    else return false;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int i=0;i<numbers.size();i++){
        v.push_back(to_string(numbers[i]));
    }
    sort(v.begin(),v.end(), cmp);
    for(int i=0;i<v.size();i++){
        if(!(answer==""&&v[i]=="0")){
            answer+=v[i];
        }
    }
    if(answer=="") answer = "0";
    return answer;
}