#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H
#include "include.h" 
	//#include "includedll.h"
	#include <cg\cg.h>   
	#include <cg\cggl.h> 
	#define    SIZE  64                // Зададим размер модели по оси X/Z
	extern bool    cg_enable , sp;      // Переключатель Вкл/Выкл программы Cg, Нажат пробел?
	extern GLfloat    mesh[SIZE][SIZE][3];    // Наша статическая модель
	extern GLfloat    wave_movement;   // Наша переменная для смещения волн вдоль модели
	extern CGcontext  cgContext;  // Контекст сохранения нашей Cg программы
	extern CGparameter  position, color, modelViewMatrix, wave; // Параметры необходимые в шейдере
	extern CGprofile  cgVertexProfile;  // Профиль использования нашего вершинного шейдера
	extern CGprogram  cgProgram;  // Наша вершинная программа Cg
#endif 