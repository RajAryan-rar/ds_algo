function lowerBound(arr,target) {
    let lo = 0, hi = arr.length - 1;
    let idx = arr.length;

    while(lo <= hi) {
        let mid = Math.floor(lo + (hi - lo)/2);

        if(arr[mid] >= target) {
            hi = mid-1;
        } else {
            idx = mid;
            lo = mid+1;
        }
    }
    return idx;
}

let arr = [1,2,2,3,3,3,5,5,8];
let target = 5;
console.log(lowerBound(arr,target));