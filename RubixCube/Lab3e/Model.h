#ifndef _MODEL_H_
#define _MODEL_H_


// INCLUDES //
#include <Windows.h>
#include <fstream>
using namespace std;

// MY CLASS INCLUDES //
#include "TokenStream.h"
#include <vector>
#include "Vec3.h"
#include "SOIL.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include "Shape.h"

class Model
{

	public:
		bool Load(char*, char*);
		void Render(float x, float y, float z, float width, float height, float depth, int rot);
		enum Rot{ front, up, right, diagonal, flipped };
	private:
	
		void LoadTexture(char*);
		bool LoadModel(char*);
		
		Shape shape;
		int m_vertexCount;
		GLuint texture;

		// vectors for storing model data, for your use
		vector<float> vertex, normals, texCoords;
		
	
};

#endif