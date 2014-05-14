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
class SQLSession
{
public :
    SQLHSTMT& getStatement();
    SQLHDBC& getDBC();
    SQLSession(std::string DSN);
    void close();

private :
    SQLHDBC dbc;
    SQLHENV env;
    SQLHSTMT stmt;
};
#endif /* SQLSESSION_H_ */
