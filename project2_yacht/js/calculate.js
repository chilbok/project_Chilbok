function aces(diceValue){
    let result = 0;
    for(let i=0;i<diceValue.length;i++){
        if(diceValue[i]===1) result+=1;
    }
    return result;
}

function deuces(diceValue){
    let result = 0;
    for(let i=0;i<diceValue.length;i++){
        if(diceValue[i]===2) result+=2;
    }
    return result;
}

function threes(diceValue){
    let result = 0;
    for(let i=0;i<diceValue.length;i++){
        if(diceValue[i]===3) result+=3;
    }
    return result;
}

function fours(diceValue){
    let result = 0;
    for(let i=0;i<diceValue.length;i++){
        if(diceValue[i]===4) result+=4;
    }
    return result;
}

function fives(diceValue){
    let result = 0;
    for(let i=0;i<diceValue.length;i++){
        if(diceValue[i]===5) result+=5;
    }
    return result;
}

function sixes(diceValue){
    let result = 0;
    for(let i=0;i<diceValue.length;i++){
        if(diceValue[i]===6) result+=6;
    }
    return result;
}


function choice(diceValue){
    let result = 0;
    for(let i=0;i<diceValue.length;i++){
        result= result+diceValue[i];
    }
    return result;
}

function fourOfAKind(diceValue){
    if(diceValue[0]===diceValue[3]||diceValue[1]===diceValue[4]){
        return choice(diceValue);
    }else{
        return 0;
    }
}

function fullHouse(diceValue){
    if((diceValue[0]===diceValue[1]&&diceValue[2]===diceValue[4]&&diceValue[1]!==diceValue[2])
    ||(diceValue[0]===diceValue[2]&&diceValue[3]===diceValue[4]&&diceValue[2]!==diceValue[3])){
        return choice(diceValue);
    }else{
        return 0;
    }
}

function sStraight(diceValue){
    for(let i=0;i<diceValue.length;i++){
        if(diceValue[i]!==i+1){
            return 0;
        }
    }
    return 30;
}

function lStraight(diceValue){
    for(let i=0;i<diceValue.length;i++){
        if(diceValue[i]!==i+2){
            return 0;
        }
    }
    return 30;
}

function yacht(diceValue){
    if(diceValue[0]===diceValue[4]){
        return 50;
    }else{
        return 0;
    }
}