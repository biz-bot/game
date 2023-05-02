#include "texture.h"
//wwGLuint vs = glCreateShader(GL_VERTEX_SHADER);
//const char* vertexShaderText = "������ � ������� ������� �� ����� GLSL";

//glShaderSource(vs, 1, &vertexShaderText, NULL);
//glCompileShader(vs);

bool    cg_enable = TRUE, sp;      // ������������� ���/���� ��������� Cg, ����� ������?
GLfloat    mesh[SIZE][SIZE][3];    // ���� ����������� ������
GLfloat    wave_movement = 0.0f;   // ���� ���������� ��� �������� ���� ����� ������
CGcontext  cgContext;  // �������� ���������� ����� Cg ���������
CGparameter  position, color, modelViewMatrix, wave; // ��������� ����������� � �������
CGprofile  cgVertexProfile;  // ������� ������������� ������
CGprogram  cgProgram;  // ���� ��������� ��������� Cg
int CgM() {
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);          // �������� ��������� ������



  // ������� ������

	for (int x = 0; x < SIZE; x++)

	{

		for (int z = 0; z < SIZE; z++)

		{

			mesh[x][z][0] = (float)(SIZE / 2) - x; // ����� ������ � ������ ���������

			mesh[x][z][1] = 0.0f;            // ������ ��� �������� Y ��� ���� ����� ������ 0

			mesh[x][z][2] = (float)(SIZE / 2) - z; // ����� ������ � ������ ���������

		}

	}
	// �������� � ���������� ������� �� �����

	cgProgram = cgCreateProgramFromFile(cgContext, CG_SOURCE, "CG/Wave.cg", cgVertexProfile, "main", 0);

	// ��������� Cg

	cgContext = cgCreateContext(); // �������� ������ ��������� ��� ����� Cg ��������



	// �������� ������ ���������, ��� ��� �������

	if (cgContext == NULL)

	{

		MessageBox(NULL, "Failed To Create Cg Context", "Error", MB_OK);

		return FALSE; // ������ ������ ����������

	}
	cgVertexProfile = cgGLGetLatestProfile(CG_GL_VERTEX); // ����� ��������� ������� GL



  // ���������, ��� ��� ������

	if (cgVertexProfile == CG_PROFILE_UNKNOWN)

	{

		MessageBox(NULL, "Invalid profile type", "Error", MB_OK);

		return FALSE; // ������ ������ ����������

	}



	cgGLSetOptimalOptions(cgVertexProfile); // ������ ������� �������
	// ��� �������?

	if (cgProgram == NULL)

	{

		// ���������, ��� �� ���

		CGerror Error = cgGetError();



		// ����� ��������� � ���, ��� ���������.

		MessageBox(NULL, cgGetErrorString(Error), "Error", MB_OK);

		return FALSE; // ������ ������ ����������

	}
	// �������� ���������

	cgGLLoadProgram(cgProgram);

	// �������� ����������� ��� ������� �� ����� ����������, ��� ���

  // �� ����� �������� �� � ����� ����

	position = cgGetNamedParameter(cgProgram, "IN.position");

	color = cgGetNamedParameter(cgProgram, "IN.color");

	wave = cgGetNamedParameter(cgProgram, "IN.wave");

	modelViewMatrix = cgGetNamedParameter(cgProgram, "ModelViewProj");



	//return TRUE; // ������� TRUE (������������� �������)
	cgDestroyContext(cgContext); // ���������� �������� Cg � ��� ��������� � ���

	return 0;
}
int her() {
	
	return 0;
}