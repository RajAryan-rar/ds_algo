function searchMatrix(matrix, target) {
    let m = matrix.length, n = matrix[0].length;
    let lo = 0, hi = m*n-1;

    while(lo <= hi) {
        let mid = Math.floor(lo + (hi-lo) / 2);
        let r = Math.floor(mid/n), c = mid%n;
        if(matrix[r][c] == target) return true;
        else if(matrix[r][c] < target) lo = mid+1;
        else hi = mid-1;
    }
    return false;
}

let arr = [
    [1,3,5,7],
    [10,11,16,20],
    [23,30,34,60]
]

if(searchMatrix(arr,3)) console.log("true");
else console.log("false"); 