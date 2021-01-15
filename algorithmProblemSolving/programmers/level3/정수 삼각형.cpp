#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>>v = triangle;
    for(int i=v.size()-2;i>-1;i--){
        for(int j=0;j<v[i].size();j++){
            int l = v[i][j]+v[i+1][j];
            int r = v[i][j]+v[i+1][j+1];
            if(l>=r){
                v[i][j] = l;
            }else{
                v[i][j] = r;
            }
        }
    }
    answer = v[0][0];
    
    
    return answer;
}