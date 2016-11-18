#include<iostream>
#include<cstdlib>

using namespace std;


//Function definition
int gcd(int a, int b) {
	while (b) {
		cout << a << " " << b << "\n"; 
		int temp = b;
		b = a%b;
		a = temp;
		
}
// how has "a" been changed outside the scope of the while loop?
// shouldnt "a" have reverted to n1
return a;
}

int main(int argc, char* argv[]) {
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);
	cout << "GCD of " << n1 << " and " << n2 << " is : " << gcd(n1,n2) << "\n";
	return 0;
}
	
	