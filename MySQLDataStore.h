/*
 * MySQLDataStore.h
 *
 *  Created on: 14 mai 2014
 *      Author: SIDI
 */

#ifndef MYSQLDATASTORE_H_
#define MYSQLDATASTORE_H_
#include "ISQLDataStore.h"

class MySQLDataStore : public ISQLDataStore
{
public :
	 MySQLDataStore();
	 ~MySQLDataStore();
};
#endif /* MYSQLDATASTORE_H_ */
