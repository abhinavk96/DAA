#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector <int> v(3);
	v[0]=10;
	v[1]=22;
	v[2]=5;
	v.push_back(7);
	cout<<v.front()<<endl;
	cout<<v.back()<<endl;
	cout<<v.at(2)<<endl;
}
