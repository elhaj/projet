/*
 * ISQLAttribute.cpp
 *
 *  Created on: 22 mai 2014
 *      Author: SIDI
 */
#include "ISQLAttribute.h"
#include <string>
using namespace std;

ISQLAttribute::ISQLAttribute(string name,string type, bool primary, bool foreign) :
		fName(name), fType(type), fPrimary(primary), fForeign(foreign) {
}
string ISQLAttribute::getType() {
	return fType;
}

string ISQLAttribute::getName(){
	return fName;
}

bool ISQLAttribute::isPrimaryKey()
{
	return fPrimary;
}

bool ISQLAttribute::isForeignKey()
{
	return fForeign;
}
