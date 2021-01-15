function solution(progresses, speeds) {
    var answer = [];
    let tmpArr = [];
    tmpArr = progresses.map((value, index)=>{
        return Math.ceil((100-value)/speeds[index]);
    });
    console.log(tmpArr);
    let curVal = tmpArr[0];
    let curCnt = 1;
    for(let i=1;i<tmpArr.length;i++){
        if(tmpArr[i]>curVal){
            answer.push(curCnt);
            curCnt = 1;
            curVal = tmpArr[i];
        }else{
            curCnt++;
        }
    }
    answer.push(curCnt);
    return answer;
}