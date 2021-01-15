#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(const pair<int,pair<string, int>> p1, const pair<int,pair<string,int>> p2){
    if(p1.second.first.at(p1.first)<p2.second.first.at(p2.first)){
        return true;
    }else if(p1.second.first.at(p1.first)==p2.second.first.at(p2.first)){
        return p1.second.first<p2.second.first;
    }else{
        return false;
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<int,pair<string, int>>> stringsV;
    for(int i=0;i<strings.size();i++){
        stringsV.push_back(make_pair(n,make_pair(strings[i],i)));
    }
    sort(stringsV.begin(),stringsV.end(),cmp);
    for(int i=0;i<stringsV.size();i++){
        answer.push_back(stringsV[i].second.first);
    }
    return answer;
}