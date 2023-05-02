#include "render.h"

bool blokOxy[4];
int Uv=100,Ux=100;



int WorldScena::render() {
	GLbyte *pB;
	GLuint texture;
	GLint lW, lH, lC;
	//glGenTextures(1, &texture);
	//glBindTexture(GL_TEXTURE_2D, texture);

	const char textur[5][20] = { "texture/plane.tga\0","texture/xxx.tga\0,","texture/box.tga\0","texture/box.tga\0","texture/box1.tga\0" };
	GLenum lF;
	int i = 0;
	int k = 0;
	int p = 0;
	double vN;
	double norm[3];
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_MULTISAMPLE);
	glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
	/*glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH, GL_NICEST);
	*/
	//glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);

	GLTMatrix trans;
	//glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	for (int i = 0; i <= count;i++) 
	{
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		pB = gltLoadTGA(textur[i], &lW, &lH, &lC, &lF);
		glTexImage2D(GL_TEXTURE_2D, 0, lC, lW, lH, 0, lF, GL_UNSIGNED_BYTE, pB);
		free(pB);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
		
		
		for (int ic = 0; ic < modelk[i].count_coord; ic++) 
			{
		
			//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


			norm[0] = modelk[i].Get_PolygonNumb(ic).normal[0];
			norm[2] = modelk[i].Get_PolygonNumb(ic).normal[1];
			norm[1] = modelk[i].Get_PolygonNumb(ic).normal[2];
			glNormal3d(norm[0], norm[1], norm[2]);		
			
			glPushMatrix();
			
			glBegin(GL_TRIANGLES);
			
			
			glColor4ub(modelk[i].Get_LightColor(modelk[i].Get_PolygonNumb(ic).Get_TrVerX()).Get_ColorR(),
					   modelk[i].Get_LightColor(modelk[i].Get_PolygonNumb(ic).Get_TrVerX()).Get_ColorG(),
					   modelk[i].Get_LightColor(modelk[i].Get_PolygonNumb(ic).Get_TrVerX()).Get_ColorB(),255);
			glTexCoord2d(0.5 , 1.0);
			
			
			glVertex3d(modelk[i].Get_coordinates(modelk[i].Get_PolygonNumb(ic).Get_TrVerX()).Get_CoordX(),
					   modelk[i].Get_coordinates(modelk[i].Get_PolygonNumb(ic).Get_TrVerX()).Get_CoordY() ,
					   modelk[i].Get_coordinates(modelk[i].Get_PolygonNumb(ic).Get_TrVerX()).Get_CoordZ() );

			glColor4ub(modelk[i].Get_LightColor(modelk[i].Get_PolygonNumb(ic).Get_TrVerY()).Get_ColorR(),
					   modelk[i].Get_LightColor(modelk[i].Get_PolygonNumb(ic).Get_TrVerY()).Get_ColorG(),
					   modelk[i].Get_LightColor(modelk[i].Get_PolygonNumb(ic).Get_TrVerY()).Get_ColorB(), 255);

			glTexCoord2d(0.0 , 0.0 );
			
			glVertex3d(modelk[i].Get_coordinates(modelk[i].Get_PolygonNumb(ic).Get_TrVerY()).Get_CoordX() ,
					   modelk[i].Get_coordinates(modelk[i].Get_PolygonNumb(ic).Get_TrVerY()).Get_CoordY() ,
					   modelk[i].Get_coordinates(modelk[i].Get_PolygonNumb(ic).Get_TrVerY()).Get_CoordZ() );


			glColor4ub(modelk[i].Get_LightColor(modelk[i].Get_PolygonNumb(ic).Get_TrVerZ()).Get_ColorR(),
					   modelk[i].Get_LightColor(modelk[i].Get_PolygonNumb(ic).Get_TrVerZ()).Get_ColorG(),
					   modelk[i].Get_LightColor(modelk[i].Get_PolygonNumb(ic).Get_TrVerZ()).Get_ColorB(), 255);

			glTexCoord2d(1.0 , 0.0 );
			
			glVertex3d(modelk[i].Get_coordinates(modelk[i].Get_PolygonNumb(ic).Get_TrVerZ()).Get_CoordX(),
					   modelk[i].Get_coordinates(modelk[i].Get_PolygonNumb(ic).Get_TrVerZ()).Get_CoordY() ,
					   modelk[i].Get_coordinates(modelk[i].Get_PolygonNumb(ic).Get_TrVerZ()).Get_CoordZ());
			k++;
			glEnd();
			glPopMatrix();
		}
		
		p++;
		k = 0;
	}
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	return 0;
}

