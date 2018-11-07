#include "ColladaModel.h"
#include "../3rd-party/tinyxml2/tinyxml2.h"
#include <vector>;
#include "../3rd-party/SOIL/src/SOIL.h"

using namespace std;

ColladaModel::ColladaModel(const char* file)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(file);
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement("COLLADA");

	tinyxml2::XMLElement* pLibraryImages = pRoot->FirstChildElement("library_images");
	tinyxml2::XMLElement* pImage = pLibraryImages->FirstChildElement("image");
	tinyxml2::XMLElement* pInit_form = pImage->FirstChildElement("init_form");

	const char* textureFile = pInit_form->GetText();
	textureId = SOIL_load_OGL_texture(&textureFile[8], 0, 0, 0);

	tinyxml2::XMLElement* pLibraryGeometries = pRoot->FirstChildElement("library_geometries");
	tinyxml2::XMLElement* pGeometry = pLibraryGeometries->FirstChildElement("geometry");
	tinyxml2::XMLElement* pMesh = pGeometry->FirstChildElement("mesh");

	tinyxml2::XMLElement* pSource1 = pMesh->FirstChildElement("source");
	tinyxml2::XMLElement* pFloat_array1 = pSource1->FirstChildElement("float_array");

	tinyxml2::XMLElement* pSource2 = pSource1->NextSiblingElement("source");
	tinyxml2::XMLElement* pFloat_array2 = pSource2->FirstChildElement("float_array");

	tinyxml2::XMLElement* pSource3 = pSource2->NextSiblingElement("source");
	tinyxml2::XMLElement* pFloat_array3 = pSource3->FirstChildElement("float_array");

	tinyxml2::XMLElement* pTriangles = pRoot->FirstChildElement("library_geometries")->FirstChildElement("geometry")->FirstChildElement("mesh")->FirstChildElement("triangles");
	tinyxml2::XMLElement* pP = pRoot->FirstChildElement("library_geometries")->FirstChildElement("geometry")->FirstChildElement("mesh")->FirstChildElement("triangles")->FirstChildElement("p");

	/*
	parseXMLFloatArray(pFloatArray1, m_positions);
	parseXMLFloatArray(pFloatArray2, m_normals);
	parseXMLFloatArray(pFloatArray3, m_texCoords);
	*/
}


ColladaModel::~ColladaModel()
{
}

void ColladaModel::draw() {

}

void ColladaModel::parseXMLFloatArray(tinyxml2::XMLElement *pFloatArray, vector<double> &vector)
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
void ColladaModel::parseXMLIntArray(tinyxml2::XMLElement *pFloatArray, vector<int> &vector)
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