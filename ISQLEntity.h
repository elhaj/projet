/*
 * ISQLEntity.h
 *
 *  Created on: 2 mai 2014
 *      Author: SIDI
 */

#ifndef ISQLENTITY_H_
#define ISQLENTITY_H_
#include <string>
#include "SQLSession.h"
#include "IVersion.h"


class ISQLEntity {

public :
	ISQLEntity(){}
	virtual ~ISQLEntity(){}
	virtual bool save(SQLSession session)=0;
	virtual std::string* getField(std::string fieldName)=0;
	virtual void setFieldValue(std::string fieldName, std::string value)=0;
	virtual void display()=0;
	virtual std::string getId() const=0;
	virtual void setId(std::string id)=0;
	virtual  IVersion* getVersion()=0;
	virtual void setVersion()=0;

};

#endif /* ISQLENTITY_H_ */
