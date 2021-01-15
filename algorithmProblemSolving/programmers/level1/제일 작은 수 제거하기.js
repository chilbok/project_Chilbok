function solution(arr) {
    var answer = [];
    const tmpSet = new Set(arr);
    arr.sort((a,b)=>{return a-b;});
    tmpSet.delete(arr[0]);
    return arr.length===1?[-1]:[...tmpSet];
}