#include <string>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

bool isCompleteStr(string s){
    vector<char> tmpV;
    for(int i=0;i<s.length();i++){
        if(s.at(i)=='('){
            tmpV.push_back('(');
        }else{
            if(tmpV.back()==')'||tmpV.empty()){
                return false;
            }else{
                tmpV.pop_back();
            }
        }
    }
    if(tmpV.size()>0){
        return false;
    }
    return true;
}

pair<string,string> seperate(string s){
    int a = 0;
    int b = 0;
    for(int i=0;i<s.length();i++){
        if(s.at(i)==')'){
            b++;
        }else{
            a++;
        }
        if(a==b){
            return make_pair(s.substr(0,i+1),s.substr(i+1,s.length()-i-1));
        }
    }
}

string makeComplete(string p){
    string result = "";
    if(p==""|isCompleteStr(p)){
        return p;
    }else{
        pair<string,string> tmpPair = seperate(p);
        if(isCompleteStr(tmpPair.first)){
            result = result + tmpPair.first + makeComplete(tmpPair.second);
        }else{
            result = result + '(' + makeComplete(tmpPair.second) + ')';
            string tmpStr = tmpPair.first.substr(1,tmpPair.first.length()-2);
            string tmpStr2 = "";
            for(int i=0;i<tmpStr.length();i++){
                if(tmpStr.at(i)==')'){
                    tmpStr2 = tmpStr2+'(';
                }else{
                    tmpStr2 = tmpStr2+')';
                }
            }
            result = result + tmpStr2;
        }
    }
    return result;
}

string solution(string p) {
    string answer = "";
    if(p==""){
        return answer;
    }
    if(isCompleteStr(p)){
        return p;
    }
    answer = makeComplete(p);
    return answer;
}