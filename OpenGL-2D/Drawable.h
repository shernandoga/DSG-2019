#pragma once

#include <string>
using namespace std;
class Drawable
{
public:
	virtual void draw() = 0;
	string m_name;

	void setName(string name) { m_name = name; };
	string getName() { return m_name; };
};