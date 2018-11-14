#include "ColladaModel.h"

#include "../3rd-party/tinyxml2/tinyxml2.h"
#include "../3rd-party/SOIL/src/SOIL.h"

ColladaModel::ColladaModel(string fileName)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile("../OpenGL-3D/Venom.dae");
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement("COLLADA");
	tinyxml2::XMLElement* pLibraryImages = pRoot->FirstChildElement("library_images");
	tinyxml2::XMLElement* pImage = pLibraryImages ->FirstChildElement("image");
	tinyxml2::XMLElement* pInit_From = pImage->FirstChildElement("init_from");
	const char* nameTexture = pInit_From->GetText();

	int TextureID = SOIL_load_OGL_texture(&(nameTexture[8]), 0, 0, 0);

	
	tinyxml2::XMLElement* pLibraryGeometries = pRoot->FirstChildElement("library_geometries");
	tinyxml2::XMLElement* pGeometry = pLibraryGeometries->FirstChildElement("geometry");
	tinyxml2::XMLElement* pMesh = pGeometry->FirstChildElement("mesh");

	tinyxml2::XMLElement* pSourceVenomPos = pMesh->FirstChildElement("source");
	tinyxml2::XMLElement* pVenomPosArray = pSourceVenomPos->FirstChildElement("float_array");
	parseXMLFloatArray(pVenomPosArray, m_positions);

	tinyxml2::XMLElement* pSourceVenomNrm = pSourceVenomPos->NextSibling();
	tinyxml2::XMLElement* pVenomNrmArray = pSourceVenomNrm->FirstChildElement("float_array");
	parseXMLFloatArray(pVenomNrmArray, m_normals);

	tinyxml2::XMLElement* pSourceVenomUV = pSourceVenomNrm->NextSibling();
	tinyxml2::XMLElement* pVenomUVArray = pSourceVenomUV->FirstChildElement("float_array");
	parseXMLFloatArray(pVenomUVArray, m_texCoords);

	tinyxml2::XMLElement* pTriangles = pMesh->FirstChildElement("triangles");
	tinyxml2::XMLElement* pPTri = pTriangles->FirstChildElement("p");
	parseXMLIntArray(pPTri, m_indices);

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