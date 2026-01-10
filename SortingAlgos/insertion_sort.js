function f(arr) {
    for(let i=1; i<arr.length; i++) {
        let currElement = arr[i];
        let j = i-1;
        while(j >= 0 && arr[j] > currElement) {
            arr[j+1] = arr[j]; //shifting the elements
            j--;
        }
        arr[j+1] = currElement;
    }
}

let arr = [9,8,-1,0,33,22,14];
f(arr);
console.log(arr);