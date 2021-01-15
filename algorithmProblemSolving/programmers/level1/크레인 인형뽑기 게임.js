function solution(board, moves) {
    var answer = 0;
    var basket = [];
    for(var i=0;i<moves.length;i++){
        var target = moves[i]-1;
        for(var j=0;j<board.length;j++){
            if(board[j][target]!=0){
                if(basket[basket.length-1]==board[j][target]){
                    answer+=2;
                    basket.length = basket.length-1;
                }else{
                    basket.push(board[j][target]);
                }
                board[j][target]=0;
                break;
            }
        }
    }
    return answer;
}