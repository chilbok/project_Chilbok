#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    if(phone_book.size()==1){
        return true;
    }//벡터에 전화번호가 하나만 있는 경우 배제
    else{
        sort(phone_book.begin(), phone_book.end());
        for(int i=0;i<phone_book.size()-1;i++){
            if(phone_book[i]==phone_book[i+1].substr(0,phone_book[i].size())) return false;
        }
    }
    return true;
}