#pragma once
#include "GraphicObject3D.h"

using namespace std;

class ColladaModel :
	public GraphicObject3D
{
	std::vector<double> m_positions;
	std::vector<double> m_normals;
	std::vector<double> m_texCoords;
	int textureId;

public:
	ColladaModel(const char * file);
	~ColladaModel();
	void draw();
	void parseXMLFloatArray(tinyxml2::XMLElement * pFloatArray, std::vector<double>& vector);
	void parseXMLIntArray(tinyxml2::XMLElement * pFloatArray, std::vector<int>& vector);
};

