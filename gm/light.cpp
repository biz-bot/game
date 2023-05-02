#include "light.h"

bool PolygonReplay(double PointVec1[3], double PointVec2[3]);

int light::lightLine(lightSet set,  WorldScena &Light) {
	
	double L;
	vectInfo funcBool;
	
	float R, G, B;
	
	funcBool.x = set.x;
	funcBool.y = set.y;
	funcBool.z = set.z;


	for (int p = 0; p <= Light.count; p++) {
		Light.modelk[p].MemoryColor(Light.modelk[p].count_coord);
		
	}
	for (int p = 0; p <= Light.count; p++) {

		for (int k = 0; k < Light.modelk[p].count_coord; k++)
		{
			
			//LightColor[p][k] = (color*)malloc((3) * sizeof(color));
			funcBool.ind1 = p;
			funcBool.ind2 = k;
			funcBool.vec1 = (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordX()  - set.x);
			funcBool.vec2 = (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordY()  - set.y);
			funcBool.vec3 = (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordZ()  - set.z);


			if (WallLine(funcBool, Light) && checkObstacles(funcBool, Light)){
				L = sqrt((Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordX()  - set.x)*(Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordX()  - set.x) +
						 (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordY()  - set.y)*(Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordY() - set.y) +
						 (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordZ()  - set.z)*(Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordZ()  - set.z));
				if (L > set.range) {
					L = set.range;
				}
				R = set.r - (set.r / set.range)*L;
				G = set.g - (set.g / set.range)*L;
				B = set.b - (set.b / set.range)*L;
				Light.modelk[p].Set_LightColor(R, G, B, Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX());
			}
			else {
				Light.modelk[p].Set_LightColor(30, 30, 30, Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX());
			}
			funcBool.vec1 = (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordX()  - set.x);
			funcBool.vec2 = (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordY()  - set.y);
			funcBool.vec3 = (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordZ()  - set.z);


			if (WallLine(funcBool, Light) && checkObstacles(funcBool, Light)) {
				L = sqrt((Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordX() - set.x)*(Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordX()  - set.x) +
					 	 (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordY()  - set.y)*(Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordY()  - set.y) +
						 (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordZ()  - set.z)*(Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordZ()  - set.z));
				if (L > set.range) {
					L = set.range;
				}
				R = set.r - (set.r / set.range)*L;
				G = set.g - (set.g / set.range)*L;
				B = set.b - (set.b / set.range)*L;
				Light.modelk[p].Set_LightColor(R, G, B, Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY());
			}
			else {
				Light.modelk[p].Set_LightColor(30, 30, 30, Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY());
			}

			funcBool.vec1 = (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordX()  - set.x);
			funcBool.vec2 = (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordY()  - set.y);
			funcBool.vec3 = (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordZ()  - set.z);
			if (WallLine(funcBool, Light) && checkObstacles(funcBool, Light)) {
				
				L = sqrt((Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordX() - set.x)*(Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordX()  - set.x) +
						 (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordY()  - set.y)*(Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordY()  - set.y) +
						 (Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordZ()  - set.z)*(Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordZ()  - set.z));
				
				if (L > set.range) {
					L = set.range;
				}
				R = set.r - (set.r / set.range)*L;
				G = set.g - (set.g / set.range)*L;
				B = set.b - (set.b / set.range)*L;
				Light.modelk[p].Set_LightColor(R, G, B, Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ());
			}
			else {
				Light.modelk[p].Set_LightColor(30, 30, 30, Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ());
			}
		}
	}
	Light.modelk[0];
	//count_coord = N-1;
	//std::cout << N << std::endl;
	
	return 0;
}
bool light::WallLine(vectInfo funcBool, WorldScena &Light) { 
	GLdouble n = 10.0f;
	double norm[3], Point[3], vect1[3], vect2[3],
		PoTr1[3], PoTr2[3], PoTr3[3];
	double D, T;
	//vectInfo func;
	double S1, S2, S3, S, L, cosh;
	double A, B, C;
	double X, Y, Z;
	double K = 0, J = 0, vecbool[2][3];
	double L1, L2;
	int ix = 0;

	

	float radcam = 5.0f;
	if (!Light.modelk[funcBool.ind1].Get_PolygonNumb(0).normalB) {
		PoTr1[0] = Light.modelk[funcBool.ind1].Get_coordinates(Light.modelk[funcBool.ind1].Get_PolygonNumb(funcBool.ind2).Get_TrVerX()).Get_CoordX();
		PoTr2[0] = Light.modelk[funcBool.ind1].Get_coordinates(Light.modelk[funcBool.ind1].Get_PolygonNumb(funcBool.ind2).Get_TrVerY()).Get_CoordX();
		PoTr3[0] = Light.modelk[funcBool.ind1].Get_coordinates(Light.modelk[funcBool.ind1].Get_PolygonNumb(funcBool.ind2).Get_TrVerZ()).Get_CoordX();

		PoTr1[1] = Light.modelk[funcBool.ind1].Get_coordinates(Light.modelk[funcBool.ind1].Get_PolygonNumb(funcBool.ind2).Get_TrVerX()).Get_CoordY();
		PoTr2[1] = Light.modelk[funcBool.ind1].Get_coordinates(Light.modelk[funcBool.ind1].Get_PolygonNumb(funcBool.ind2).Get_TrVerY()).Get_CoordY();
		PoTr3[1] = Light.modelk[funcBool.ind1].Get_coordinates(Light.modelk[funcBool.ind1].Get_PolygonNumb(funcBool.ind2).Get_TrVerZ()).Get_CoordY();

		PoTr1[2] = Light.modelk[funcBool.ind1].Get_coordinates(Light.modelk[funcBool.ind1].Get_PolygonNumb(funcBool.ind2).Get_TrVerX()).Get_CoordZ();
		PoTr2[2] = Light.modelk[funcBool.ind1].Get_coordinates(Light.modelk[funcBool.ind1].Get_PolygonNumb(funcBool.ind2).Get_TrVerY()).Get_CoordZ();
		PoTr3[2] = Light.modelk[funcBool.ind1].Get_coordinates(Light.modelk[funcBool.ind1].Get_PolygonNumb(funcBool.ind2).Get_TrVerZ()).Get_CoordZ();

		normal(norm, PoTr1, PoTr2, PoTr3);
		D = Dplane(PoTr1, PoTr2, PoTr3, norm);
	}
	else {
		norm[0] = Light.modelk[funcBool.ind1].Get_PolygonNumb(funcBool.ind2).normal[0];
		norm[1] = Light.modelk[funcBool.ind1].Get_PolygonNumb(funcBool.ind2).normal[1];
		norm[2] = Light.modelk[funcBool.ind1].Get_PolygonNumb(funcBool.ind2).normal[2];

	}




	if (norm[0] < 0) { vecbool[0][0] = 0; }
	else { vecbool[0][0] = 1; }
	if (norm[1] < 0) { vecbool[0][1] = 0; }
	else { vecbool[0][1] = 1; }
	if (norm[2] < 0) { vecbool[0][2] = 0; }
	else { vecbool[0][2] = 1; }

	if (funcBool.vec1 < 0) { vecbool[1][0] = 0; }
	else { vecbool[1][0] = 1; }
	if (funcBool.vec2 < 0) { vecbool[1][1] = 0; }
	else { vecbool[1][1] = 1; }
	if (funcBool.vec3 < 0) { vecbool[1][2] = 0; }
	else { vecbool[1][2] = 1; }

	if ((norm[0] == 0 || (vecbool[0][0] != vecbool[1][0])) && (norm[1] == 0 || (vecbool[0][1] != vecbool[1][1])) && (norm[2] == 0 || (vecbool[0][2] != vecbool[1][2]))) {
		return true;
	}
	

	return false;
}

