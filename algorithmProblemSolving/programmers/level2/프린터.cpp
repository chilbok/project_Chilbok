#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> p, int l) {
    int answer = 0, order_ = 1;
    queue<pair<int, int>> printer;
    priority_queue<int> pri;
    for(int i=0;i<p.size();i++){
        printer.push(pair<int,int>(i, p[i]));
        pri.push(p[i]);
    }
    while(!printer.empty()){
        if(printer.front().second==pri.top()){
            if(printer.front().first == l){
                return answer+1;
            }else{
                answer++;
                printer.pop();
                pri.pop();
            }
        }else{
            printer.push(printer.front());
            printer.pop();
        }
    }
    return answer;
}