#include <string>
#include <vector>

using namespace std;
int answer = 0;
void dfs(vector<int> num, int target, int sum, int count){
    if(count==num.size()){
        if(sum==target) answer++;
        return;
    }
    dfs(num, target, sum+num[count],count+1);
    dfs(num, target, sum-num[count],count+1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers,target,0,0);
    return answer;
}