function solution(arr) {
    var answer = 0;
    arr.forEach((v)=>{
        answer+=v;
    });
    return answer/arr.length;
}