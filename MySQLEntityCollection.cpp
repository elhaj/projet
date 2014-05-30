/*
 * MySQLEntityCollection.cpp
 *
 *  Created on: 5 mai 2014
 *      Author: SIDI
 */

#include "MySQLEntityCollection.h"
#include "ISQLEntity.h"
#include "SQLSession.h"
#include <iostream>
#include <string>
using namespace std;
MySQLEntityCollection::MySQLEntityCollection() {

}

ISQLEntity* MySQLEntityCollection::getEntityByIndex(int index) {
	return &fEntities[index];
}

bool MySQLEntityCollection::save(SQLSession session)
{
	return true;
}
void MySQLEntityCollection::add(MySQLEntity entity)
{
fEntities.push_back(entity);
}
int MySQLEntityCollection::size()
{
	return fEntities.size();}
void MySQLEntityCollection::display()
{
	for(unsigned int i=1;i<=fEntities.size();i++)
	{
		cout<<"Entity "<<i<<endl;
		fEntities[i-1].display();
	}
}
MySQLEntityCollection::~MySQLEntityCollection()
{

}
