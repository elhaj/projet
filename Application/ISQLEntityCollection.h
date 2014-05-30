/*
 * ISQLEntityCollection.h
 *
 *  Created on: 4 mai 2014
 *      Author: SIDI
 */

#ifndef ISQLENTITYCOLLECTION_H_
#define ISQLENTITYCOLLECTION_H_
#include <vector>
#include "ISQLEntity.h"
class ISQLEntityCollection
{
public :
	virtual ~ISQLEntityCollection(){}
	 ISQLEntityCollection(){}
	virtual bool save(SQLSession session)=0;
	virtual ISQLEntity* getEntityByIndex(int index)=0;
	virtual int size()=0;
	virtual void display()=0;
};

#endif /* ISQLENTITYCOLLECTION_H_ */
