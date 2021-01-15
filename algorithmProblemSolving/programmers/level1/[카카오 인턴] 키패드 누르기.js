function findDist(cur, dest){
    let cur_ = cur;
    let dest_ = dest;
    if(cur===0) cur_=11;
    if(dest===0) dest_ = 11;
    return Math.abs(parseInt((cur_-1)/3)-parseInt((dest_-1)/3))
        +Math.abs(((cur_-1)%3)-((dest_-1)%3));
}

function solution(numbers, hand) {
    let lHand = 10;
    let rHand = 12;
    console.log(findDist(7,0));
    console.log(findDist(12,0));
    
    return numbers.map((v)=>{
        if(v%3===1){
            lHand = v;
            return 'L';
        }else if(v%3===0&&v!==0){
            rHand = v;
            return 'R';
        }else{
            if(findDist(rHand,v)>findDist(lHand,v)){
                lHand = v;
                return 'L';
            }else if(findDist(rHand,v)<findDist(lHand,v)){
                rHand  = v;
                return 'R';
            }else{
                hand==='left'? lHand = v : rHand = v;
                return hand==='left'?'L':'R';
            }
        }
    }).join('');
}