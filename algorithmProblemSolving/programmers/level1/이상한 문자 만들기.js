function solution(s){
    let flag = true;
    let result = '';
    for(let i=0;i<s.length;i++){
        if(s.charAt(i)===' '){
            result +=' ';
            flag = true;
            continue;
        }
        if(flag){
            result += (s.charAt(i)).toUpperCase();
        }else{
            result += (s.charAt(i)).toLowerCase();
        }
        flag = !flag;
    }
    return result;
}