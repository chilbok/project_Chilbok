#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long tmp;
    for(long long i = 0;i<=n;i++){
        tmp = i*i;
        if(tmp==n){
            return (i+1)*(i+1);
        }else if(tmp>n){
            return -1;
        }
    }
    return answer;
}