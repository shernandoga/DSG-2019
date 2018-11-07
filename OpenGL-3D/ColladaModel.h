#pragma once
#include "GraphicObject3D.h"

class ColladaModel :
	public GraphicObject3D
{
public:
	ColladaModel(const char* file);
	~ColladaModel();
	void draw();

	void ColladaModel::parseXMLFloatArray(tinyxml2::XMLElement *pFloatArray, std::vector<double> & vector);
	void ColladaModel::parseXMLIntArray(tinyxml2::XMLElement *pFloatArray, std::vector<int> &vector);
};

