function solution(n){
    let answer = 0;
    n.toString().split('').forEach(function(v){
        answer += parseInt(v);
        return v;
    });
    return answer;
}