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
	static int normal(double *normz, double *PTr1, double *PTr2, double  *PTr3); //расчет нормали
	static 	double Dplane(double *PTr1, double *PTr2, double  *PTr3, double *norm);//расчет D для уравнения плоскости 
	static double Ss(double *vect1, double *vect2);//расчет площади треугольника 
};
class Physics: public Math
{
 public:

	static int stop(WorldScena &coord);// расчет препятствий игроку 
};
class WorldScena: public fileObject
{
public:
	using fileObject::fileObject;
	
	
	int render();//отображения мира
};





 
 void timerfun(int value);

#endif  /*  RENDER_H */