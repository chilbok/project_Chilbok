#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int length = money.size();
    vector<int> data1(length-1,0); //첫 집을 털었다
    vector<int> data2(length,0); //첫 집을 털지 않았다
    data1[0] = money[0];
    data1[1] = money[0];
    
    data2[0] = 0;
    data2[1] = money[1];
    
    for(int i=2;i<data1.size();i++){
        data1[i] = max(data1[i-2]+money[i],data1[i-1]);
    }
    for(int i=2;i<data2.size();i++){
        data2[i] = max(data2[i-2]+money[i],data2[i-1]);
    }
    answer = max(data1[data1.size()-1],data2[data2.size()-1]);
    return answer;
}