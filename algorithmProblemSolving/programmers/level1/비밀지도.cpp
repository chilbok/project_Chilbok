#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string change(int input, int n){
    string result = "";
    if(input>0){
        while(input>1){
			if(input%2 == 1){
				result+='1';
			}
			else
				result+='0'; //2진수 변환
			input/=2;
		}
        result+='1';
        reverse(result.begin(),result.end());
        string tmp;        
        for(int i=0;i<n-result.length();i++){
            tmp = tmp+"0";
        }
        result = tmp+result;
    }else{
        for(int i=0;i<n;i++){
            result = result+"0";
        }
    }
    
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<n;i++){
        string map1 = change(arr1[i], n);
        string map2 = change(arr2[i], n);
        string tmp = "";
        for(int j=0;j<map1.length();j++){
            if(map1.at(j)=='0'&&map2.at(j)=='0'){
                tmp = tmp + " ";
            }else{
                tmp = tmp + "#";
            }
        }
        answer.push_back(tmp);
    }
    return answer;
}