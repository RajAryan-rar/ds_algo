function searchElement(arr, target) {
    let lo = 0, hi = arr.length-1;

    while(lo <= hi) {
        let mid = Math.floor(lo + (hi-lo)/2);
        if(arr[mid] == target) return mid;
        if(arr[mid] >= arr[lo]) {
            //upper curve 
            //check range(left part always sorted)
            if(target >= arr[lo] && target < arr[mid]) hi = mid-1;
            else lo = mid+1;
        } else {
            //lower curve
            //check range(right part always sorted)
            if(target > arr[mid] && target <= nums[hi]) lo = mid+1;
            else hi = mid-1;
        }
    }
    return -1;
}

let arr = [4,5,6,7,0,1,2];
console.log(searchElement(arr,0));