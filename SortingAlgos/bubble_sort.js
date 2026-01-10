function bubbleSort(arr) {
    for(let i=0; i<arr.length-1; i++) {
        let swapped = false;
        for(let j=0; j<arr.length-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                [arr[j],arr[j+1]] = [arr[j+1],arr[j]];
                swapped = true;
            }
        }
        if(!swapped) {
            return arr;
        }
    }
    return arr;
}

let arr = [6,7,8,7,4];
bubbleSort(arr);
console.log(arr);

//kth largest element in the array

let v = [6,-3,1,-2,4];
function g(arr,k) {
    for(let i=0; i<k; i++) {
        for(let j=0; j<arr.length-1; j++) {
            if(arr[j] > arr[j+1]) {
                [arr[j],arr[j+1]] = [arr[j+1],arr[j]];
            }
        }
    }
    return arr[arr.length-k];
}

console.log(g(v,4));