#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<char> upperCharV;
vector<char> lowerCharV;

string solution(string s, int n) {
    string answer = "";
    for(char i='a';i<='z';i++){
        lowerCharV.push_back(i);
    }
    for(char i='A';i<='Z';i++){
        upperCharV.push_back(i);
    }
    for(int i=0;i<s.length();i++){
        if(s.at(i)==' '){
            answer = answer+' ';
        }else if(s.at(i)<91){
            answer = answer+upperCharV[(s.at(i)-'A'+n)%26];
        }else{
            answer = answer+lowerCharV[(s.at(i)-'a'+n)%26];
        }
    }
    return answer;
}