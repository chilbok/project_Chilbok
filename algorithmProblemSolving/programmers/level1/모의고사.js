function solution(answers) {
    var answer = [];
    var spj1 = [1,2,3,4,5];
    var spj2 = [2,1,2,3,2,4,2,5];
    var spj3 = [3,3,1,1,2,2,4,4,5,5];
    var score = [0,0,0];
    for(var i=0;i<answers.length;i++){
        if(answers[i]==spj1[i%spj1.length]) score[0]++;
        if(answers[i]==spj2[i%spj2.length]) score[1]++;
        if(answers[i]==spj3[i%spj3.length]) score[2]++;
    }
    var max = score.reduce(function(a,b){
        return a>b?a:b;
    });
    for(var i=0;i<score.length;i++){
        if(score[i]==max) answer.push(i+1);
    }
    return answer;
}