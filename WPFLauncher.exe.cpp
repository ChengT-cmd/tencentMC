#include <bits/stdc++.h>//C++����ͷ
#include<windows.h>//����̨�����Ҫͷ�ļ�
#include<conio.h>//getch()����
#include<stdlib.h>//system()����
using namespace std;
void pos(int x,int y);//ȷ�����λ��
void blue_border();//��ɫ����
void white_back();//��ԭ����ɫ����
void cyan_choose();//��ɫ����
void on_Select();//��ѡ��ʱ����ʽ
void onChoose(int x,int y);//ȷ����ѡ�е�λ��
void star();//��ʼ������
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼������
int main()
{
    system("color 7F");//���ÿ���̨���汳����ɫ��ǰ����ɫ
    system("mode con cols=100 lines=40");//��ʼ����������С
    SetConsoleTitle("M-I-N-E-C-R-A-F-T");//���ÿ���̨���ڱ���
    cyan_choose();
 
    blue_border();
    pos(5,5);
    cout<<"================================M I N E C R A F T================================";//�ϱ߿�
    pos(5,25);
    cout<<"=================================Bedrock Ediction================================";//�±߿�
    for(int i=5,j=6; j<25; j++) //��߿�
    {
        pos(i,j);
        cout<<"|";
    }
    for(int i=85,j=6; j<25; j++) //�ұ߿�
    {
        pos(i,j);
        cout<<"|";
    }
 
    cyan_choose();
    pos(41,14);
    cout<<"������Ϸ";
    pos(41,18);
    cout<<"��    ��";
    on_Select();
    pos(41,10);
    cout<<"������Ϸ";
	MessageBox(NULL,"����\"ȷ��\"�����������˺ź�������е�¼������������MINECRAFT?\n�����˺ţ�����www.tencent.minecraft.com/buy�ϻ���200Ԫ����","��Ѷ��Ϸ",MB_YESNO);
 
//wsad���ƹ��Խ�������ѡ��
    int x=25,y=10;
    char sel;
    sel=getch();
    while(sel!=' ')
    {
        star();
        switch(sel)
        {
        case 'w':
            y=y-4;
            break;
        case 's':
            y=y+4;
            break;
        }
//��ֹ������Χ
        if(x!=41)
        {
            x=41;
        }
        if(y>=18)
        {
            y=18;
        }
        if(y<=10)
        {
            y=10;
        }
        pos(x,y);
        onChoose(x,y);
        sel=getch();
        if((x==41&&y==10)||(x==41&&y==18))
        {
			MessageBox(NULL,"����\"ȷ��\"�����������˺ź�������е�¼������������MINECRAFT?\n�����˺ţ�����www.tencent.minecraft.com/buy�ϻ���200Ԫ����","��Ѷ��Ϸ",MB_YESNO);
        	y=14;
		}
    }
    pos(0,30);
    white_back();//��ԭĬ������
    CloseHandle(hOut);//�رձ�׼������
    return 0;
}
//���ù��λ��
void pos(int x,int y)
{
    COORD posPoint = {x,y}; //��������
    SetConsoleCursorPosition(hOut,posPoint);
}
void blue_border()
{
    WORD blue=FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN;//����������ɫ��������ɫ
    SetConsoleTextAttribute(hOut,blue);//������ʽ
}
void white_back()
{
    WORD white=FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY;
    SetConsoleTextAttribute(hOut,white);
}
void cyan_choose()
{
    WORD cyan=FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE;
    SetConsoleTextAttribute(hOut,cyan);
}
void on_Select()
{
    WORD select=FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_RED;
    SetConsoleTextAttribute(hOut,select);
}
void onChoose(int x,int y)
{
    if(x==41&&y==10)
    {
        on_Select();
        cout<<"������Ϸ";
    }
    else if(x==41&&y==18)
    {
        on_Select();
        cout<<"��    ��";
    }
    else if(x==41&&y==14)
    {
        on_Select();
        cout<<"������Ϸ";
    }
}
void star()
{
    cyan_choose();
    pos(41,10);
    cout<<"������Ϸ";
    pos(41,18);
    cout<<"��    ��";
    pos(41,14);
    cout<<"������Ϸ";
}

