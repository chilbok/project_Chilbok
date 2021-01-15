#include <string>
#include <vector>
#include <algorithm>
#include <utility>

#include<iostream>

using namespace std;

bool cmp(const pair<int,float> &p1, const pair<int,float> &p2){
    if(p1.second>p2.second){
        return true;
    }else if(p1.second==p2.second){
        return p1.first<p2.first;
    }else{
        return false;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int total_user = stages.size();
    vector<pair<int,float>> stage_info(N,{0,0.0});
    vector<pair<int,int>> player_info(N,{0,0});
    for(int i=0;i<N;i++){
        stage_info[i].first = i+1;
    }
    for(int i=0;i<stages.size();i++){
        for(int j=0;j<stages[i]-1;j++){
            player_info[j].second++;
        }
        player_info[stages[i]-1].first++;
    }
    for(int i=0;i<N;i++){
        if(player_info[i].first+player_info[i].second==0){
            stage_info[i].second = 0;
        }else{
            stage_info[i].second = (float) player_info[i].first / (player_info[i].first+player_info[i].second);    
        }
    }
    sort(stage_info.begin(),stage_info.end(),cmp);
    for(int i=0;i<N;i++){
        answer.push_back(stage_info[i].first);
    }
    return answer;
}