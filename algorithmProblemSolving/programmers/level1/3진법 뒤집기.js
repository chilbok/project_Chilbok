function solution(n) {
    var answer = 0;
    var tmp = n.toString(3).split("").reverse().join();
    for(var i=0;i<tmp.length;i++){
        answer *= 3;
        answer += parseInt(tmp[i]);
    }
    return answer;
}