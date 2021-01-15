#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<bool> visit(201,false);
int idx = 0;

void dfs(vector<vector<int>>v, int n){
    for(int i=0;i<v[n].size();i++){
        if(v[n][i]==1&&visit[i]==false){
            visit[i]=true;
            dfs(v,i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(visit[i]==false){
            answer++;
            dfs(computers,i);
        }
    }
    
    return answer;
}