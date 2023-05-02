#pragma once
#ifndef LIGHT_H
#define LIGHT_H
#include "include.h"
#include "file.h"
#include "render.h"
#include "mouse.h"
#include "key.h"
class WorldScena;
class Math;

struct vectInfo {
	int ind1;
	int ind2;
	double vec1;
	double vec2;
	double vec3;
	double x;
	double y;
	double z;

};
struct lightSet {
	double x;
	double y; 
	double z; 
	double range; 
	int r;
	int g;
	int b;
};

class light: public Math
{
public:
	light(){

	}
	light(lightSet set, WorldScena &Light) {

		
		lightLine( set, Light);
	}
	~light() {
		
		//delete[] this->vector;
		
	}
	
	bool checkObstacles(vectInfo polyg,  WorldScena &Light); //�������� �� ����������� ����
	bool WallLine(vectInfo funcBool, WorldScena &Light);//�������� �� ��,���   ������� ������� � ���� ����������� � ��������������� �������
	int lightLine(lightSet set,  WorldScena &Light);//������ �����
	
	
private:
	
	
};

#endif