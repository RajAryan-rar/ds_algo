function repeatingElement(arr) {
    let lo=0, hi=arr.length-1;

    while(lo <= hi) {
        let mid = Math.floor(lo + (hi-lo)/2);

        if(mid-1 > 0 && arr[mid-1] == mid-1 && arr[mid-1] == arr[mid]) return arr[mid];
        if(mid+1 < arr.length && arr[mid] == mid && arr[mid] == arr[mid+1]) return arr[mid];

        else if(arr[mid] < mid) hi = mid-1;
        else lo = mid+1;
    }
    return -1;
}

let arr = [0,1,2,2,3,4,5,6];
console.log(repeatingElement(arr));
