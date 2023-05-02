#pragma once
#ifndef RENDER_H
#define RENDER_H
#include "include.h" 
#include "file.h"
#include "mouse.h"
#include "key.h"
//#include "light.h"


class WorldScena;

class Math
{
public:
	static int normal(double *normz, double *PTr1, double *PTr2, double  *PTr3); //������ �������
	static 	double Dplane(double *PTr1, double *PTr2, double  *PTr3, double *norm);//������ D ��� ��������� ��������� 
	static double Ss(double *vect1, double *vect2);//������ ������� ������������ 
};
class Physics: public Math
{
 public:

	static int stop(WorldScena &coord);// ������ ����������� ������ 
};
class WorldScena: public fileObject
{
public:
	using fileObject::fileObject;
	
	
	int render();//����������� ����
};





 
 void timerfun(int value);

#endif  /*  RENDER_H */