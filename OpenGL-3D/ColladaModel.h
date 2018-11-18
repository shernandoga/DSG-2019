#pragma once
#include "GraphicObject3D.h"
#include <vector>
#include "../3rd-party/tinyxml2/tinyxml2.h"


class ColladaModel :
	public GraphicObject3D
{
public:

	std::vector<double> m_positions;
	std::vector<double> m_normals;
	std::vector<double> m_texCoords;
	int textureId;

	std::vector<int> m_indexes;

	ColladaModel(const char * file_name);
	~ColladaModel();

	virtual void draw();

	void parseXMLFloatArray(tinyxml2::XMLElement * pFloatArray, std::vector<double>& vector);

	void parseXMLIntArray(tinyxml2::XMLElement * pFloatArray, std::vector<int>& vector);

};

