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

const p1Point =[document.querySelector('.p1.aces')
    ,document.querySelector('.p1.deuces')
    ,document.querySelector('.p1.threes')
    ,document.querySelector('.p1.fours')
    ,document.querySelector('.p1.fives')
    ,document.querySelector('.p1.sixes')
    ,document.querySelector('.p1.choice')
    ,document.querySelector('.p1.fourofakind')
    ,document.querySelector('.p1.fullhouse')
    ,document.querySelector('.p1.sstraight')
    ,document.querySelector('.p1.lstraight')
    ,document.querySelector('.p1.yacht')];

const p2Point =[document.querySelector('.p2.aces')
    ,document.querySelector('.p2.deuces')
    ,document.querySelector('.p2.threes')
    ,document.querySelector('.p2.fours')
    ,document.querySelector('.p2.fives')
    ,document.querySelector('.p2.sixes')
    ,document.querySelector('.p2.choice')
    ,document.querySelector('.p2.fourofakind')
    ,document.querySelector('.p2.fullhouse')
    ,document.querySelector('.p2.sstraight')
    ,document.querySelector('.p2.lstraight')
    ,document.querySelector('.p2.yacht')];

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
    point = [];
    for(let i=0;i<5;i++){
        if(selectedDice[i]) continue;
        rollDice(i);
        diceValue[i] = dices[i].innerText;
    }
    point = calculatePoint(diceValue);
    for(let i=0;i<p1Point.length;i++){
        p1Point[i].innerText=point[i];
        p2Point[i].innerText=point[i];
    }
    console.log(diceValue);
    console.log(calculatePoint(diceValue));
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

