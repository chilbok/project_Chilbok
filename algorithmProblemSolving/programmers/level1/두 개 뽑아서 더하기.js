function solution(numbers) {
    var answer = [];
    for(var i=0;i<numbers.length;i++){
        for(var j=0;j<numbers.length;j++){
            if(i!==j){
                answer.push(numbers[i]+numbers[j]);   
            }
        }
    }
    const answer_ = answer.filter((element,index)=>{
        return answer.indexOf(element)===index;
    });
    answer_.sort(function(a,b){
        return a-b;
    })
    return answer_;
}