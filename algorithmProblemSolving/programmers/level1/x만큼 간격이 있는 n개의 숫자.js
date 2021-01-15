function solution(x, n) {
    var answer = [];
    answer.push(x);
    for(let i=1;i<n;i++){
        answer.push(x+x*i);
    }
    return answer;
}