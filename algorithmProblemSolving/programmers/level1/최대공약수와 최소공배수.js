function gcd(minNum, maxNum){
    return (minNum % maxNum) === 0 ? maxNum : gcd(maxNum, minNum % maxNum);
}
function lcm(minNum, maxNum){
    return minNum * maxNum / gcd(minNum, maxNum);
}
function solution(n, m) {
    let maxNum = Math.max(n,m);
    let minNum = Math.min(n,m);
    return [gcd(minNum, maxNum),lcm(minNum, maxNum)];
}