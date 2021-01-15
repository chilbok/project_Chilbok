function solution(s, n) {
    var answer = '';
    return s.split('').map((v)=>{
        let code = v.charCodeAt(0);
        if(code===32) return v;
        if(code<91){
            return String.fromCharCode((code-65+n)%26+65);
        }else{
            return String.fromCharCode((code-97+n)%26+97);
        }
        return v;
    }).join('');
}