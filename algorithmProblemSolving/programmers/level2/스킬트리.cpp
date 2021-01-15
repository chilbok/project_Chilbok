#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<char> skillV;
    vector<char> back_up;
    for(int i=skill.length()-1;i>-1;i--){
        skillV.push_back(skill.at(i));
    }
    back_up = skillV;
    vector<char>::iterator it;
    bool errCheck = false;
    for(int i=0;i<skill_trees.size();i++){
        for(int j=0;j<skill_trees[i].length();j++){
            it = find(skillV.begin(),skillV.end(),skill_trees[i].at(j));
            if(it!=skillV.end()){
                if(skillV.back()==skill_trees[i][j]){
                    skillV.pop_back();
                }else{
                    errCheck = true;
                    break;
                }
            }
        }
        if(!errCheck){
            answer++;
        }
        errCheck = false;
        skillV = back_up;
    }
    return answer;
}