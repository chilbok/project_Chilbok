function solution(x) {
    let sums = 0;
    return x%x.toString().split('').reduce((tot,cur,i)=>{
        return parseInt(tot)+parseInt(cur);
    },0)===0?true:false;
}