#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    vector<int> d_ = d;
    int budget_ = budget;
    sort(d_.begin(),d_.end());
    for(int i=0;i<d_.size();i++){
        if(budget_>=d_[i]){
            answer++;
            budget_ -= d_[i];
        }
    }
    return answer;
}