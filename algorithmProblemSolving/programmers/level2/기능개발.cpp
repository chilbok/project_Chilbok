#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> needs;
    int tmp;
    for(int i=0;i<speeds.size();i++){
        tmp = 100-progresses[i];
        if(tmp%speeds[i]==0) tmp = tmp/speeds[i];
        else tmp = tmp/speeds[i] + 1;
        needs.push_back(tmp);
    } //소요되는 작업 일 갱신
    for(int i=1;i<needs.size();i++){
        if(needs[i-1]>needs[i]){
            needs[i] = needs[i-1];
        }
    }//작업일  맞추기
    vector<int> count;
    for(int i=0;i<*max_element(needs.begin(),needs.end())+1;i++){
        count.push_back(0);
    }
    for(int i=0;i<needs.size();i++){
        count[needs[i]]++;
    }
    for(int i=0;i<count.size();i++){if(count[i]!=0) answer.push_back(count[i]);
    }
    return answer;
}