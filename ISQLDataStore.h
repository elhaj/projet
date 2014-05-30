/*
 * DataStore.h
 *
 *  Created on: 30 avr. 2014
 *      Author: SIDI
 */

#ifndef DATASTORE_H_
#define DATASTORE_H_
#include "SQLSession.h"
#include "ISQLEntityCollection.h"
#include "ISQLEntity.h"
#include <string>
#include <vector>
#include "ISQLDataClass.h"
class ISQLDataStore
{
public :
	 ISQLDataStore();
	 virtual ~ISQLDataStore();
	 ISQLDataClass* getDataClass(int i);
	 ISQLDataClass* getDataClass(std::string name);
	 int getDataClassesCount();
protected:
	 std::vector<ISQLDataClass*> fDataClasses;

};
#endif /* DATASTORE_H_ */
