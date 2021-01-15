#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> visit(51,false);
int answer = 100;
bool change(string a, string b){
    int count = 0;
    for(int i=0;i<a.length();i++){
        if(a.at(i)!=b.at(i)) count++;
    }
    if(count==1) return true;
    return false;
}

bool hasElem(vector<string> v, string a){
    for(int i=0;i<v.size();i++){
        if(v[i]==a) return true;
    }
    return false;
}

bool allVisit(vector<bool> v){
    for(int i=0;i<v.size();i++){
        if(v[i]==false) return false;
    }
    return true;
}

void dfs(vector<string> v, string b, string t,int count){
    if(allVisit(visit)) return;
    for(int i=0;i<v.size();i++){
        if(change(v[i],b)){
            if(t==v[i]){
                if(count+1<answer){
                    answer = count+1;
                    return;
                }
            }
            if(!visit[i]){
                visit[i] = true;
                dfs(v, v[i],t,count+1);
            }
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    if(!hasElem(words,target)){
        return 0;
    }
    dfs(words, begin, target, 0);
    
    return answer;
}