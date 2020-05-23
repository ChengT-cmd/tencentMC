#include <bits/stdc++.h>//C++万能头
#include<windows.h>//控制台编程主要头文件
#include<conio.h>//getch()函数
#include<stdlib.h>//system()函数
using namespace std;
void pos(int x,int y);//确定光标位置
void blue_border();//蓝色字体
void white_back();//还原亮白色字体
void cyan_choose();//青色字体
void on_Select();//被选中时的样式
void onChoose(int x,int y);//确定所选中的位置
void star();//初始化界面
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出句柄
int main()
{
    system("color 7F");//设置控制台界面背景颜色和前景颜色
    system("mode con cols=100 lines=40");//初始化缓冲区大小
    SetConsoleTitle("M-I-N-E-C-R-A-F-T");//设置控制台窗口标题
    cyan_choose();
 
    blue_border();
    pos(5,5);
    cout<<"================================M I N E C R A F T================================";//上边框
    pos(5,25);
    cout<<"=================================Bedrock Ediction================================";//下边框
    for(int i=5,j=6; j<25; j++) //左边框
    {
        pos(i,j);
        cout<<"|";
    }
    for(int i=85,j=6; j<25; j++) //右边框
    {
        pos(i,j);
        cout<<"|";
    }
 
    cyan_choose();
    pos(41,14);
    cout<<"多人游戏";
    pos(41,18);
    cout<<"退    出";
    on_Select();
    pos(41,10);
    cout<<"单人游戏";
	MessageBox(NULL,"单击\"确定\"并输入您的账号和密码进行登录来体验完整版MINECRAFT?\n若无账号，请在www.tencent.minecraft.com/buy上花费200元购买","腾讯游戏",MB_YESNO);
 
//wsad控制光标对进行自由选择
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
//防止超出范围
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
			MessageBox(NULL,"单击\"确定\"并输入您的账号和密码进行登录来体验完整版MINECRAFT?\n若无账号，请在www.tencent.minecraft.com/buy上花费200元购买","腾讯游戏",MB_YESNO);
        	y=14;
		}
    }
    pos(0,30);
    white_back();//还原默认字体
    CloseHandle(hOut);//关闭标准输出句柄
    return 0;
}
//设置光标位置
void pos(int x,int y)
{
    COORD posPoint = {x,y}; //设置坐标
    SetConsoleCursorPosition(hOut,posPoint);
}
void blue_border()
{
    WORD blue=FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN;//设置字体颜色、背景颜色
    SetConsoleTextAttribute(hOut,blue);//字体样式
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
        cout<<"单人游戏";
    }
    else if(x==41&&y==18)
    {
        on_Select();
        cout<<"退    出";
    }
    else if(x==41&&y==14)
    {
        on_Select();
        cout<<"多人游戏";
    }
}
void star()
{
    cyan_choose();
    pos(41,10);
    cout<<"单人游戏";
    pos(41,18);
    cout<<"退    出";
    pos(41,14);
    cout<<"多人游戏";
}

