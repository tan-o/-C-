#include<iostream>
using namespace std;

int main()
{
	long long n=0,a=1,b=1,c,d=3;
	cin>>n;
	cout<<a<<endl<<b<<endl;
	for(int i=0;i<n;i++) {
		c=a+b;
		cout<<c<<endl;
		a=b+c;
		cout<<a<<endl;
		b=a+c;
		cout<<b<<endl;
	}
	system("pause");
	return 0;
}