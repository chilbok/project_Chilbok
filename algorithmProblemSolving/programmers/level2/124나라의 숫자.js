function solution(n) {
    let charV = ['4','1','2','4'];
    var answer = '';
    while(n!=0){
        let d = n%3;
        if(d==0) d = 3;
        answer=charV[d]+answer;
        n = (n-d)/3;
    }
    return answer;
}