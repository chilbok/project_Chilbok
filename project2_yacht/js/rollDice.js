const dices = [document.querySelector('.dice0')
    ,document.querySelector('.dice1')
    ,document.querySelector('.dice2')
    ,document.querySelector('.dice3')
    ,document.querySelector('.dice4')];

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