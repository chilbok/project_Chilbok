function solution(d, budget) {
    return d.sort((a,b)=>a-b).reduce((acc,cur,idx)=>{
        budget-=cur;
        return budget>=0?acc+1:acc;
    },0);
}