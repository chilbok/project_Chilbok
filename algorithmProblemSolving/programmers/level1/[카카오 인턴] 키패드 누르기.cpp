#include <string>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;
string h;
vector<pair<int,int>> btn = {{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{3,0},{3,2}};
int lh = 10, rh = 11;
    
char findNearHand(int b){
    int ld = abs(btn[lh].first - btn[b].first) + abs(btn[lh].second - btn[b].second);
    int rd = abs(btn[rh].first - btn[b].first) + abs(btn[rh].second - btn[b].second);
    if(ld<rd){
        lh = b;
        return 'L';
    }else if(ld>rd){
        rh = b;
        return 'R';
    }else{
        if(h=="left"){
            lh = b;
            return 'L';
        }else{
            rh = b;
            return 'R';
        }
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    h = hand;
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==1||numbers[i]==4||numbers[i]==7){
            lh = numbers[i];
            answer = answer + 'L';
        }else if(numbers[i]==3||numbers[i]==6||numbers[i]==9){
            rh = numbers[i];
            answer = answer + 'R';
        }else{
            answer = answer + findNearHand(numbers[i]);
        }
    }
    return answer;
}