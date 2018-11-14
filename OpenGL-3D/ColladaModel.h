#pragma once
#include "GraphicObject3D.cpp"
#include <string>
using namespace std;
#include <vector>



class ColladaModel : public GraphicObject3D
{
	vector<double> m_positions;
	vector<double> m_normals;
	vector<double> m_texCoords;
	int textureId;
	vector<int> m_indices;

public:
	ColladaModel(string fileName);
	~ColladaModel();

	virtual void draw() {


		glBegin(GL_TRIANGLES);
		for (int i = 0; i < m_indices; i++) {
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.3, 0.2, 0.5);
			glVertex3f(0.3, 0.8, 0.2);
			//2o triángulo

			glPushMatrix();
			obj1.applyMatrix();
			obj1.draw();
			glPopMatrix();
		}
	
	} 
	void parseXMLFloatArray(tinyxml2::XMLElement *pFloatArray, std::vector<double> &vector);
	void parseXMLIntArray(tinyxml2::XMLElement *pFloatArray, std::vector<int> &vector);
};
