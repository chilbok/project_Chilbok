#include <vector>
#include <queue>
#include <utility>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
vector<vector<bool>> visit;
vector<vector<int>> map;
int BFS(pair<int,int> idx){
    int result = 0;
    queue<pair<int,int>> q;
    q.push(idx);
    visit[idx.first][idx.second] = true;
    while(!q.empty()){
        result++;
        pair<int,int> tmp = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ni = tmp.first + di[i];
            int nj = tmp.second + dj[i];
            if(ni<0||nj<0||ni>=map.size()||nj>=map[0].size()) continue;
            if(visit[ni][nj] || map[tmp.first][tmp.second]!=map[ni][nj]) continue;
            q.push(make_pair(ni,nj));
            visit[ni][nj] = true;
        }
    }
    return result;
}

vector<int> solution(int ii, int jj, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<bool>> tmpV (ii,vector<bool>(jj,false));
    visit = tmpV;
    map = picture;
    int max = 0;
    int cnt = 0;
    for(int i=0;i<ii;i++){
        for(int j=0;j<jj;j++){
            if(visit[i][j]||map[i][j]==0) continue;
            else{
                cnt++;
                int tmpMax = BFS(make_pair(i,j));
                if(tmpMax>max) max = tmpMax;
            }
        }
    }
    number_of_area = cnt;
    max_size_of_one_area = max;
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}