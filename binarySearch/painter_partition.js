function canPaint(A,B,C,mid) {
    let unitPainted = 0;
    let painters = 1;
    let i = 0;
    while(i < C.length) {
        if(unitPainted + C[i] * B > mid) {
            painters++;
            if(painters > A) return false;
            unitPainted = 0;
        } else {
            unitPainted += (C[i] * B);
            i++;
        }
    }
    return true;
}

function paint(A, B, C){
    let lo = 0, hi = 0;
    for(let i=0; i<C.length; i++) {
        hi += C[i];
        lo = Math.max(lo,C[i]);
    }
    
    hi *= B; // worst case
    lo *= B; // best case
    
    let ans = 0;
    
    while(lo <= hi) {
        let mid = Math.floor(lo + (hi-lo)/2);
        if(canPaint(A,B,C,mid)) {
            ans = mid;
            hi = mid-1;
        } else lo = mid+1;
    }
    return ans % 10000003;
}