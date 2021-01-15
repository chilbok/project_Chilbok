function solution(priorities, location) {
    let waitList = [];
    for(let i=0;i<priorities.length;i++){
        waitList.push([i,priorities[i]]);
    }
    let cnt = 0;
    let flag = true;
    while(true){
        let curPage = waitList.shift();
        for(let i=0;i<waitList.length;i++){
            if(waitList[i][1]>curPage[1]){
                waitList.push(curPage);
                flag = false;
                break;
            }
        }
        if(flag){
            cnt++;
            if(curPage[0]===location) return cnt;
        }
        flag = true;
    }
}