/*
 * SQLSession.h
 *
 *  Created on: 29 avr. 2014
 *      Author: SIDI
 */

#ifndef SQLSESSION_H_
#define SQLSESSION_H_

#include <windows.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <string>
#include <vector>
#include "ISQLResultSet.h"

class SQLSession
{
public :
    SQLHSTMT& getStatement();
    SQLHDBC& getDBC();
    SQLSession(std::string DSN);
    void close();
    std::vector<std::vector<std::string> >& getRows(std::string query);
    ISQLResultSet* select(std::string& inTable, std::vector<std::string>& fields, std::string filtre);
    long long int update(std::string& query);
private :
    SQLHDBC fDbc;
    SQLHENV fEnv;
    SQLHSTMT fStmt;
};
#endif /* SQLSESSION_H_ */
