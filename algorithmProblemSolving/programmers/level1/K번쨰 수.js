function solution(array, commands) {
    var answer = [];
    for(var i=0;i<commands.length;i++){
        var tmpArray = [];
        for(var j=commands[i][0]-1;j<commands[i][1];j++){
            tmpArray.push(array[j]);
        }
        tmpArray.sort(function(a,b){
            return a-b;
        });
        answer.push(tmpArray[commands[i][2]-1]);
    }
    return answer;
}