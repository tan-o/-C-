#include<windows.h>
#include<cstdio>
#include<iostream>
#include<conio.h>
 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
HWND hwnd=GetForegroundWindow();//使hwnd代表最前端的窗口 
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
	printf("按下[空格]切换最大/最小化\n");
	while(1){
		if(KEY_DOWN(VK_SPACE)){
			if(f)ShowWindow(hwnd,SW_MINIMIZE);//最小化 hwnd 所代表的窗口 
			else ShowWindow(hwnd,SW_MAXIMIZE);//最大化 hwnd 所代表的窗口 
			f=1-f;//切换状态 
			Sleep(100);
		}
		Sleep(25);
	}
	
	return 0;
}
