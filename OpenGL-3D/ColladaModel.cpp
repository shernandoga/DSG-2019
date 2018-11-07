#include "ColladaModel.h"
#include "../3rd-party/tinyxml2/tinyxml2.h"
#include <vector>


ColladaModel::ColladaModel(const char* file)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(file);
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement(COLLADA);
	tinyxml2::XMLElement* pLibraryImages = pRoot->FirstChildElement(library_images);
}


ColladaModel::~ColladaModel()
{
}

void ColladaModel::draw() {

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

