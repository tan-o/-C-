#include<iostream>
using namespace std;

int main()
{
	int n,m,num,a;
	cin>>n>>m;
	a=n*m;
	if(n<m) {
		swap(n,m);
	}
	do {
		num=n%m;
		n=m;
		m=num;
	}while(num!=0);
	cout<<"���Լ����"<<n<<endl;
	a/=n;
	cout<<"��󹫱�����"<<a<<endl;
	system("pause");
	return 0;
}