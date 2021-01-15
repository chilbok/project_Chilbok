#include <iostream>

using namespace std;
int solution(int n){
    int n_ = n;
    int answer = 0;
    while(n_!=0){
        answer += n_%10;
        n_ =n_/10;
    }
    return answer;
}