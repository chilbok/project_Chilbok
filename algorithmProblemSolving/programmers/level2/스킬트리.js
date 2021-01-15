function solution(skill, skill_trees) {
    var answer = 0;
    const skillArr = skill.split('');
    let resultArr = [];
    skill_trees.forEach((v)=>{
        let tmpStr = '';
        for(let i=0;i<v.length;i++){
            if(skillArr.includes(v[i])) tmpStr += v[i];
        }
        tmpStr += skill.substr(tmpStr.length,skill.length-tmpStr.length);
        if(tmpStr===skill) answer++;
    });
    return answer;
}