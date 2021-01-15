//variables
const GAME_TIME = 8;
const START_BUTTON_TEXT = 'start game';
const LOAD_BUTTON_TEXT = 'loading...';
const PLAYING_BUTTON_TEXT = 'playing...';
const END_BUTTON_TEXT = 'game over';
const WORD_SIZE = 200;
let score = 0;
let time = GAME_TIME;
let isPlaying = false;
let timeInterval;
let checkInterval;
let words = [];
const wordInput = document.querySelector('.word-input');
const wordDisplay = document.querySelector(".word-display");
const scoreDisplay = document.querySelector('.score');
const timeDisplay = document.querySelector('.time');
const playButton = document.querySelector('.button');

//events
init();
    
function init(){
    buttonChange(LOAD_BUTTON_TEXT);
    getWords();
    wordInput.addEventListener('input',checkMatch)
}

function run(){
    if(isPlaying){
        return;
    }
    isPlaying = true;
    time = GAME_TIME;
    wordInput.focus();
    scoreDisplay.innerText = 0;
    timeInterval = setInterval(countDown,1000);
    checkInterval = setInterval(checkStatus,50);
    buttonChange(PLAYING_BUTTON_TEXT);
}

//check word matching
function checkMatch(){
    if(wordInput.value===wordDisplay.innerText){
        wordInput.value = "";
        if(!isPlaying){
            return;
        }
        scoreDisplay.innerText = score;
        score++;
        time = GAME_TIME;
        const randomIndex = Math.floor(Math.random()*words.length);
        wordDisplay.innerText = words[randomIndex];
    }
}

function checkStatus(){
    if(!isPlaying&&time===0){
        buttonChange(START_BUTTON_TEXT);
        clearInterval(checkInterval);
    }
}

function getWords(){
    axios.get('https://random-word-api.herokuapp.com/word?number='+WORD_SIZE)
        .then(function (response) {
            // handle success
            response.data.forEach((word)=>{
                if(word.length<10) words.push(word);
            });
            buttonChange(START_BUTTON_TEXT);
        })
        .catch(function (error) {
            // handle error
            console.log(error);
        });
}

buttonChange(START_BUTTON_TEXT);

function countDown(){
    time>0?time--:isPlaying = false;
    if(!isPlaying){
        clearInterval(timeInterval);
    }
    timeDisplay.innerText = time;
}

function buttonChange(text){
    playButton.innerText = text;
    text===START_BUTTON_TEXT?playButton.classList.remove('loading'):playButton.classList.add('loading');
}