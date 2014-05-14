/*
 * EntityManager.cpp
 *
 *  Created on: 13 mai 2014
 *      Author: SIDI
 */

#include "EntityManager.h"
#include <string>;
#include "windows.h"
#include "sql.h"
#include "sqltypes.h"
#include "sqlext.h"


using namespace std;
IVersion* EntityManager::getVersion(ISQLEntity* entity) {
	return id_version[entity->getId()];
}


bool EntityManager::save(ISQLEntity* entity, string tableName) {
	if (!(getVersion(entity) == entity->getVersion()))
		return false;
	string request="UPDATE "+tableName+" SET ";
	return true;
}
