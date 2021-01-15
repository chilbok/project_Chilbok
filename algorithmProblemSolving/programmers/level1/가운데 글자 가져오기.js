function solution(s) {
    var answer = '';
    var tmp = s.split("");
    if(tmp.length%2){
        return tmp[(tmp.length-1)/2];
    }else{
        return [tmp[(tmp.length/2)-1],tmp[tmp.length/2]].join("");
    }
    return tmp;
}