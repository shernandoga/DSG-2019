#include "ColladaModel.h"
#include <vector>
#include <string>
#include "../3rd-party/SOIL/src/SOIL.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include <iostream>



using namespace std;

ColladaModel::ColladaModel(const char* file_name)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(file_name);

	// xml path -> COLLADA / library_images / image / init_from
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement("COLLADA");
	tinyxml2::XMLElement* pLibraryImages = pRoot->FirstChildElement("library_images");
	const char* initFrom = pLibraryImages
		->FirstChildElement("image")
		->FirstChildElement("init_from")
		->GetText();

	cout << "FileName: " << &(initFrom[8]) << "\n";

	SOIL_load_OGL_texture(&(initFrom[8]), 0, 0, 0);

	// xml path -> COLLADA / library_geometries / geometry / mesh / source
	tinyxml2::XMLElement* pLibraryGeometries = pRoot->FirstChildElement("library_geometries");
	tinyxml2::XMLElement* source = pLibraryGeometries
		->FirstChildElement("geometry")
		->FirstChildElement("mesh")
		->FirstChildElement("source");

	while (source != nullptr)
	{
		const char * name = source->Attribute("name");
		tinyxml2::XMLElement *pFloatArray = source->FirstChildElement("float_array");
		
		if (strcmp(name, "venomPos") == 0) 
		{
			ColladaModel::parseXMLFloatArray(pFloatArray, m_positions);
		}
		else if (strcmp(name, "venomNrm") == 0) 
		{
			ColladaModel::parseXMLFloatArray(pFloatArray, m_normals);
		}
		else if (strcmp(name, "venomUV") == 0) 
		{
			ColladaModel::parseXMLFloatArray(pFloatArray, m_texCoords);
		}

		source = source->NextSiblingElement("source");
	}


	// xml path -> COLLADA / library_geometries / geometry / mesh / triangles / p
	source = pLibraryGeometries
		->FirstChildElement("geometry")
		->FirstChildElement("mesh")
		->FirstChildElement("triangles");
	tinyxml2::XMLElement *pIntArray = source->FirstChildElement("p");
	ColladaModel::parseXMLIntArray(pIntArray, m_indexes);

}


ColladaModel::~ColladaModel()
{
}

void ColladaModel::draw()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	//glEnable(GL_BLEND);

	glEnable(GL_TEXTURE_2D);

	glPushMatrix();

	glTranslatef(m_x, m_y, 0);
	glScalef(0.20, 0.20, 1);
	glRotatef(270, 1, 0, 0);

	glBegin(GL_TRIANGLES);
	
	for (int i=0; i<m_indexes.size(); i++)
	{
		int pos = m_indexes[i] * 3;
		int tex = m_indexes[i] * 2;
		if ((pos + 2) < m_positions.size())
		{
			glNormal3f(
				m_normals[pos],
				m_normals[pos + 1],
				m_normals[pos + 2]);
		}
		if ((tex + 1) < m_positions.size())
		{
			glTexCoord2f(
				m_texCoords[tex],
				//(m_texCoords[tex + 1])
				(1 - m_texCoords[tex + 1])
			);
		}
		if ((pos + 2) < m_positions.size())
		{
			glVertex3f(
				m_positions[pos],
				m_positions[pos + 1],
				m_positions[pos + 2]);
			
		}
	}
	
	glEnd();

	glPopMatrix();
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
