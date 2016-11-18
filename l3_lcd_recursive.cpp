#include<iostream>
#include<cstdlib>

using namespace std;


//Function definition
int gcd(int a, int b) {
	if (b==0) 
		return a;
	else
		gcd (b, gcd(a,b) );
	// standard recursive.  Every recursive call the calculation
	// becomes bigger
}

int main(int argc, char* argv[]) {
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);
	cout << "GCD of " << n1 << " and " << n2 << " is : " << gcd(n1,n2) << "\n";
	return 0;
}
	
	