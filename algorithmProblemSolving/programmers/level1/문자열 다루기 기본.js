function solution(s) {
    var answer = true;
    var tmpArr = s.split('').sort();
    return tmpArr.length===4||tmpArr.length===6?
        tmpArr[tmpArr.length-1]>='a'?false:true:false;
}