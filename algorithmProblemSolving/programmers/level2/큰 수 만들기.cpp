#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Ans{
    char num;
    int index;
};

Ans findMaxNum(string number, int s_index, int e_index){
    Ans answer;
    answer.num = '/';
    for(int i=s_index;i<e_index+1;i++){
        if(answer.num<number.at(i)){
            answer.num = number.at(i);
            answer.index = i;
        }
    }
    return answer;
}


string solution(string number, int k) {
    string answer = "";
    Ans tmp;
    int start_index = 0;
    int printLen = number.length()-k;
    int end_index = number.length()-printLen;
    for(int i=0;i<printLen;i++){
        tmp= findMaxNum(number,start_index,end_index);
        answer+=tmp.num;
        start_index = tmp.index+1;
        end_index++;
    }
    return answer;
}