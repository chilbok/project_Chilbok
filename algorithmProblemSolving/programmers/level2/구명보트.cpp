#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 1;
    sort(people.begin(),people.end(),greater<int>());
    int l = 0, r = people.size()-1;
    int curW = 0;
    while(l!=r){
        if(curW==0){
            //아직 탄 사람이 없어요~
            if(people[l]+people[r]>limit){
                answer++;
                l++;
            }else{
                curW = people[l]+people[r];
                r--;
            }
        }else{
            //배에 누군가 타있다
            if(curW+people[r]>limit){
                //더는 못태우면
                curW = 0;
                l++;
                answer++;
            }else{
                //아직 더 타!
                curW += people[r];
                r--;
            }
        }
        
    }
    
    return answer;
}