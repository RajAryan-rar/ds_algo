#include<iostream>
#include<bitset>
using namespace std;

/**
 * Given two integers left and right,
 * return the count of numbers in the inclusive range [left, right]
 * having a prime number of set bits in their binary representation.
 * 
 * Constraints :
 *      1 <= left <= right <= 10^6
 */

 /**
  * Approach :
  *     Since 10^6 is less than 2^{20}, any number from left to right
  *     can be represented using at most 20 bits. If a number only has
  *     20 "slots" (bits) to fill, the maximum number of 1s it can possibly
  *     have is 20 (which happens if the number is $2^{20} - 1$). 
  *     Therefore, when we count the setBits, the result will always be
  *     an integer between 0 and 20.
  *     10^6 < 2^20  ==> we need max 20 bits
  *     Primes < 20: 2, 3, 5, 7, 11, 13, 17, 19
        Binary mask: 010100010100010101100 (in decimal: 665772)

  *     TC : O(n)
            since,  __builtin_popcount() ==> O(1)
  */
int countPrimeSetBits(int left, int right) {
    int count = 0;
    int primeMask = 665772;
    for(int i=left; i<=right; i++) {
        int setBits = __builtin_popcount(i);

        if((primeMask >> setBits) & 1 == 1) {
            count++;
        } 
    }
    return count;
}

int main() {
    int left, right;
    cin>>left>>right;

    cout<<countPrimeSetBits(left,right);

    return 0;
}