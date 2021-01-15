function solution(s) {
    return s.substr(0,1)==='+'?parseInt(s.substr(1,s.length-1)):parseInt(s);
}