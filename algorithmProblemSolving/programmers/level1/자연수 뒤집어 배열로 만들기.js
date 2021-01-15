function solution(n) {
    return n.toString().split('').map((v)=>{
        return parseInt(v);
    }).reverse();
}