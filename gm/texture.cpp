#include "texture.h"
//wwGLuint vs = glCreateShader(GL_VERTEX_SHADER);
//const char* vertexShaderText = "строка с текстом шейдера на языке GLSL";

//glShaderSource(vs, 1, &vertexShaderText, NULL);
//glCompileShader(vs);

bool    cg_enable = TRUE, sp;      // Переключатель Вкл/Выкл программы Cg, Нажат пробел?
GLfloat    mesh[SIZE][SIZE][3];    // Наша статическая модель
GLfloat    wave_movement = 0.0f;   // Наша переменная для смещения волн вдоль модели
CGcontext  cgContext;  // Контекст сохранения нашей Cg программы
CGparameter  position, color, modelViewMatrix, wave; // Параметры необходимые в шейдере
CGprofile  cgVertexProfile;  // Профиль использования нашего
CGprogram  cgProgram;  // Наша вершинная программа Cg
int CgM() {
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);          // Рисовать каркасную модель



  // Создать модель

	for (int x = 0; x < SIZE; x++)

	{

		for (int z = 0; z < SIZE; z++)

		{

			mesh[x][z][0] = (float)(SIZE / 2) - x; // Центр модели в начале координат

			mesh[x][z][1] = 0.0f;            // Задать все значение Y для всех точек равным 0

			mesh[x][z][2] = (float)(SIZE / 2) - z; // Центр модели в начале координат

		}

	}
	// Загрузка и компиляция шейдера из файла

	cgProgram = cgCreateProgramFromFile(cgContext, CG_SOURCE, "CG/Wave.cg", cgVertexProfile, "main", 0);

	// Настройка Cg

	cgContext = cgCreateContext(); // Создание нового контекста для наших Cg программ



	// Проверка нашего контекста, что все успешно

	if (cgContext == NULL)

	{

		MessageBox(NULL, "Failed To Create Cg Context", "Error", MB_OK);

		return FALSE; // Дальше нельзя продолжать

	}
	cgVertexProfile = cgGLGetLatestProfile(CG_GL_VERTEX); // Взять последний профиль GL



  // Проверить, что все хорошо

	if (cgVertexProfile == CG_PROFILE_UNKNOWN)

	{

		MessageBox(NULL, "Invalid profile type", "Error", MB_OK);

		return FALSE; // Дальше нельзя продолжать

	}



	cgGLSetOptimalOptions(cgVertexProfile); // Задать текущий профиль
	// Все успешно?

	if (cgProgram == NULL)

	{

		// Определим, что не так

		CGerror Error = cgGetError();



		// Вывод сообщения с тем, что произошло.

		MessageBox(NULL, cgGetErrorString(Error), "Error", MB_OK);

		return FALSE; // Дальше нельзя продолжать

	}
	// Загрузка программы

	cgGLLoadProgram(cgProgram);

	// Получить дескрипторы для каждого из наших параметров, так как

  // мы будем изменять их в нашем коде

	position = cgGetNamedParameter(cgProgram, "IN.position");

	color = cgGetNamedParameter(cgProgram, "IN.color");

	wave = cgGetNamedParameter(cgProgram, "IN.wave");

	modelViewMatrix = cgGetNamedParameter(cgProgram, "ModelViewProj");



	//return TRUE; // Вернуть TRUE (Инициализация успешна)
	cgDestroyContext(cgContext); // Уничтожить контекст Cg и все программы в нем

	return 0;
}
int her() {
	
	return 0;
}