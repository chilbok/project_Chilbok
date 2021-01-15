function solution(p, c) {
    var answer = '';
    p.sort();
    c.sort();
    for(var i=0;i<c.length;i++){
        if(p[i]!=c[i]) return p[i];
    }
    return p[p.length-1];
}