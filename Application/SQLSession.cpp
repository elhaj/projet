/*
 * SQLSession.cpp
 *
 *  Created on: 29 avr. 2014
 *      Author: SIDI
 */

#include "SQLSession.h"
using namespace std;

SQLSession::SQLSession(string DSN)
{
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0); // utiliser la version 3 d'ODBC
    SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc); // Connecton à la base de données
    SQLDriverConnect(dbc, NULL, (SQLCHAR*)(reinterpret_cast<const unsigned char*>(("DSN="+DSN+";").c_str())), SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
    SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
}

SQLHDBC& SQLSession::getDBC()
{
	return dbc;
}

SQLHSTMT& SQLSession::getStatement()
{
    return stmt;
}

void SQLSession::close()
{
    SQLDisconnect( this->dbc );
    SQLFreeHandle(SQL_HANDLE_DBC, this->dbc);
    SQLFreeHandle(SQL_HANDLE_ENV, this->env);
}

