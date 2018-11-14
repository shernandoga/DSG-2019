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

	vector<int> m_indices;

public:
	ColladaModel(const char * file);
	~ColladaModel();
	void draw();
	void parseXMLFloatArray(tinyxml2::XMLElement * pFloatArray, std::vector<double>& vector);
	void parseXMLIntArray(tinyxml2::XMLElement * pFloatArray, std::vector<int>& vector);
};

