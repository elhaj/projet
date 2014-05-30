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
#include <algorithm>
using namespace std;

ISQLDataStore::ISQLDataStore(string DSN) :
		session(DSN) {

}


ISQLDataStore::~ISQLDataStore() {
	session.close();

}

ISQLEntity* ISQLDataStore::find(std::string tableName, std::vector<std::string> fields,
		std::string condition, string database) {
	SQLAllocHandle(SQL_HANDLE_STMT, session.getDBC(), &session.getStatement());
	ISQLEntity* ent = new MySQLEntity;
	string requete = "SELECT ";
	vector<string> pri=getPrimaryKeyFields(tableName, database);
	for(int i=0;i<pri.size();i++)
	{
		if(std::find(fields.begin(), fields.end(), pri[i]) == fields.end()) {
		  fields.push_back(pri[i]);
		}
	}

	unsigned int i = 0;
	for (i = 0; i < fields.size(); i++) {
		requete += fields[i];
		if (i < fields.size() - 1)
			requete += ", ";
	}

	requete += " FROM " + tableName + " " + condition + " LIMIT 1;";
	SQLRETURN ret =
			SQLExecDirect(session.getStatement(),
					(SQLCHAR*) (reinterpret_cast<const unsigned char*>((requete).c_str())),
					SQL_NTS);

	SQLSMALLINT nCols = 0;
	long long int nIdicator = 0;
	SQLCHAR buf[1024] = { 0 };
	SQLNumResultCols(session.getStatement(), &nCols);

	if (SQL_SUCCEEDED( ret = SQLFetch( session.getStatement() ) )) {

		unsigned short int j = 1;
		for (j = 1; j <= nCols; ++j) {
			ret = SQLGetData(session.getStatement(), j, SQL_C_CHAR, buf, 1024,
					&nIdicator);
			if (SQL_SUCCEEDED( ret )) {
				ent->setFieldValue(fields[j - 1], reinterpret_cast<char*>(buf));
			}
		}
		string id=tableName;
		for(j=0;j<pri.size();j++)
		{
			id+="_"+ent->getField(pri[j]);
		}
		ent->setId(id);
	}
	SQLFreeHandle( SQL_HANDLE_STMT, session.getStatement());
	return ent;
}

ISQLEntityCollection* ISQLDataStore::query(std::string tableName,
		std::vector<std::string> fields, std::string condition, string database) {

	//Build request
	SQLAllocHandle(SQL_HANDLE_STMT, session.getDBC(), &session.getStatement());
	vector<string> pri=getPrimaryKeyFields(tableName, database);
		for(int i=0;i<pri.size();i++)
		{
			if(std::find(fields.begin(), fields.end(), pri[i]) == fields.end()) {
			  fields.push_back(pri[i]);
			}
		}
	string requete = "SELECT ";
	unsigned int i = 0;
	for (i = 0; i < fields.size(); i++) {
		requete += fields[i];
		if (i < fields.size() - 1)
			requete += ", ";
	}
	requete += " FROM " + tableName + " " + condition + ";";

	//----------------------------------------------------------------

	//execute query
	SQLRETURN ret =
			SQLExecDirect(session.getStatement(),
					(SQLCHAR*) (reinterpret_cast<const unsigned char*>((requete).c_str())),
					SQL_NTS);
	//----------------------------------------------------------------

	//Fetch results
	SQLSMALLINT nCols = 0;
	long long int nRows = 0;
	long long int nIdicator = 0;
	SQLCHAR buf[1024] = { 0 };
	SQLNumResultCols(session.getStatement(), &nCols);
	SQLRowCount(session.getStatement(), &nRows);
	cout<<nRows<<endl;
	MySQLEntityCollection* col = new MySQLEntityCollection;
	for (i = 1; i <= nRows; i++) {
		MySQLEntity entity;
		if (!SQL_SUCCEEDED( ret = SQLFetch( session.getStatement() ) ))
			break;
		unsigned short int j = 1;
		for (j = 1; j <= nCols; ++j) {
			ret = SQLGetData(session.getStatement(), j, SQL_C_CHAR, buf, 1024,
					&nIdicator);
			if (SQL_SUCCEEDED( ret )) {
				entity.setFieldValue(fields[j - 1],
						reinterpret_cast<char*>(buf));
			}
		}
		string id=tableName;
				for(j=0;j<pri.size();j++)
				{
					id+="_"+entity.getField(pri[j]);
				}
				entity.setId(id);
		col->add(entity);

	}
	//-------------------------------------------------------------
	SQLFreeHandle( SQL_HANDLE_STMT, session.getStatement());
	return col;
}
