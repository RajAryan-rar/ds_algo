#include<iostream>
#include<climits>
using namespace std;

void swapNums(int &a, int &b) {
	cout<<"a :"<<a<<"b :"<<b<<endl;
	a = a^b;	//a -> a^b, b -> b
	b = a^b;	//a -> a^b, b -> a^b^b (a)
	a = a^b;	//a -> a^b^a (b), b -> a

	cout<<"a :"<<a<<"b :"<<b<<endl;
}

void checkBitSetOrNot(int n, int i) {
	//checking the ith bit of n is a setbit or not
	if(((n >> i) & 1) == 1) cout<<"yes it is a setBit";
	else cout<<"not a setbit";
}

void setIthBit(int n, int i) {
	n = n | (1 << i);
	cout<<n<<endl;
}

void clearIthBit(int n, int i) {
	n = n & (~(1 << i));
	cout<<n<<endl;
}

void toggleIthBit(int n, int i) {
	n = n ^ (1 << i);
	cout<<n<<endl;
}

void removeLastSetBit(int n) {
	if(n == 0) {
		cout<<0;
		return;
	}
	n = n & n-1;
	cout<<n<<endl;
}

void minBitsFlip(int a, int b) {
	int temp = a^b;
	cout<<__builtin_popcount(temp);
}

void isPowerOf2(int n) {
	//brian kernighan's algorithm
	int count = 0;

	while(n > 0) {
		count++;
		n = n & n-1;
	}
	if(count == 1) cout<<"true";
	else cout<<"false";
}

int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool sign = true;
        if(dividend > 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor > 0) sign = false;

        long long n = llabs(dividend);
        long long d = llabs(divisor);

        long long ans = 0;
        while(n >= d) {
            int count = 0;

            while(n >= (d << (count+1))) count++;

            ans += (1LL << count);
            n = n - (d * (1LL << count));
        }

        if(ans >= (1LL << 31) && sign == true) return INT_MAX;
        if(ans >= (1LL << 31) && sign == false) return INT_MIN;

        return sign ? ans : (-1 * ans);
}

int main() {
	int a,b;
	cin>>a>>b;
	//swapNums(a,b);
	checkBitSetOrNot(a,b);
	//setIthBit(a,b);
	//clearIthBit(a,b);
	//toggleIthBit(a,b);
	//isPowerOf2(a);
	//minBitsFlip(a,b);


	return 0;
}

