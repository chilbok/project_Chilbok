const CATEGORY_NAME = ["aces","deuces","threes","fours","fives","sixes","choice"
    ,"fourofakind","fullhouse","sstraight","lstraight","yacht"];

const p1Point =[document.querySelector('.p1.'+CATEGORY_NAME[0])
    ,document.querySelector('.p1.'+CATEGORY_NAME[1])
    ,document.querySelector('.p1.'+CATEGORY_NAME[2])
    ,document.querySelector('.p1.'+CATEGORY_NAME[3])
    ,document.querySelector('.p1.'+CATEGORY_NAME[4])
    ,document.querySelector('.p1.'+CATEGORY_NAME[5])
    ,document.querySelector('.p1.'+CATEGORY_NAME[6])
    ,document.querySelector('.p1.'+CATEGORY_NAME[7])
    ,document.querySelector('.p1.'+CATEGORY_NAME[8])
    ,document.querySelector('.p1.'+CATEGORY_NAME[9])
    ,document.querySelector('.p1.'+CATEGORY_NAME[10])
    ,document.querySelector('.p1.'+CATEGORY_NAME[11])];

const p2Point =[document.querySelector('.p2.'+CATEGORY_NAME[0])
    ,document.querySelector('.p2.'+CATEGORY_NAME[1])
    ,document.querySelector('.p2.'+CATEGORY_NAME[2])
    ,document.querySelector('.p2.'+CATEGORY_NAME[3])
    ,document.querySelector('.p2.'+CATEGORY_NAME[4])
    ,document.querySelector('.p2.'+CATEGORY_NAME[5])
    ,document.querySelector('.p2.'+CATEGORY_NAME[6])
    ,document.querySelector('.p2.'+CATEGORY_NAME[7])
    ,document.querySelector('.p2.'+CATEGORY_NAME[8])
    ,document.querySelector('.p2.'+CATEGORY_NAME[9])
    ,document.querySelector('.p2.'+CATEGORY_NAME[10])
    ,document.querySelector('.p2.'+CATEGORY_NAME[11])];

let p1PointValue = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1];//12 : bonus, 13 : total
let p2PointValue = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1];//12 : bonus, 13 : total

function calculatePoint(diceValue){
    diceValue_ = [];
    for(let i=0;i<5;i++){
        diceValue_.push(parseInt(diceValue[i]));
    }
    diceValue_.sort((a,b)=>{
        return a-b;
    });
    console.log(diceValue_)
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

function selectPoint(e){
    console.log(p1PointValue);
    let player = e.className.split(' ')[0];
    let category = e.className.split(' ')[1];
    let idx;
    let tmp = document.querySelector("."+player+"."+category);
    for(let i=0;i<CATEGORY_NAME.length;i++){
        if(CATEGORY_NAME[i]===category){
            idx = i;
            break;
        }
    }
    if(player === "p1"){
        if(p1PointValue[idx]!==-1) return;
        p1PointValue[idx] = parseInt(tmp.innerText);
        p1Point[idx].classList.add("checkedScore");
        console.log(p1PointValue);
    }else{
        if(p2PointValue[idx]!==-1) return;
        p2PointValue[idx] = parseInt(tmp.innerText);
        p2Point[idx].classList.add("checkedScore");
        console.log(p2PointValue);
    }
}