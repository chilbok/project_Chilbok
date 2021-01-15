#include <string>
#include <vector>

using namespace std;
vector<bool> nums(1000001,true);
int solution(int n) {
    int answer = 0;
    nums[0] = false;
    nums[1] = false;
    bool check = true;
    for(int i=2;i<n+1;i++){
        if(!nums[i]) continue;
        for(int j=i*2;j<n+1;j=j+i){
            nums[j] = false;
        }
    }
    for(int i=0;i<n+1;i++){
        if(nums[i]) answer++;
    }
    return answer;
}