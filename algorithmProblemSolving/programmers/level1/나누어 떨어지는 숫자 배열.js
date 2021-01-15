function solution(arr, divisor) {
    var answer = [];
    var tmpAnswer = arr.filter((val,index)=>val%divisor==0);
    if(tmpAnswer.length==0) return [-1];
    tmpAnswer.sort(function(a,b){return a-b});
    return tmpAnswer;
}