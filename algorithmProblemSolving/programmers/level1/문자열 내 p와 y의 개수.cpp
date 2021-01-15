#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt = 0;
    int p = 0, y =0;
    for(int i=0;i<s.length();i++){
        if(s.at(i)=='p'||s.at(i)=='P'){
            cnt++;
        }else if(s.at(i)=='y'||s.at(i)=='Y'){
            cnt--;
        }
    }
    if(cnt!=0){
        return false;
    }
    return answer;
}