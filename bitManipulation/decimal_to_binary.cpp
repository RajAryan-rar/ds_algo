#include<iostream>
using namespace std;

string decimalToString(int n) {
	string result = "";
	while(n > 0) {
		if(n%2 == 0) result = "0" + result;
		else result = "1" + result;

		n >>= 1; //right shift
	}
	return result;
}

int main() {
	int n;
	cin>>n;
	cout<<decimalToString(n);
	

	return 0;
}
