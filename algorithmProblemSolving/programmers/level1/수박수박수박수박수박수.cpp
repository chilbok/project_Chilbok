#include <string>
#include <vector>

using namespace std;

vector<string> v = {"수", "박"};

string solution(int n) {
    string answer = "";
    for(int i=0;i<n;i++){
        answer = answer+v[i%2];
    }
    return answer;
}