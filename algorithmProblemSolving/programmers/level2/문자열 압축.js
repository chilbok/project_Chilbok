function calLength(str, n){
    let resultStr = '';
    let tmpArr = [];
    for(let i=0;i<Math.floor(str.length/n);i++){
        tmpArr.push(str.substr(i*n,n));
    }
    let curStr = tmpArr[0];
    let cnt = 1;
    for(let i=1;i<tmpArr.length;i++){
        if(tmpArr[i]===curStr){
            cnt++;
        }else{
            if(cnt>1) resultStr+=cnt;
            resultStr+=curStr;
            curStr = tmpArr[i];
            cnt=1;
        }
    }
    if(cnt>1) resultStr+=cnt;
    resultStr+=curStr;
    return resultStr.length + str.length%n;
}

function solution(s) {
    let answer = 1003;
    let charArr = s.split('');
    for(let i=1;i<=charArr.length;i++){
        let tmpLength = calLength(s,i);
        if(tmpLength<answer) answer = tmpLength;
    }
    return answer;
}