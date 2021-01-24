const TEXT_ROLL = "ROLL";
const TEXT_SELECT = "SELECT";
const PLAYER_NAME = [document.querySelector(".p1.status").innerText
    ,document.querySelector(".p2.status").innerText];
const curTurn = document.querySelector(".curTurn");

let turnCnt = 0;
let turnFlag = false;
let points = Array(6);


function play(){
    changeTurnText(PLAYER_NAME[turnFlag]);

}

function changeTurnText(text){
    curTurn.innerText = text;
}