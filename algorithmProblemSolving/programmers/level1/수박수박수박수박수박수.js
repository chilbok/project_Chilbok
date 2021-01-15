function solution(n) {
    var answer = '';
    const strArr = ['수','박'];
    for(let i=0;i<n;i++){
        answer+=strArr[i%2];
    }
    return answer;
}