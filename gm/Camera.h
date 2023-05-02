#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include "mouse.h"
#include "key.h"
class Camera
{
public:
	int lookCamera(KeyButton &key, mouseCoord &mouse);
};

#endif
