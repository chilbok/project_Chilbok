#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    multimap<string, string> spy;
    multimap<string, string>::iterator iter;
    int answer = 1;
    vector<string> key;
    for(int i=0;i<clothes.size();i++){
        spy.insert(pair<string,string>(clothes[i][1],clothes[i][0]));
        key.push_back(clothes[i][1]);
    }//initialize map
    sort(key.begin(),key.end());
    key.erase(unique(key.begin(), key.end()),key.end());
    for(int i=0;i<key.size();i++){
        answer = answer * (spy.count(key[i])+1);
    }
    return answer-1;
}