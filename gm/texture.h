#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H
#include "include.h" 
	//#include "includedll.h"
	#include <cg\cg.h>   
	#include <cg\cggl.h> 
	#define    SIZE  64                // ������� ������ ������ �� ��� X/Z
	extern bool    cg_enable , sp;      // ������������� ���/���� ��������� Cg, ����� ������?
	extern GLfloat    mesh[SIZE][SIZE][3];    // ���� ����������� ������
	extern GLfloat    wave_movement;   // ���� ���������� ��� �������� ���� ����� ������
	extern CGcontext  cgContext;  // �������� ���������� ����� Cg ���������
	extern CGparameter  position, color, modelViewMatrix, wave; // ��������� ����������� � �������
	extern CGprofile  cgVertexProfile;  // ������� ������������� ������ ���������� �������
	extern CGprogram  cgProgram;  // ���� ��������� ��������� Cg
#endif 