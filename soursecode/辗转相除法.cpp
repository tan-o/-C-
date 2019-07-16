#include<iostream>
using namespace std;

int n,m,num;

int main()
{
	cout << "请输入两个数字：";
	cin>>m>>n;
	if(m<n) {
		swap(m,n);
	}
	do {
		num=m%n;
		m=n;
		n=num;
	}while(num!=0);
	cout<<m<<endl;
	system("pause");
	return 0;
}