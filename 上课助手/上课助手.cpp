#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include<ctime>
#include<cstring>
#include<errno.h>
using namespace std;

extern int errno ;

HWND hwnd=GetForegroundWindow();  //��С�����ڣ�

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
  ShowWindow(hwnd,SW_MINIMIZE);  //��С�����ڣ�
  while(true)
    _in_interpreter();
  return 0;
}

int window() {
  system("mode con cols=78 lines=3");
  system("cls");
  system("color f0");
  string s = {"="};
  string s1 = {"���ڼ���ļ�������..."};
  string s2 = {"���ڼ������..."};
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
          fprintf(stderr, "�������: %d\n", errno);
          perror("���Ҳ����ļ�");
          fprintf(stderr, "�򿪴��� %s\n", strerror( errnum ));
          system("color 08");
          return -1;
      }
    }
    cout << s1 << "[" << i*2 << ".0%][" << s << "]\r";
    Sleep(70);
  }
  system("cls");
  cout << "������ɣ�" <<"[100.0%][" << s << "]" << endl;
  cout << "��飺������򿪺���Զ����У������κβ�����\n��Ҫ�޸Ŀα���������class_excel�а���ȷ��ʽ�޸ģ�";
  Sleep(10000);
  return 0;
}

int obtarn_time(string *date, string *Time) {
  time_t now = time(0);
  string dt = ctime(&now);
  *date = dt.substr(0,3);   //��ȡ�ַ���;
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
  const char* s1 = command.data();  //string ת���� char ���ͣ�
  system(s1);
  Sleep(2400000);  //��ͣ40���ӣ�
  return 0;
}
