#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
struct genre_plays{
    string genre;
    int plays;
};
struct idx_plays{
    int idx;
    int play;
};
bool cmp(const genre_plays &i1,const genre_plays &i2){
    if(i1.plays>i2.plays) return true;
    else return false;
}
bool cmp_(const idx_plays &i1,const idx_plays &i2){
    if(i1.play>i2.play) return true;
    else return false;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    multimap<string, int> gen_idx, gen_plays;
    vector<string> keys = genres;
    sort(keys.begin(),keys.end());
    keys.erase(unique(keys.begin(),keys.end()),keys.end()); //key 값 추출
    vector<genre_plays> sumOfPlays;
    genre_plays tmp_struct;
    for(int i=0;i<keys.size();i++){
        int count = 0;
        for(int j=0;j<genres.size();j++){
            if(keys[i]==genres[j]){
                count+=plays[j];
            }
        }
        tmp_struct.genre = keys[i];
        tmp_struct.plays = count;
        sumOfPlays.push_back(tmp_struct);
    }
    sort(sumOfPlays.begin(), sumOfPlays.end(), cmp);
    //key값을 합계가 큰 순으로 정렬 완료
    for(int i=0;i<genres.size();i++){
        gen_idx.insert(pair<string, int>(genres[i],i));
    }
    vector<idx_plays> sorting_vector;
    idx_plays tmp_struct2;
    multimap<string, int>::iterator iter;
    pair<map<string, int>::iterator, map<string, int>::iterator> iter_pair;
    for(int i=0;i<sumOfPlays.size();i++){
        iter_pair = gen_idx.equal_range(sumOfPlays[i].genre);
        for (iter = iter_pair.first; iter != iter_pair.second; ++iter){
            tmp_struct2.idx = iter->second;
            tmp_struct2.play = plays[iter->second];
            sorting_vector.push_back(tmp_struct2);
        }
        sort(sorting_vector.begin(), sorting_vector.end(), cmp_);
        if(sorting_vector.size()==1){
            answer.push_back(sorting_vector[0].idx);
        }else{
            answer.push_back(sorting_vector[0].idx);
            answer.push_back(sorting_vector[1].idx);
        }
        sorting_vector.clear();
    }
    return answer;
}