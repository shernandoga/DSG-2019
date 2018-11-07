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

public:
	ColladaModel(string fileName);
	~ColladaModel();

	virtual void draw() {} 
	void parseXMLFloatArray(tinyxml2::XMLElement *pFloatArray, std::vector<double> &vector);
	void parseXMLIntArray(tinyxml2::XMLElement *pFloatArray, std::vector<int> &vector);
};
