function solution(a, b) {
    return a==b? a:a>b? (a*(a+1)-b*(b+1))/2+b:(b*(b+1)-a*(a+1))/2+a;
}