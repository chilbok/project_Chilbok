function solution(a, b) {
    var days = ['SUN','MON','TUE','WED','THU','FRI','SAT'];
    return days[new Date(2016,a-1,b).getDay()];
}