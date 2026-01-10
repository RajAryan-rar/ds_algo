function minimumElement(nums) {
    let lo = 0, hi = arr.length-1;
    while(lo <= hi) {
        let mid = Math.floor(lo + (hi - lo)/2);
        if(nums[lo] < nums[hi]) return nums[lo];
        
        //comparing mid with its left
        if(mid > 0 && nums[mid] < nums[mid-1]) return nums[mid];

        //comparing mid with its right
        if(mid+1 < nums.length && nums[mid+1] < nums[mid]) return nums[mid+1];

        //if mid is in upper curve move rightwards
        if(nums[mid] >= nums[lo]) lo = mid+1;

        //else lower curve => move leftwards
        else hi = mid-1;
    }
    return -1;
}

let arr = [4,5,6,7,1,2,3];
console.log(minimumElement(arr));