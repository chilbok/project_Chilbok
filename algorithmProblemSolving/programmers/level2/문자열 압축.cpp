#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 10000;
    vector<string> tmpV;
    for(int i=1;i<=s.length();i++){
        tmpV.clear();
        string shortStr = "";
        for(int j=0;j<s.length()/i;j++){
            tmpV.push_back(s.substr(j*i,i));
        }
        if(s.length()%i!=0){
            tmpV.push_back(s.substr(s.length()/i*i,s.length()%i));
        }
        //cout<<"---------------------------\n";
        for(int k=0;k<tmpV.size();k++){
           //cout<<tmpV[k]<<endl;
        }
        //cout<<"---------------------------\n";
        //여기까지 초기화 완료
        int tmpCnt = 1;
        string tmpStr = tmpV[0];
        for(int j=1;j<tmpV.size();j++){
            if(tmpV[j]==tmpStr){
                tmpCnt++;
            }else{
                if(tmpCnt>1){
                    shortStr = shortStr+to_string(tmpCnt);
                }
                shortStr = shortStr+tmpStr;
                
                tmpStr = tmpV[j];
                tmpCnt = 1;
            }
        }
        if(tmpCnt>1){
            shortStr = shortStr+to_string(tmpCnt);
        }
        shortStr = shortStr+tmpStr;
        //cout<<shortStr<<endl;
        if(shortStr.length()!=0&&shortStr.length()<answer){
            answer = shortStr.length();
        }
    }
    
    return answer;
}