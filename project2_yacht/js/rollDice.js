let selectedDice = Array(5);

const dices = [document.querySelector('.dice0')
    ,document.querySelector('.dice1')
    ,document.querySelector('.dice2')
    ,document.querySelector('.dice3')
    ,document.querySelector('.dice4')];

function roll(turnFlag){
    point = [];
    for(let i=0;i<5;i++){
        if(selectedDice[i]) continue;
        rollDice(i);
        diceValue[i] = dices[i].innerText;
    }
    point = calculatePoint(diceValue);
    if(turnFlag){
        for(let i=0;i<p1Point.length;i++){
            if(p1PointValue[i]===-1){
                p1Point[i].innerText=point[i];
            }
        }
    }else{
        for(let i=0;i<p2Point.length;i++){
            if(p2PointValue[i]===-1){
                p2Point[i].innerText=point[i];
            }
        }
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