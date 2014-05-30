/*
 * EntityManager.cpp
 *
 *  Created on: 13 mai 2014
 *      Author: SIDI
 */

#include "EntityManager.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include "IncrementalVersion.h"
#include "ISQLDataStore.h"

using namespace std;
//fichier de configuration contient 3 valeurs possibles : ORM, Trigger ou Hash
string confPath = "Configuration/config";

//initialisation des membres static
bool EntityManager::sInstanceFlag = false;
EntityManager* EntityManager::sInstance = NULL;

//constructeur
EntityManager::EntityManager() {

	ifstream myfile(confPath.c_str());
	string line;
	if (myfile.is_open()) {
		getline(myfile, line);
		line.erase(line.end() - 1, line.end());
		EntityManager::fType = line.substr(line.find("=") + 1);
		myfile.close();
	}

	else
		cout << "Unable to open file" << endl;
}

//destructeur
EntityManager::~EntityManager()
{
	sInstanceFlag = false;
}

// retourn le type ORM , Trigger ou Hash
std::string EntityManager::getType() {
	return fType;
}

//retourne la version d'une Entité présente dans la base de données
IVersion* EntityManager::getVersion(ISQLEntity* entity) {
	IVersion* version(0);
	if (fId_version.find(entity->getId()) == fId_version.end()) {

		if (fType == "ORM") {

			IncrementalVersion* v = new IncrementalVersion("Incr", 0);
			fId_version[entity->getId()] = v;

			version = new IncrementalVersion("Incr", 0);
		} else if (fType == "Hash") {

		}
	} else {
		if (fType == "ORM") {
			IncrementalVersion* iv =
					static_cast<IncrementalVersion*>(fId_version.find(
							entity->getId())->second);
			version = new IncrementalVersion("Incr", iv->getVersion());
		}
	}
	return version;
}

// retourne l'instance singleton
EntityManager* EntityManager::getInstance() {
	if (!sInstanceFlag) {
		sInstance = new EntityManager();
		sInstanceFlag = true;
		return sInstance;
	} else {
		return sInstance;
	}
}

// met à jour la version d'une entité
void EntityManager::updateVersion(ISQLEntity* entity) {
	if(fType=="ORM")
	{
		IncrementalVersion* vers=static_cast<IncrementalVersion*>(fId_version.find(entity->getId())->second);
		vers->update();
	}
}
