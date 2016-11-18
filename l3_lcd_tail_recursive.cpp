#include<iostream>
#include<cstdlib>

using namespace std;


//Function definition
int gcd(int a, int b) {
	if (b==0)  
		return a;
	
	else
		gcd (b, a%b);
	//tail recursion, Rather than passing another lcd to lcd
	// we evaluate before we pass to re recursive function.
}

int main(int argc, char* argv[]) {
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);
	cout << "GCD of " << n1 << " and " << n2 << " is : " << gcd(n1,n2) << "\n";
	return 0;
}
	
	