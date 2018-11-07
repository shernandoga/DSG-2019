#include "ColladaModel.h"
#include "tinyxml2/tinyxml2.h"
#include "Debug/tinyxml2.lib"
#include "../3rd-party/SOIL/src/SOIL.h"

ColladaModel::ColladaModel(string fileName)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(filename.c_str);
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement(“COLLADA”);
	tinyxml2::XMLElement* pLibraryImages = pRoot->FirstChildElement(“library_images”);
	tinyxml2::XMLElement* pImage = pLibraryImages ->FirstChildElement(“image”);
	tinyxml2::XMLElement* pInit_From = pImage->FirstChildElement(“init_from”);
	Const char* name = pInit_From->GetText();

	int TextureID = SOIL_load_OGL_texture(&(name[8]), 0, 0, 0);

	
	tinyxml2::XMLElement* pLibraryGeometries = pRoot->FirstChildElement(“library_geometries”);
	tinyxml2::XMLElement* pGeometry = pLibraryGeometries->FirstChildElement(“geometry”);
	tinyxml2::XMLElement* pMesh = pGeometry->FirstChildElement(“mesh”);
	tinyxml2::XMLElement* pSourceVenomPos = pGeometry->FirstChildElement(“source”);
	while(!null)
	{
		pSourceVenomPos->NextSibling();
	}
	








}


ColladaModel::~ColladaModel()
{
}


void ColladaModel::parseXMLFloatArray(tinyxml2::XMLElement *pFloatArray, std::vector<double> &vector)
{
	char* pCharArray = (char*)pFloatArray->GetText();
	char* nextToken;
	char* pt = strtok_s(pCharArray, " ", &nextToken);
	while (pt != 0)
	{
		vector.push_back(atof(pt));
		pt = strtok_s(0, " ", &nextToken);
	}
}


void ColladaModel::parseXMLIntArray(tinyxml2::XMLElement *pFloatArray, std::vector<int> &vector)
{
	char* pCharArray = (char*)pFloatArray->GetText();
	char* nextToken;
	char* pt = strtok_s(pCharArray, " ", &nextToken);
	while (pt != 0)
	{
		vector.push_back(atoi(pt));
		pt = strtok_s(0, " ", &nextToken);
	}
}