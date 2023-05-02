#pragma once
#ifndef FILE_H
#define FILE_H

#include "include.h" 
class color
{

public:
	color() {}
	color(int R, int G, int B) {
		Set_Color(R, G, B);
	}
	GLdouble Get_ColorR() { return this->ColorR; }
	GLdouble Get_ColorG() { return this->ColorG; }
	GLdouble Get_ColorB() { return this->ColorB; }


	int Set_Color(GLdouble R, GLdouble G, GLdouble B) {
		this->ColorR = R;
		this->ColorG = G;
		this->ColorB = B;
		return 0;
	}


private:
	GLdouble ColorR;
	GLdouble ColorG;
	GLdouble ColorB;


};
class coordinates
{
public:

	
	coordinates() {
		
	}
	GLdouble Get_CoordX() { return this->coordX; }
	GLdouble Get_CoordY() { return this->coordY; }
	GLdouble Get_CoordZ() { return this->coordZ; }
	

	int Set_Coord(GLdouble cor1, GLdouble cor2, GLdouble cor3) { this->coordX = cor1;
																 this->coordY = cor2;
																 this->coordZ = cor3;
	return 0; }

	
private:
	GLdouble coordX;
	GLdouble coordY;
	GLdouble coordZ;
	
};
class polygon
{
public:
	int Get_TrVerX() { return this->TriangleVerticesX; }
	int Get_TrVerY() { return this->TriangleVerticesY; }
	int Get_TrVerZ() { return this->TriangleVerticesZ; }

	int Set_TrVer(int Tv1, int Tv2, int Tv3) {
		this->TriangleVerticesX = Tv1;
		this->TriangleVerticesY = Tv2;
		this->TriangleVerticesZ = Tv3;
		return 0;
	}
	double normal[3];
	bool normalB=false;
private:
	
	int  TriangleVerticesX;
	int  TriangleVerticesY;
	int  TriangleVerticesZ;
};

class model
{
	
public:
	static int count;
	int count_coord;
	int countx;
	
	model() {
		
		count++;
		this->CoordModel = new coordinates[1];
	}
	~model() {
		count--;
		free(this->CoordModel);
		free(this->PolygonNumb);
		free(this->LightColor);
	}
	int Set_Coord(GLdouble cor1, GLdouble cor2, GLdouble cor3, int i) {
		this->CoordModel[i].Set_Coord(cor1, cor2, cor3);
		return 0;
	}

	int Set_TrVer(int Tv1, int Tv2, int Tv3, int i) {
		this->PolygonNumb[i].Set_TrVer(Tv1, Tv2, Tv3);
		return 0;
	}
	int Set_Normal(double Tv1, double Tv2, double Tv3, int i) {
		this->PolygonNumb[i].normal[0] = Tv1;
		this->PolygonNumb[i].normal[1] = Tv2;
		this->PolygonNumb[i].normal[2] = Tv3;
		return 0;
	}
	int Set_NormalBoolTrue() {
		this->PolygonNumb[0].normalB = true;
		return 0;
	}
	int Set_LightColor(GLdouble R, GLdouble G, GLdouble B, int a) {
		this->LightColor[a].Set_Color(R, G, B);
		return 0;
	}
	int MemoryCoord(int i){
		this->CoordModel=(coordinates*)malloc(i * sizeof(coordinates));
		//this->CoordModel = CoordModel2;
		return 0;
	}
	int MemoryPolygon(int i) {
		this->PolygonNumb = (polygon*)malloc(i * sizeof(polygon));
		//this->PolygonNumb = PolygonNumb2;
		return 0;
	}
	int MemoryColor(int i) {
		this->LightColor = (color*)malloc(i * sizeof(color));
		//this->PolygonNumb = PolygonNumb2;
		return 0;
	}
	//int Get_coordX() { return CoordModel.coordX; };
	coordinates Get_coordinates(int c) { return CoordModel[c]; }
	coordinates* Get_coordinatesV() { return CoordModel; }

	polygon Get_PolygonNumb(int c) { return PolygonNumb[c]; }
	polygon* Get_PolygonNumbV() { return PolygonNumb; }
	

	color Get_LightColor(int a) { return this->LightColor[a]; }
	color* Get_LightColorK() { return LightColor; }
	
private:
	coordinates* CoordModel;
	polygon* PolygonNumb;
	color* LightColor;
	
};
class fileObject 
{
public:
	fileObject(){}
	fileObject(const char *file) {
		outfile(file);
	}
	~fileObject() {
		free(modelk);
		
	}
	int outfile(const char *file); 
	int count;
	model* modelk;
	

};



#endif  