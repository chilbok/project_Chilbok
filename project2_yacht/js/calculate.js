function calculatePoint(diceValue){
    diceValue_ = diceValue;
    diceValue_.sort((a,b)=>{
        return a-b;
    });
    result = [];
    result.push(aces(diceValue_));
    result.push(deuces(diceValue_));
    result.push(threes(diceValue_));
    result.push(fours(diceValue_));
    result.push(fives(diceValue_));
    result.push(sixes(diceValue_));
    result.push(choice(diceValue_));
    result.push(fourOfAKind(diceValue_));
    result.push(fullHouse(diceValue_));
    result.push(sStraight(diceValue_));
    result.push(lStraight(diceValue_));
    result.push(yacht(diceValue_));
    return result;
}

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
        result+=diceValue[i];
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
    if(diceValue===[1,2,3,4,5]){
        return 30;
    }else{
        return 0;
    }
}

function lStraight(diceValue){
    if(diceValue===[2,3,4,5,6]){
        return 30;
    }else{
        return 0;
    }
}

function yacht(diceValue){
    if(diceValue[0]===diceValue[4]){
        return 50;
    }else{
        return 0;
    }
}