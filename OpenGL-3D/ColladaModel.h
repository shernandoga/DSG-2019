#pragma once
#include "GraphicObject3D.h"
#include <vector>
#include "../3rd-party/tinyxml2/tinyxml2.h"

using namespace std;

class ColladaModel :
	public GraphicObject3D
{
	vector<double> m_positions;
	vector<double> m_normals;
	vector<double> m_texCoords;
	int textureId;

public:
	ColladaModel(char* file);
	~ColladaModel();

	void draw();
	void parseXMLFloatArray(tinyxml2::XMLElement *pFloatArray, vector<double> &vector);
	void parseXMLIntArray(tinyxml2::XMLElement *pFloatArray, vector<int> &vector);
};

