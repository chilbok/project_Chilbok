#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> words;
    int start = 0;
    for(int i=0;i<s.length();i++){
        if(s.at(i)==' '){
            words.push_back(s.substr(start,i-start+1));
            start = i+1;
        }
    }
    words.push_back(s.substr(start));
    for(int i=0;i<words.size();i++){
        for(int j=0;j<words[i].length();j++){
            if(words[i].at(j)==' ') continue;
            if(j%2==0){
                if(words[i].at(j)>91){
                    words[i].at(j) -=32;
                }
            }else if(j%2==1){
                if(words[i].at(j)<91){
                    words[i].at(j) +=32;
                }
            }
        }
    }
    answer = words[0];
    for(int i=1;i<words.size();i++){
        answer = answer + words[i];
    }
    return answer;
}