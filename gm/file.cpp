#define _CRT_SECURE_NO_WARNINGS

#include "file.h" 

int clear(char N[100]) {
	for (int i = 0; i < 100; i++) {
		N[i] = '\0';
	}
	return 0;
}
int fileObject::outfile(const char *file) {
	char opcode;
	char N[100] = { 0 };
	char Vec[14] = "*MESH_VERTEX ", Face[] = "*MESH_FACE ", Normal[] = "*MESH_FACENORMAL ", NumVec[] = "*MESH_NUMVERTEX ", NumFaces[] = "*MESH_NUMFACES ";
	float Pt[10];
	float del = 10.0f;
	bool vc[5] = { false }, Wr = true, nm = false;
	FILE *f1 = NULL;
	modelk= (model*)malloc(1 * sizeof(model));

	f1 = fopen(file, "r+");


	if (f1 == NULL) {
		std::cout << "file not open" << std::endl;
		exit(1);
		return 0;
	}
	
	
	int  stb = 0;
	double xy = 0, xc = -100, yc = -100;
	int input, numb, born = 0, ch = 0, In = 0,ModelNum=-1;
	bool toc = false;
	int min = 1 , count_Vertices, count_Faces, count_Normal;

	while (!feof(f1)) {
		fscanf(f1, "%c", &opcode);

 		if (toc) {
			born++;
		}
		if (isdigit(opcode) != 0) {
			xy *= 10;
			xy += opcode - '0';
			nm = true;
		}
		else {

			N[ch] = opcode;
			ch++;
		}
		
		

		switch (opcode)
		{

		case '-':
			min = -1;
			break;
		case ' ':
		case '\t':
		
			born--;
			
			
			N[ch] = '\0';
			if (strcmp(N, Vec) == 0) {
				vc[0] = true;
				vc[1] = false;
				vc[2] = false;
				vc[3] = false;
				vc[4] = false;
				Wr = false;
				
			}
			if (strcmp(N, Face) == 0) {
				vc[0] = false;
				vc[1] = true;
				vc[2] = false;
				vc[3] = false;
				vc[4] = false;
				Wr = false;
			}
			if (strcmp(N, Normal) == 0) {
				vc[0] = false;
				vc[1] = false;
				vc[2] = true;
				vc[3] = false;
				vc[4] = false;
				Wr = false;
				modelk->Set_NormalBoolTrue();
			}
			if (strcmp(N, NumVec) == 0) {
				vc[0] = false;
				vc[1] = false;
				vc[2] = false;
				vc[3] = true;
				vc[4] = false;
				Wr = true;
				ModelNum++;
				modelk = (model*)realloc(modelk, (1 + ModelNum) * sizeof(model));

			}
			
			if (strcmp(N, NumFaces) == 0) {
				vc[0] = false;
				vc[1] = false;
				vc[2] = false;
				vc[3] = false;
				vc[4] = true;
				Wr = true;
			}
			if (Wr) {
				Pt[stb] = xy;
			}
			else {
				

					if (born <= 0) {
						Pt[stb] = min * xy;
					}
					else {
						Pt[stb] = min * (xy / double(pow(10, (born))));
					}
				
			}
			if (nm) {
				stb++;
				

			}
			nm = false;
			toc = false;
			
			ch = 0;
			born = 0;
			min = 1;
			clear(N);
			xy = 0;
			break;
		case '.':
			toc = true;
			break;

		case '\n':
			born--;
			

			if (born <= 0) {
				Pt[stb] = min * xy;
			}
			else {
				Pt[stb] = min * (xy / double(pow(10, born)));
			}

			if (Wr == false) {
				if (vc[0] && Pt[0] < count_Vertices) {
					modelk[ModelNum].Set_Coord(Pt[1]/ del, Pt[3]/ del, Pt[2]/ del, Pt[0]);
					float b= modelk[0].Get_coordinates(2).Get_CoordX();
					vc[0] = false;

				}
				if (vc[1] && Pt[0] < count_Faces) {
					modelk[ModelNum].Set_TrVer(Pt[1], Pt[3], Pt[2], Pt[0]);
					vc[1] = false;
				}
				if (vc[2] && Pt[0] < count_Faces) {
					modelk[ModelNum].Set_Normal(Pt[1],Pt[3], Pt[2], Pt[0]);
					vc[2] = false;

				}
				

			}
			else {
				
				if (vc[3]) {
					
					modelk[ModelNum].MemoryCoord(Pt[0]);
					count_Vertices = Pt[0];
					vc[3] = false;
				}
				if (vc[4]) {
					modelk[ModelNum].MemoryPolygon(Pt[0]);
					count_Faces = Pt[0];
					modelk[ModelNum].count_coord = Pt[0];
					vc[4] = false;
				}

			}
			
			toc = false;
			Wr = false;
			nm = false;
			stb = 0;
			born = 0;
			min = 1;
			xy = 0;
			ch = 0;
			clear(N);
			//std::cout << std::endl;
			break;
		
		}
		


	}
	count = ModelNum;
	
	return 0;
}