#include "ColladaModel.h"
#include "../3rd-party/SOIL/src/SOIL.h"


ColladaModel::ColladaModel(char* file)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(file);
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement("COLLADA");
	tinyxml2::XMLElement* pLibraryImages = pRoot->FirstChildElement("library_images");
	tinyxml2::XMLElement* pImage = pLibraryImages->FirstChildElement("image");
	tinyxml2::XMLElement* pInitFrom = pImage->FirstChildElement("init_from");
	char* nameLong = (char*)pInitFrom->GetText();
	char* name = &(nameLong[8]);
	textureId = SOIL_load_OGL_texture(name,0,0,0);
	
	tinyxml2::XMLElement* pLibraryGeometries = pRoot->FirstChildElement("library_geometries");
	tinyxml2::XMLElement* pGeometry = pLibraryGeometries->FirstChildElement("geometry");
	tinyxml2::XMLElement* pMesh = pGeometry->FirstChildElement("mesh");
	tinyxml2::XMLElement* pSource1 = pMesh->FirstChildElement("source");
	tinyxml2::XMLElement* pFloatArrayPos = pSource1->FirstChildElement("float_array");
	parseXMLFloatArray(pFloatArrayPos,m_positions);

	tinyxml2::XMLElement* pSource2 = pSource1->NextSiblingElement();
	tinyxml2::XMLElement* pFloatArrayNrm = pSource2->FirstChildElement("float_array");
	parseXMLFloatArray(pFloatArrayNrm, m_normals);

	tinyxml2::XMLElement* pSource3 = pSource2->NextSiblingElement();
	tinyxml2::XMLElement* pFloatArrayUV = pSource3->FirstChildElement("float_array");
	parseXMLFloatArray(pFloatArrayUV, m_texCoords);

	tinyxml2::XMLElement* pTriangles = pMesh->FirstChildElement("triangles");
	tinyxml2::XMLElement* pP = pTriangles->FirstChildElement("p");
	char* numbersRandomTrianglesMeow = (char*)pP->GetText();

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