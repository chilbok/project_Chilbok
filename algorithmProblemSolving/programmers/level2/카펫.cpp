#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    //brown + red == answer[0]*answer[1]
    vector<int> answer;
    int x,y;
    int b = (brown-4)/2;
    for(int i=1;i<b;i++){
        if((b-i)*i==red){
            x = b-i;
            y = i;
            if(x>=y){
                answer.push_back(x+2);
                answer.push_back(y+2);
            }
        }
    }
    return answer;
}