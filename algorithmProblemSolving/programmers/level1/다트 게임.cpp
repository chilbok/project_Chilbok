#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    string s = dartResult;
    vector<int> score;
    for(int i=0;i<s.length();i++){
        if(s.at(i)>='0'&&s.at(i)<='9'){
            if(i>0&&s.at(i)=='0'&&s.at(i-1)=='1'){
                score.pop_back();
                score.push_back(10);
            }else{
                score.push_back(s.at(i)-'0');
            }
        }else{
            int tmp;
            switch(s.at(i)){
                case 'D':
                    tmp = score.back();
                    score.pop_back();
                    score.push_back(tmp*tmp);
                    break;
                case 'T':
                    tmp = score.back();
                    score.pop_back();
                    score.push_back(tmp*tmp*tmp);
                    break;
                case '*':
                    if(score.size()==1){
                        score[0] = score[0]*2;
                    }else{
                        score[score.size()-1] = score[score.size()-1] *2;
                        score[score.size()-2] = score[score.size()-2] *2;
                    }
                    break;
                case '#':
                    score[score.size()-1] = score[score.size()-1]*-1;
                    break;
                    
            }
        }
    }
    for(int i=0;i<score.size();i++){
        answer = answer+score[i];
        cout<<score[i]<<endl;
    }
    return answer;
}