#include<windows.h>
#include<cstdio>
#include<iostream>
#include<conio.h>
 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
HWND hwnd=GetForegroundWindow();//ʹhwnd������ǰ�˵Ĵ��� 
using namespace std;

int main()
{
  long long n,x,y;
	int zhuixiaohua();
	zhuixiaohua();
  for( ; ;) {
  cin>>n>>x;
  while(n>=x) {
    y=n%x;
    n/=x;
    cout<<y<<" ";
  }
  cout<<n<<endl;
  }
  system("pause");
}
 

 
int zhuixiaohua(){
	bool f=1;
	ShowWindow(hwnd,SW_MAXIMIZE);
	printf("����[�ո�]�л����/��С��\n");
	while(1){
		if(KEY_DOWN(VK_SPACE)){
			if(f)ShowWindow(hwnd,SW_MINIMIZE);//��С�� hwnd ������Ĵ��� 
			else ShowWindow(hwnd,SW_MAXIMIZE);//��� hwnd ������Ĵ��� 
			f=1-f;//�л�״̬ 
			Sleep(100);
		}
		Sleep(25);
	}
	
	return 0;
}
