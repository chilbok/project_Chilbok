function solution(n) {
    let resultArr = [];
    for(let i=1;i<=n;i++){
        let tmpArr = Array(i).fill(-1);
        resultArr.push(tmpArr);
    }
    var answer = [];
    let flag = 0; // 0: down 1: right 2: left+up
    let move = [[1,0],[0,1],[-1,-1]];
    let curRow = 0, curCol = 0;
    let endPoint = n*(n+1)/2;
    for(let i=1;i<=endPoint;i++){
        resultArr[curRow][curCol] = i;
        let tmpRow = curRow+move[flag][0];
        let tmpCol = curCol+move[flag][1];
        if(tmpRow>n-1||tmpRow<0||
            tmpCol>n-1||tmpCol>n-1||
            resultArr[tmpRow][tmpCol]!=-1){
            flag = (flag+1)%3;
        }
        curRow = curRow+move[flag][0];
        curCol = curCol+move[flag][1];
    }
    for(let i=0;i<n;i++){
        for(let j=0;j<i+1;j++){
            answer.push(resultArr[i][j]);  
        }
    }
    return answer;
}