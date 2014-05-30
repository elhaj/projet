/*
 * MySQLDataStore.h
 *
 *  Created on: 14 mai 2014
 *      Author: SIDI
 */

#ifndef MYSQLDATASTORE_H_
#define MYSQLDATASTORE_H_
#include "ISQLDataStore.h"

class MySQLDataStore : ISQLDataStore
{
public :
	 MySQLDataStore(std::string DSN);
	 virtual ~MySQLDataStore();
	 ISQLEntity* find(std::string tableName, std::string fields[], std::string condition);
	 ISQLEntityCollection* query(std::string tableName, std::string fields[], std::string condition);
	 std::vector<std::string> getPrimaryKeys();
	 //virtual std::vector<std::string> getRowHash()=0;
private :
	 SQLSession session;
	 std::vector<std::string> getPrimaryKeyFields(std::string tableName, std::string database);
};
#endif /* MYSQLDATASTORE_H_ */
