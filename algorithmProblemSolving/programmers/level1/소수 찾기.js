function solution(n) {
    var answer = [];
    const tmpSet = new Set();
    //tmpSet.add(2);
    for(let i=1;i<=n;i+=2){
        tmpSet.add(i);
    }
    tmpSet.delete(1);
    for(let i=3;i<Math.sqrt(n);i++){
        if(tmpSet.has(i)){
            for(let k=i*2; k<=n; k+=i){    
                tmpSet.delete(k);
            }
        }
    }
    return tmpSet.size+1;
}