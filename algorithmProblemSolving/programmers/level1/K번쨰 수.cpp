#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> command) {
    vector<int> answer;
    vector<int> v;
    for(int i=0;i<command.size();i++){
        v.clear();
        for(int j=command[i][0]-1;j<command[i][1];j++){
            v.push_back(array[j]);
        }
        sort(v.begin(),v.end());
        answer.push_back(v[command[i][2]-1]);
    }
    return answer;
}