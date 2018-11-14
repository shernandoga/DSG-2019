#pragma once
#include "GraphicObject3D.cpp"
#include <string>
#include <vector>
using namespace std;
namespace tinyxml2 { class XMLElement; }

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

	virtual void draw();
	void parseXMLFloatArray(tinyxml2::XMLElement *pFloatArray, vector<double> &vector);
	void parseXMLIntArray(tinyxml2::XMLElement *pFloatArray, vector<int> &vector);
};
