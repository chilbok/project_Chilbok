/*function solution(n) {
    return Math.pow(parseInt(Math.sqrt(n)),2)===n?Math.pow((Math.sqrt(n)+1),2):-1;
}*/
function solution(n){
    var result = 0;
    var x = 0;
    while (x*x < n){
        x++;
    }
    if (x*x == n){
        x++;
        result = x*x; 
    }else{
        result = -1;
    }
    return result;
}