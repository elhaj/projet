/*
 * SQLSession.cpp
 *
 *  Created on: 29 avr. 2014
 *      Author: SIDI
 */

#include "SQLSession.h"
#include "ISQLAttribute.h"
#include "ISQLEntity.h"
#include "ISQLDataClass.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
SQLSession::SQLSession(string DSN) {
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &fEnv);
	SQLSetEnvAttr(fEnv, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0); // utiliser la version 3 d'ODBC
	SQLAllocHandle(SQL_HANDLE_DBC, fEnv, &fDbc); // Connecton à la base de données
	SQLDriverConnect(fDbc, NULL,
			(SQLCHAR*) (reinterpret_cast<const unsigned char*>(("DSN=" + DSN
					+ ";").c_str())), SQL_NTS, NULL, 0, NULL,
			SQL_DRIVER_COMPLETE);
	SQLAllocHandle(SQL_HANDLE_STMT, fDbc, &fStmt);
}

SQLHDBC& SQLSession::getDBC() {
	return fDbc;
}

SQLHSTMT& SQLSession::getStatement() {
	return fStmt;
}

void SQLSession::close() {
	SQLDisconnect(this->fDbc);
	SQLFreeHandle(SQL_HANDLE_DBC, this->fDbc);
	SQLFreeHandle(SQL_HANDLE_ENV, this->fEnv);
}
std::vector<std::vector<std::string> >& SQLSession::getRows(std::string query) {
	vector<vector<string> >* result = new vector<vector<string> >;

	SQLAllocHandle(SQL_HANDLE_STMT, fDbc, &fStmt);
	unsigned int i = 0;

	SQLRETURN ret =
			SQLExecDirect(fStmt,
					(SQLCHAR*) (reinterpret_cast<const unsigned char*>((query).c_str())),
					SQL_NTS);

	SQLSMALLINT nCols = 0;
	long long int nIdicator = 0;
	SQLCHAR buf[1024] = { 0 };
	long long int nRows = 0;
	SQLNumResultCols(fStmt, &nCols);
	SQLRowCount(fStmt, &nRows);
	for (i = 1; i <= nRows; i++) {

		vector<string> v(0);
		if (!SQL_SUCCEEDED( ret = SQLFetch( fStmt ) ))
			break;
		unsigned short int j = 1;
		for (j = 1; j <= nCols; ++j) {
			ret = SQLGetData(fStmt, j, SQL_C_CHAR, buf, 1024, &nIdicator);
			if (SQL_SUCCEEDED( ret )) {
				v.push_back(reinterpret_cast<char*>(buf));
			}
		}
		result->push_back(v);
	}

	SQLFreeHandle(SQL_HANDLE_STMT, fStmt);
	return *result;

}
ISQLResultSet* SQLSession::select(std::string& inTable,
		std::vector<std::string>& fields, std::string filtre) {
	ISQLResultSet* rs = new ISQLResultSet();

	string query = "SELECT ";
	for (unsigned i = 0; i < fields.size(); i++) {
		query += fields[i];
		if (i < fields.size() - 1)
			query += string(", ");
	}

	query += string(" FROM ") + inTable + string(" WHERE ") + filtre + ";";
	SQLAllocHandle(SQL_HANDLE_STMT, fDbc, &fStmt);
	unsigned int i = 0;

	SQLRETURN ret =
			SQLExecDirect(fStmt,
					(SQLCHAR*) (reinterpret_cast<const unsigned char*>((query).c_str())),
					SQL_NTS);

	SQLSMALLINT nCols = 0;
	long long int nIdicator = 0;
	SQLCHAR buf[1024] = { 0 };
	long long int nRows = 0;
	SQLNumResultCols(fStmt, &nCols);
	SQLRowCount(fStmt, &nRows);
	for (i = 1; i <= nRows; i++) {

		ISQLRow* row = new ISQLRow;

		if (!SQL_SUCCEEDED( ret = SQLFetch( fStmt ) ))
			break;
		unsigned short int j = 1;
		for (j = 1; j <= nCols; ++j) {
			ret = SQLGetData(fStmt, j, SQL_C_CHAR, buf, 1024, &nIdicator);
			if (SQL_SUCCEEDED( ret )) {
				string s = reinterpret_cast<char*>(buf);
				row->add(s);
			}
		}
		rs->addRow(row);
	}

	SQLFreeHandle(SQL_HANDLE_STMT, fStmt);

	return rs;
}
long long int SQLSession::update(string& query) {

	SQLRETURN ret =
			SQLExecDirect(fStmt,
					(SQLCHAR*) (reinterpret_cast<const unsigned char*>((query).c_str())),
					SQL_NTS);
	long long int nRows =0;
	SQLRowCount(fStmt, &nRows);
	return nRows;
}

