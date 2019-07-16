#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include<ctime>
#include<cstring>
#include<errno.h>
using namespace std;

extern int errno ;

HWND hwnd=GetForegroundWindow();  //最小化窗口；

extern "C" {
  __declspec(dllexport) int main();
  __declspec(dllexport) int window();
  __declspec(dllexport) int _in_interpreter();
  __declspec(dllexport) int work(string);
  __declspec(dllexport) int obtain_time(string*, string*);
}

int main() {
  int num = 0;
  num = window();
  if(num == -1) return 0;
  ShowWindow(hwnd,SW_MINIMIZE);  //最小化窗口；
  while(true)
    _in_interpreter();
  return 0;
}

int window() {
  system("mode con cols=78 lines=3");
  system("cls");
  system("color f0");
  string s = {"="};
  string s1 = {"正在检查文件完整性..."};
  string s2 = {"正在加载组件..."};
  for(int i=0; i<=50; i++) {
    s = s + "=";
    if(i == 25) {
      s1 = s2;  
      system("cls");
    }  
    if(i == 2) {
      FILE * pf;
      int errnum;
      pf = fopen ("class_excel.xml", "rb");
      if (pf == NULL) {
          system("cls");
          errnum = errno;
          fprintf(stderr, "错误代码: %d\n", errno);
          perror("查找不了文件");
          fprintf(stderr, "打开错误 %s\n", strerror( errnum ));
          system("color 08");
          return -1;
      }
    }
    cout << s1 << "[" << i*2 << ".0%][" << s << "]\r";
    Sleep(70);
  }
  system("cls");
  cout << "加载完成！" <<"[100.0%][" << s << "]" << endl;
  cout << "简介：本软件打开后会自动运行，无需任何操作！\n若要修改课表，请自行在class_excel中按正确格式修改！";
  Sleep(10000);
  return 0;
}

int obtarn_time(string *date, string *Time) {
  time_t now = time(0);
  string dt = ctime(&now);
  *date = dt.substr(0,3);   //截取字符串;
  *Time = dt.substr(11,5);
  return 0;
}

int _in_interpreter() {
  string xml_0;
  string Time, Time_1;
  string date, date_1;
  string bu, s1;
  loop:
    obtarn_time(&date,&Time);
    Time_1 = Time;
    Time_1 = '<' + Time + '>';
    fstream xml_in("class_excel.xml",ios::in);
    while (!xml_in.eof()) {
      getline(xml_in, xml_0);
      xml_0 = bu + xml_0;
      bu = xml_0;
    }
    int it_1 = 0, it_2 = 0, total = 0, num = 0;
    it_1 = xml_0.find(Time_1);
    Time_1 = "</" + Time + ">";
    it_2 = xml_0.find(Time_1);
    if(it_1 == -1) {
      Sleep(58000);
      goto loop;
    }
    else {
      total = it_2 - it_1;
      xml_0 = xml_0.substr(it_1+1, total);
      it_1 = 0;
      it_2 = 0;
      date_1 = "<" + date + ">";
      it_1 = xml_0.find(date_1);
      if(it_1 == -1) 
        return 0;
      else {
        date_1 = "</" + date + ">";
        it_2 = xml_0.find(date_1);
        total = it_2 - it_1;
        xml_0 = xml_0.substr(it_1, total);
        num = date_1.size() - 1;
        xml_0.erase(0,num);
        work(xml_0);
      }
    } 
  return 0;
}

int work(string command) {
  const char* s1 = command.data();  //string 转换成 char 类型；
  system(s1);
  Sleep(2400000);  //暂停40分钟；
  return 0;
}
