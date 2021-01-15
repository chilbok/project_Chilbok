#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int pick = arr[0];
    answer.push_back(pick);
    for(int i=1;i<arr.size();i++){
        if(arr[i]==pick) continue;
        pick = arr[i];
        answer.push_back(pick);
    }

    return answer;
}