void timerfun(int value) {

	
	//stop();
	//keys();
	//stop();
	
	glutPostRedisplay();
	glutTimerFunc(1, timerfun, 1);
}

int Math::normal(double *normz,double *PTr1, double *PTr2, double  *PTr3) {

	normz[0] = (PTr2[1] - PTr1[1])*(PTr3[2] - PTr1[2]) - (PTr3[1] - PTr1[1])*(PTr2[2] - PTr1[2]);
	normz[1] = -((PTr2[0] - PTr1[0])*(PTr3[2] - PTr1[2]) - (PTr3[0] - PTr1[0])*(PTr2[2] - PTr1[2]));
	normz[2] = (PTr2[0] - PTr1[0])*(PTr3[1] - PTr1[1]) - (PTr3[0] - PTr1[0])*(PTr2[1] - PTr1[1]);
	
	//glNormal3d(normz[0], normz[1], normz[2]);
	return 0;
}
double Math::Dplane(double *PTr1, double *PTr2, double  *PTr3, double *norm) {
	double D,D1,D2,D3;
	D = -PTr1[0] * (PTr2[1] - PTr1[1])*(PTr3[2] - PTr1[2]) -
		PTr1[2] * (PTr2[0] - PTr1[0])*(PTr3[1] - PTr1[1]) -
		PTr1[1] * (PTr2[2] - PTr1[2])*(PTr3[0] - PTr1[0]) +
		PTr1[2] * (PTr3[0] - PTr1[0])*(PTr2[1] - PTr1[1]) +
		PTr1[1] * (PTr2[0] - PTr1[0])*(PTr3[2] - PTr1[2]) +
		PTr1[0] * (PTr3[1] - PTr2[1])*(PTr2[2] - PTr1[2]);
	D1 = -(norm[0] * PTr1[0] + norm[1] * PTr1[1] + norm[2] * PTr1[2]);
	D2 = -(norm[0] * PTr2[0] + norm[1] * PTr2[1] + norm[2] * PTr2[2]);
	D3 = -(norm[0] * PTr3[0] + norm[1] * PTr3[1] + norm[2] * PTr3[2]);

	if (abs(D1 - D2) < 0.001 && abs(D1 - D3) < 0.001) {
		return D1;
	}
	
	return D;
}
double Math::Ss(double *vect1, double *vect2) {
	double S;
	S = sqrt((vect1[1] * vect2[2] - vect2[1] * vect1[2])*(vect1[1] * vect2[2] - vect2[1] * vect1[2]) +
		(vect1[0] * vect2[2] - vect2[0] * vect1[2])*(vect1[0] * vect2[2] - vect2[0] * vect1[2]) +
		(vect1[0] * vect2[1] - vect2[0] * vect1[1])*(vect1[0] * vect2[1] - vect2[0] * vect1[1]))/2 ;
	return S;
}

