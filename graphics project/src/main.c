#include "graphics.h"
#include "genlib.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include <math.h>//���Ǻ��� 

#define PI 3.14159265
double deg = 0; //����Ƕȣ�Ϊ�Ƕ��� 

void forward(double distance);//�ص�ǰ����ֱ�ߣ�����Ϊdistance����distanceΪ������ʱ����ˣ� 
void turn(double angle);//˳ʱ����ת�Ƕ�Ϊangle���Ƕȵ�λΪdeg����angleΪ��ʱ��ʱ����ת�� 
void move(double distance);//�ص�ǰ�����ƶ��ʣ������ߣ�������Ϊdistance����distanceΪ��ʱ���ˣ� 
void Drawsix();//��һ�������Σ��⣩ 
void Drawinner();//���ڲ�����״

 
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    InitConsole();
}

void Main()
{
    double cx, cy;
    double tx, ty;
    
    InitGraphics();

    SetPenColor("Green"); 
    SetPenSize(2);
    
    Drawsix();
    turn(20);
    Drawsix();
    turn(20);
    Drawsix();//���������
	
	
	turn(-40);
	Drawinner();//����һ������ 
	int j = 0;
	while(j < 5)
	{
	turn(-90);
	Drawinner();
    j++;
    }//ѭ����� 
    
    
     
    turn(70);
	Drawinner();
	j = 0;
	while(j < 5)
	{
	turn(-90);
	Drawinner();
    j++;
    }
    
    
    
    turn(70);
	Drawinner();
	j = 0;
	while(j < 5)
	{
	turn(-90);
	Drawinner();
    j++;
    }
}


void forward(double distance)
{
	double x,ret,val;
	x = deg;//��ǰ�ĽǶ�
	val = PI/180;
	ret = x*val;//���Ƕ�ֵ��Ϊ����
	
	double sinx,cosx;
	sinx = sin(ret);
	cosx = cos(ret);
	DrawLine(cosx*distance,sinx*distance); 
}

void turn(double angle)
{
	deg = deg - angle;
}

void move(double distance)
{
	double tx = GetCurrentX();
	double ty = GetCurrentY();
	
	double x,ret,val;
	x = deg;//��ǰ�ĽǶ�
	val = PI/180;
	ret = x*val;//���Ƕ�ֵ��Ϊ����
	
	double sinx,cosx;
	sinx = sin(ret);
	cosx = cos(ret);
	
	MovePen(tx+cosx*distance,ty+sinx*distance);
}

void Drawsix()
{
	MovePen(5.0,4.0);
	turn(-90);
	move(2);
	turn(60);
	int i = 0;
	while(i < 6)
	{	
	turn(60);
	forward(2);
	i++;
    }
    turn(120);
    move(2);
    turn(-90);
}

void Drawinner()//��һ������ 
{
	MovePen(5.0,4.0);
	turn(-90);
	forward(1);
	turn(60);
	forward(1);
	turn(120);
	forward(1);
	turn(60);
	forward(1);
}
