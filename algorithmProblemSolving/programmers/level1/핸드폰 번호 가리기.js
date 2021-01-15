function solution(phone_number) {
    let answer = '';
    for(let i=0;i<phone_number.length-4;i++){
        answer += '*';
    }
    answer += phone_number.substr(phone_number.length-4,4);
    return answer;
}