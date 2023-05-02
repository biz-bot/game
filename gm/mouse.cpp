#include "mouse.h"

double xrotd = 0, yrotd = 0;
mouseCoord mouse;
int nx , ny;

void mouseactiv(int x, int y) {

	mouse.mouserot(x, y);

}
void mousepassiv(int x, int y) {

	mouse.mouserot(x, y);
	
}
int mouseCoord::mouserot(int x, int y) {
	float radcam = 5.0f;
	double xpoz, ypoz, zpoz;
	double pi = 3.1415926535;
	double windowW = windowWidth;
	double windowH = windowHeight;
	rotx = (pi*(x - windowW / 2) * sensax) / (180) + xrotd;
	roty = ((pi*(-y + windowH / 2) * sensax) / (180) + yrotd);
	xpoz = cos(rotx)*cos(roty)*radcam;
	zpoz = sin(rotx)*cos(roty)*radcam;
	ypoz = -sin(roty)*radcam;
	xnorm = cos(rotx + pi)*sin(roty) ;
	znorm = sin(rotx + pi)*sin(roty);
	ynorm = -cos(roty);
	if (x >= 3 * windowW / 4 || y >= 3 * windowH / 4 || x <= windowW / 4 || y <= windowH / 4) {
		glutWarpPointer(windowW / 2, windowH / 2);
		xrotd = rotx;
		yrotd = roty;
		
		//printf("%f   %f\n", xrotd, yrotd);
	}
	Set_Coord(xpoz, ypoz, zpoz);
	glutPostRedisplay();
	return 0;
}






