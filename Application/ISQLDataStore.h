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
#include <vector>
class ISQLDataStore
{
public :
	 ISQLDataStore(std::string DSN);
	 virtual ~ISQLDataStore();
	 ISQLEntity* find(std::string tableName, std::vector<std::string> fields, std::string condition, std::string);
	 ISQLEntityCollection* query(std::string tableName, std::vector<std::string> fields, std::string condition, std::string database);
	 virtual std::vector<std::string> getPrimaryKeys()=0;
	 //virtual std::vector<std::string> getRowHash()=0;
private :
	 SQLSession session;
	 std::vector<std::string> getPrimaryKeyFields(std::string tableName, std::string database);
};



#endif /* DATASTORE_H_ */