bool light::checkObstacles(vectInfo polyg, WorldScena &Light) {
	GLdouble n = 10.0f;
	double norm[3], Points[3] = { 0 }, vect1[3], vect2[3],
		PoTr1[3], PoTr2[3], PoTr3[3],PointVec1[3], PointVec2[3];
	double D1,D2,D3, T1,T2,T3;
	double S1, S2, S3, S, L;
	double A, B, C;
	int M = 0;
	
	for (int p = 0; p <= Light.count; p++)
	{

		for (int k = 0; k < Light.modelk[p].count_coord; k++)
		{
			/*PointVec1[0] = Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX();
			PointVec1[1] = Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY();
			PointVec1[2] = Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ();

			PointVec2[0] = Light.modelk[polyg.ind1].Get_PolygonNumb(polyg.ind2).Get_TrVerX();
			PointVec2[1] = Light.modelk[polyg.ind1].Get_PolygonNumb(polyg.ind2).Get_TrVerY();
			PointVec2[2] = Light.modelk[polyg.ind1].Get_PolygonNumb(polyg.ind2).Get_TrVerZ();*/
			

			PoTr1[0] = Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordX();
			PoTr2[0] = Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordX();
			PoTr3[0] = Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordX();



			PoTr1[1] = Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordY();
			PoTr2[1] = Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordY();
			PoTr3[1] = Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordY();


			PoTr1[2] = Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordZ();
			PoTr2[2] = Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordZ();
			PoTr3[2] = Light.modelk[p].Get_coordinates(Light.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordZ();
					
						

				
			norm[0] = Light.modelk[p].Get_PolygonNumb(k).normal[0];
			norm[1] = Light.modelk[p].Get_PolygonNumb(k).normal[1];
			norm[2] = Light.modelk[p].Get_PolygonNumb(k).normal[2];

			


			D2 = Dplane(PoTr1, PoTr2, PoTr3, norm);
			//T2 = -(norm[0] * Point[0] + norm[1] * Point[1] + norm[2] * Point[2] + D2) / (norm[0] * norm[0] + norm[1] * norm[1] + norm[2] * norm[2]);
			T2 = -(norm[0] * polyg.x + norm[1] * polyg.y + norm[2] * polyg.z + D2) / (norm[0] * polyg.vec1 + norm[1] * polyg.vec2 + norm[2] * polyg.vec3);


			Points[0] = polyg.vec1*T2 + polyg.x;
			Points[1] = polyg.vec2*T2 + polyg.y;
			Points[2] = polyg.vec3*T2 + polyg.z;
			
			vect1[0] = PoTr3[0] - PoTr2[0];
			vect1[1] = PoTr3[1] - PoTr2[1];
			vect1[2] = PoTr3[2] - PoTr2[2];

			vect2[0] = Points[0] - PoTr2[0];
			vect2[1] = Points[1] - PoTr2[1];
			vect2[2] = Points[2] - PoTr2[2];
			S1 = Ss(vect1, vect2);

			vect1[0] = PoTr3[0] - PoTr1[0];
			vect1[1] = PoTr3[1] - PoTr1[1];
			vect1[2] = PoTr3[2] - PoTr1[2];

			vect2[0] = Points[0] - PoTr1[0];
			vect2[1] = Points[1] - PoTr1[1];
			vect2[2] = Points[2] - PoTr1[2];
			S2 = Ss(vect1, vect2);

			vect1[0] = PoTr2[0] - PoTr1[0];
			vect1[1] = PoTr2[1] - PoTr1[1];
			vect1[2] = PoTr2[2] - PoTr1[2];

			vect2[0] = Points[0] - PoTr1[0];
			vect2[1] = Points[1] - PoTr1[1];
			vect2[2] = Points[2] - PoTr1[2];
			S3 = Ss(vect1, vect2);

			vect1[0] = PoTr2[0] - PoTr1[0];
			vect1[1] = PoTr2[1] - PoTr1[1];
			vect1[2] = PoTr2[2] - PoTr1[2];

			vect2[0] = PoTr3[0] - PoTr1[0];
			vect2[1] = PoTr3[1] - PoTr1[1];
			vect2[2] = PoTr3[2] - PoTr1[2];
			S = Ss(vect1, vect2);

			A = S1 / S;
			B = S2 / S;
			C = S3 / S;

			if (A >= 0 && A <= 1 && B >= 0 && B <= 1 && C >= 0 && C <= 1 && T2 < 1) {
				return false;
			}
		}
		
				
		
	}
	return true;
}

bool PolygonReplay(double PointVec1[3],double PointVec2[3]) {
	if ((PointVec1[0]== PointVec2[0] || PointVec1[0]== PointVec2[1] || PointVec1[0]== PointVec2[2]) || 
		(PointVec1[1] == PointVec2[0] || PointVec1[1] == PointVec2[1] || PointVec1[1] == PointVec2[2])||
		(PointVec1[2] == PointVec2[0] || PointVec1[2] == PointVec2[1] || PointVec1[2] == PointVec2[2])  ) {
		return false;
	}
	return true;
}