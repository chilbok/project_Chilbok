function solution(s){
    var tmpArr = [];
    tmpArr = s.split('');
    var cntP = 0, cntY = 0;
    for(var i=0;i<tmpArr.length;i++){
        if(tmpArr[i]==='p'||tmpArr[i]==='P') cntP++;
        if(tmpArr[i]==='y'||tmpArr[i]==='Y') cntY++;
    }
    return cntP===cntY? true:false;
}