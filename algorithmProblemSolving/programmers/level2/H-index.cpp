#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> v = citations;
    sort(v.begin(),v.end(),greater<int>());
    int h = 0;
    for(int i=1;i<v.size()+1;++i){
        int count = 0;
        //여기서 i가 h를 의미
        for(int j=0;j<v.size();++j){
            if(v[j]>=i){
                count++; //i번 이상 인용된 논문이 count권
            }
        }
        if(count>=i && v[count]<=i){
            if(i>h) h = i;
        }
    }
    answer = h;
    return answer;
}