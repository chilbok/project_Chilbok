const ROLL_CHANCE = 3;

let turn = true;
let isPlaying = false;
let selectedDice = Array(5);
let diceValue = Array(5);


const playButton = document.querySelector('.playBtn');

const dices = [document.querySelector('.dice0')
    ,document.querySelector('.dice1')
    ,document.querySelector('.dice2')
    ,document.querySelector('.dice3')
    ,document.querySelector('.dice4')];


init();

function init(){
    for(let i=0;i<5;i++){
        selectedDice[i] = false;
    }
}

function run(){
    //if(isPlaying) return;
    //isPlaying = true;
    roll();
}

function buttonChange(text){
    playButton.innerText = text;
}

function roll(){
    for(let i=0;i<5;i++){
        if(selectedDice[i]) continue;
        rollDice(i);
        diceValue[i] = dices[i].innerText;
    }
    console.log(diceValue);
}

function rollDice(idx){
    dices[idx].innerText=Math.floor(Math.random()*6+1);
}

function clickDice(idx){
    if(selectedDice[idx]){
        selectedDice[idx] = !selectedDice[idx];
        dices[idx].classList.remove("selectedDice");
    }else{
        selectedDice[idx] = !selectedDice[idx];
        dices[idx].classList.add("selectedDice");
        console.log(selectedDice);
    }
}