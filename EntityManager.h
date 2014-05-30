/*
 * EntityManager.h
 *
 *  Created on: 13 mai 2014
 *      Author: SIDI
 */

#ifndef ENTITYMANAGER_H_
#define ENTITYMANAGER_H_
#include "ISQLEntity.h"
#include "IVersion.h"
#include "SQLSession.h"
#include <string>
#include <map>
#include <vector>
#include "ISQLDataStore.h"
class EntityManager
{
	public:
	static EntityManager* getInstance();
	~EntityManager();
	std::string getType();
	IVersion* getVersion(ISQLEntity* entity);
	void updateVersion(ISQLEntity* entity);
	private :
	EntityManager();
	std::string fType;
	static EntityManager* sInstance;
	std::map<std::string,IVersion*> fId_version;
	static bool sInstanceFlag;
};
#endif /* ENTITYMANAGER_H_ */