int Physics::stop(WorldScena &coord) {
	double norm[3], Point[3], vect1[3], vect2[3],
	PoTr1[3], PoTr2[3], PoTr3[3];
	double D,T;

	double S1, S2, S3, S,L,cosh;
	double A, B, C;
	double X, Y, Z;
	double K=0,J=0;
	double L1, L2;
	int ix = 0;
	
	float radcam = 5.0f;

	for (int p = 0; p <= coord.count; p++) {
		
		for (int k = 0; k < coord.modelk[p].count_coord; k++)
		{
			
			PoTr1[0] = coord.modelk[p].Get_coordinates(coord.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordX() ;
			PoTr2[0] = coord.modelk[p].Get_coordinates(coord.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordX() ;
			PoTr3[0] = coord.modelk[p].Get_coordinates(coord.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordX();

			PoTr1[1] = coord.modelk[p].Get_coordinates(coord.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordY() ;
			PoTr2[1] = coord.modelk[p].Get_coordinates(coord.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordY() ;
			PoTr3[1] = coord.modelk[p].Get_coordinates(coord.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordY() ;



			PoTr1[2] = coord.modelk[p].Get_coordinates(coord.modelk[p].Get_PolygonNumb(k).Get_TrVerX()).Get_CoordZ();
			PoTr2[2] = coord.modelk[p].Get_coordinates(coord.modelk[p].Get_PolygonNumb(k).Get_TrVerY()).Get_CoordZ() ;
			PoTr3[2] = coord.modelk[p].Get_coordinates(coord.modelk[p].Get_PolygonNumb(k).Get_TrVerZ()).Get_CoordZ() ;
				
				
			

			
		
			normal(norm, PoTr1, PoTr2, PoTr3);
			D = Dplane(PoTr1, PoTr2, PoTr3,norm);
			
			T = -(norm[0] * but.xtransf + norm[1] * but.ytransf + norm[2] * but.ztransf + D) / (norm[0] * norm[0] + norm[1] * norm[1] + norm[2] * norm[2]);

			Point[0] = norm[0] * T + but.xtransf;
			Point[1] = norm[1] * T + but.ytransf;
			Point[2] = norm[2] * T + but.ztransf;
			
			vect1[0] = PoTr3[0] - PoTr2[0];
			vect1[1] = PoTr3[1] - PoTr2[1];
			vect1[2] = PoTr3[2] - PoTr2[2];

			vect2[0] = Point[0] - PoTr2[0];
			vect2[1] = Point[1] - PoTr2[1];
			vect2[2] = Point[2] - PoTr2[2];
			S1 = Ss(vect1, vect2);

			vect1[0] = PoTr3[0] - PoTr1[0];
			vect1[1] = PoTr3[1] - PoTr1[1];
			vect1[2] = PoTr3[2] - PoTr1[2];

			vect2[0] = Point[0] - PoTr1[0];
			vect2[1] = Point[1] - PoTr1[1];
			vect2[2] = Point[2] - PoTr1[2];
			S2 = Ss(vect1, vect2);

			vect1[0] = PoTr2[0] - PoTr1[0];
			vect1[1] = PoTr2[1] - PoTr1[1];
			vect1[2] = PoTr2[2] - PoTr1[2];

			vect2[0] = Point[0] - PoTr1[0];
			vect2[1] = Point[1] - PoTr1[1];
			vect2[2] = Point[2] - PoTr1[2];
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

			L = sqrt((Point[0] - but.xtransf)*(Point[0] - but.xtransf) + (Point[1] - but.ytransf)*(Point[1] - but.ytransf) + (Point[2] - but.ztransf)*(Point[2] - but.ztransf));
			
			if (A >= 0 && A <= 1 && B >= 0 && B <= 1 && C >= 0 && C <= 1 && L <= radcam / 2) {
				
				X = (Point[0] - but.xtransf);
				Y = (Point[1] - but.ytransf);
				Z = (Point[2] - but.ztransf);
				if (X == 0 && Y == 0 && Z == 0) {
					/*but.xtransf += 30;
					but.ytransf += 10;
					but.ztransf += 30;*/
				}
					
				else {
					while (L <= radcam / 2) {

						
						L = sqrt((Point[0] - (but.xtransf + K * X))*(Point[0] - (but.xtransf + K * X)) + (Point[1] - (but.ytransf + K * Y))*(Point[1] - (but.ytransf + K * Y)) + (Point[2] - (but.ztransf + K * Z))*(Point[2] - (but.ztransf + K * Z)));
						K -= 0.001;

						
					}
					but.xtransf += K * X;
					but.ytransf += K * Y;
					but.ztransf += K * Z;
				
				
					
				}
				
				
				K = 0;
				}
			
			

			
		}
		
		
		
	}
	return 0;
}
