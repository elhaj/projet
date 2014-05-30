/*
 * MySQLDataStore.cpp
 *
 *  Created on: 14 mai 2014
 *      Author: SIDI
 */
#include "MySQLDataStore.h"

/*
 * DataStore.cpp
 *
 *  Created on: 30 avr. 2014
 *      Author: SIDI
 */

#include <string>
#include "MySQLEntity.h"
#include "ISQLDataStore.h"
#include "MySQLEntityCollection.h"
#include "ISQLEntity.h"
#include <iostream>
#include <vector>
using namespace std;

MySQLDataStore::MySQLDataStore(string DSN) :
		session(DSN) {

}

vector<string> ISQLDataStore::getPrimaryKeyFields(string tableName,
		string database) {
	vector<string> keys;
	string MySQLRequest =
			"SELECT column_name FROM information_schema.columns WHERE ( table_schema ='"+database+"' AND table_name='"+tableName+"' AND column_key='PRI');";
	SQLRETURN ret =
			SQLExecDirect(session.getStatement(),
					(SQLCHAR*) (reinterpret_cast<const unsigned char*>((MySQLRequest).c_str())),
					SQL_NTS);



	long long int nRows = 0;
	long long int nIdicator = 0;
	SQLCHAR buf[1024] = { 0 };
	unsigned int i;
	SQLRowCount(session.getStatement(), &nRows);
	for (i = 1; i <= nRows; i++) {
		if(!SQL_SUCCEEDED( ret = SQLFetch( session.getStatement() ) ))
			break;

		ret = SQLGetData(session.getStatement(), 1, SQL_C_CHAR, buf, 1024,
				&nIdicator);
		if (SQL_SUCCEEDED( ret )) {
			keys.push_back(reinterpret_cast<char*>(buf));
		}

	}

	return keys;

}
MySQLDataStore::~MySQLDataStore() {
	session.close();

}




