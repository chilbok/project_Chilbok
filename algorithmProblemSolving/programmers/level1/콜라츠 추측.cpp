#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long n = num;
    while(true){
        if(n==1){
            return answer;
        }
        answer++;
        if(n%2==0){
            n = n/2;
        }else if(n%2==1){
            n = n*3 + 1;
        }
        
        if(answer==501){
            return -1;
        }
    }
    return answer;
}