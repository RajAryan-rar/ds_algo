#include<iostream>
using namespace std;
/*
x << 1 = 2x;
x >> 1 = x/2;
*/
int binaryToDecimal(string s) {
	int n = s.length();
	int num = 0;
	for(int i=n-1; i>=0; i--) {
		num += (s[i] - '0') * (1 << (n-i-1));	
	}
	return num;
}

int main() {
	string s;
	cin>>s;
	cout<<binaryToDecimal(s);

	return 0;

}


