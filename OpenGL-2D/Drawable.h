#pragma once
#include <string>
using namespace std;

class Drawable
{
	string name;
public:
	virtual void draw() = 0;
	string getName();
	void setName(string name);
};