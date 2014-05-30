/*
 * main.cpp
 *
 *  Created on: 29 avr. 2014
 *      Author: SIDI
 */
#include <iostream>
#include "ISQLDataStore.h"
#include "ISQLDataClass.h"
#include "ISQLAttribute.h"
#include "EntityManager.h"
#include "ISQLEntity.h"
#include "IncrementalVersion.h"
#include <string>
#include <vector>
using namespace std;
string filtre1 = " id=1 ";
vector<string> fields1;
string filtre2 = " id=1 ";
vector<string> fields2;

int main() {
	fields1.push_back("description");
	fields2.push_back("description");
	ISQLDataStore ds;
	ISQLDataClass* dc=ds.getDataClass("games");
	ISQLEntity* entity1=dc->find(fields1, filtre1);
	ISQLEntity* entity2=dc->find(fields2, filtre2);
	entity1->setFieldValue("description", "de451");
	entity2->setFieldValue("description","desc4ij");
	entity1->save();
	if(entity2->save())
		cout<<"entity saved"<<endl;
	else cout<<"concurrent modification"<<endl;
	return 0;
}
