#include<iostream>
#include<vector>

using namespace std;

int first_set_bit_position(int n) {
    int i = 0;
    while(true) {
        if(n == 0) break;
        if(n & 1) return i;
        i++;
        n >>= 1;
    }
    return i;
}

int last_set_bit_position(int n) {
    int i=0, temp = 0; 
    while(n > 0) {
        if(n & 1) temp = i;
        i++;
        n >>= 1;
    }
    return temp;
}

vector<int> largest_and_smallest_power_of_2_set_in_the_integer(int n) {
    //using brian kernighan algorithm

    vector<int> result(2);
    result[0] = n & ~(n-1);

    int temp = 0;
    while(n > 0) {
        if(n != 0) temp=n;
        n = n & n-1;
    }
    result[1] = temp;
    return result;
}

int main() {
    int n;
    cin>>n;
    vector<int> ans = largest_and_smallest_power_of_2_set_in_the_integer(n);

    cout<<first_set_bit_position(ans[0])
    <<" "
    <<last_set_bit_position(ans[1]);

    return 0;
}