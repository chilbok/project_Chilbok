const ROLL_CHANCE = 3;

let turn = true;
let isPlaying = false;
let diceValue = Array(5);


const playButton = document.querySelector('.playBtn');

init();

function init(){}


function run(){
    //if(isPlaying) return;
    //isPlaying = true;
    for(let i=1;i<=12;i++){
        roll(turn);
        turn = !turn;
        roll(turn);
    }
}

function buttonChange(text){
    playButton.innerText = text;
}



