function GCD(x, y) {
    while(y) {
        var t = y;
        y = x % y;
        x = t;
    }
    return x;
}

function solution(w, h) {
        var answer = 0;
        let gcd = GCD(w,h);
        let w_ = w/gcd;
        let h_ = h/gcd;
        for(let i = 0;i<w_;i++){
            answer = answer - Math.floor(i*h_/w_) + Math.ceil((i+1)*h_/w_);
        }
        return w*h - answer*gcd;
}