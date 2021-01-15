#include <string>
#include <vector>

using namespace std;

int sums(int n){
    int x = n;
    int result = 0;
    while(x!=0){
        result += x%10;
        x = x/10;
    }
    return result;
}

bool solution(int x) {
    bool answer = false;
    if(x%sums(x)==0){
        return true;
    }
    return answer;
}