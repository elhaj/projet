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
	return &entities[index];
}

bool MySQLEntityCollection::save(SQLSession session)
{
	return true;
}
void MySQLEntityCollection::add(MySQLEntity entity)
{
entities.push_back(entity);
}
int MySQLEntityCollection::size()
{
	return entities.size();}
void MySQLEntityCollection::display()
{
	for(unsigned int i=1;i<=entities.size();i++)
	{
		cout<<"Entity "<<i<<endl;
		entities[i-1].display();
	}
}
MySQLEntityCollection::~MySQLEntityCollection()
{

}
