#include "Camera.h"
int Camera::lookCamera(KeyButton &key, mouseCoord &mouse) {
	gluLookAt(key.xtransf, key.ytransf, key.ztransf, mouse.Get_CoordX() + key.xtransf, mouse.Get_CoordY() + key.ytransf, mouse.Get_CoordZ() + key.ztransf, mouse.Get_xnorm(), mouse.Get_ynorm(), mouse.Get_znorm());
	return 0;
}