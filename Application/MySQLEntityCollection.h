/*
 * MySQLEntityCollection.h
 *
 *  Created on: 5 mai 2014
 *      Author: SIDI
 */

#ifndef MYSQLENTITYCOLLECTION_H_
#define MYSQLENTITYCOLLECTION_H_
#include <vector>
#include "ISQLEntityCollection.h"
#include "ISQLEntity.h"
#include "MySQLEntity.h"
#include "SQLSession.h"
class MySQLEntityCollection: public ISQLEntityCollection {
public:
	MySQLEntityCollection();
	~MySQLEntityCollection();
	bool save(SQLSession session);
	ISQLEntity* getEntityByIndex(int index);
	void add(MySQLEntity entity);
	int size();
	void display();

private:
	std::vector<MySQLEntity> entities;

};

#endif /* MYSQLENTITYCOLLECTION_H_ */
