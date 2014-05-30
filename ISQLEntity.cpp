/*
 * ISQLEntity.cpp
 *
 *  Created on: 26 mai 2014
 *      Author: SIDI
 */



#include "ISQLEntity.h"
#include <string>
using namespace std;
ISQLEntity::ISQLEntity(ISQLDataClass* dc):fDataClass(dc)
{

}
ISQLDataClass* ISQLEntity::getDataClass() const
{
	return fDataClass;}

