function solution(strings, n) {
    var answer = [];
    strings.sort((s1,s2)=> s1[n]==s2[n]?s1.localeCompare(s2):s1[n].localeCompare(s2[n]));
    return strings;
}