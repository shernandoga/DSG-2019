#include "Drawable.h"

string Drawable::getName() {
	return name;
}

void Drawable::setName(string pName){
	name = pName;
}

void Drawable::markForDeletion()
{
	m_alive = false;
}

bool Drawable::isAlive()
{
	return m_alive;
}