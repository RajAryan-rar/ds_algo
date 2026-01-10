function getMinIndex(arr,i) {
    let minIdx = i;
    for(let j=i+1; j<arr.length; j++) {
        if(arr[j] < arr[minIdx]) minIdx = j;
    }
    return minIdx;
}

function selectionSort(arr) {
    for(let i=0; i<arr.length; i++) {
        let minIdx = getMinIndex(arr,i);
        [arr[minIdx], arr[i]] = [arr[i], arr[minIdx]]; //swaping
    }
}

// let arr = [3,-1,6,-2,8];
let arr = [6,-3,1,-2,4];
// 6,-3,1,-2,4
selectionSort(arr);

console.log(arr);
