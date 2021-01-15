function solution(n, arr1, arr2) {
    var answer = [];
    for(let i=0;i<n;i++){
        let binArr1 = arr1[i].toString(2);
        let binArr2 = arr2[i].toString(2);
        let resultStr = '';
        binArr1 = '0'.repeat(n-binArr1.length)+binArr1;
        binArr2 = '0'.repeat(n-binArr2.length)+binArr2;
        for(let j=0;j<n;j++){
            resultStr+=binArr1.charAt(j)==='0'&&binArr2.charAt(j)==='0'?' ':'#';
        }
        answer.push(resultStr);
    }
    return answer;
}