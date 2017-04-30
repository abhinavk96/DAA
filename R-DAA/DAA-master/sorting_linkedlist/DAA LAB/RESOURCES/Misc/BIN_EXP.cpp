// BIN_EXP.cpp by Soumik Chatterjee
/* 

Binary Exponentiation is based on the idea that,
to find base^power, all we need to do is find base^(power/2) and square it. And this method can be repeated in finding base^(power/2) also.

Suppose that we need to find 5^8.
5^8=5^4 * 5^4
5^4=5^2 * 5^2
5^2=5 * 5

*/

// Copyright 2016 @ Soumik Chatterjee.


#include <iostream>
using namespace std;
#define MOD 1000000009 
#define ll long long int 

ll fastpower(ll base, ll power)
{
	if(power == 0)
		return 1;
	if( power == 1)
		return base;
	ll half = fastpower(base, power / 2);
	if( power % 2 == 0)
		return (half * half) % MOD;
	else
		return (((half * half) % MOD) * base) % MOD;	
}
int main()
{
	ll power, base, result;
	cout<<"FINDING THE BINARY EXPONENTIAN: i.e BASE ^ POWER:\n\n";
	cout<<"Enter the the base: ";
	cin>>base;
	cout<<"Enter the power: ";
	cin>>power;
	cout<<"The value of Modulo (MOD) is :"<<MOD<<endl<<endl;
	result = fastpower(base, power);
	cout<<"The value of "<<base<<" ^ "<<power<<" is -> "<<result<<endl;
	return 0;
}
