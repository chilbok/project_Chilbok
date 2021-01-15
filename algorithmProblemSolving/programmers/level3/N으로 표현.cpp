#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int makeInt(int N, int l){
    int result = 0;
    for(int i=0;i<l;i++){
        result = result*10+N;
    }
    return result;
}



int solution(int N, int number) {
    int answer = -1;
    set<int>::iterator iter1;
    set<int>::iterator iter2;
    if(N==number) return 1;
    vector<set<int>> findV(9,set<int> ());
    findV[1].insert(N);
    for(int i=2;i<9;i++){
        findV[i].insert(makeInt(N,i));
        for(int j=1;j<i;j++){
            // set[j] vs set[i-j]의 결과물을 집어넣자!
            for(iter1 = findV[j].begin();iter1!=findV[j].end();iter1++){
                for(iter2 = findV[i-j].begin();iter2!=findV[i-j].end();iter2++){
                    int a = *iter1;
                    int b = *iter2;
                    findV[i].insert(a+b);
                    findV[i].insert(a-b);
                    findV[i].insert(a*b);
                    if(b!=0){
                        findV[i].insert((int)(a/b));
                    }
                }
            }
        }
        iter1 = findV[i].find(number);
        if(iter1!=findV[i].end()) return i;
    }
    return answer;
}