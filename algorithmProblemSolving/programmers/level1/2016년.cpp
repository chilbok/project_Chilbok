#include <string>
#include <vector>

using namespace std;

vector<string> days = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
vector<int> day = {31,29,31,30,31,30,31,31,30,31,30,31};

string solution(int a, int b) {
    string answer = "";
    int cnt =b;
    for(int i=0;i<a-1;i++){
        cnt+=day[i];
    }
    answer = days[cnt%7];
    return answer;
}