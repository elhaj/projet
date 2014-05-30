/*
 * ISQLEntity.h
 *
 *  Created on: 2 mai 2014
 *      Author: SIDI
 */

#ifndef ISQLENTITY_H_
#define ISQLENTITY_H_
#include <string>
#include <vector>
#include "SQLSession.h"
#include "IVersion.h"

class ISQLDataClass;

class ISQLEntity {

public :
	ISQLEntity(ISQLDataClass* dataClass);
	virtual ~ISQLEntity(){}
	virtual bool save()=0;
	virtual std::string* getField(std::string fieldName) const = 0;
	virtual void setFieldValue(std::string fieldName, std::string value) =0;
	virtual void setId(std::string id)=0;
	virtual  IVersion* getVersion() const = 0;
	virtual void setVersion(IVersion* version)=0;
	virtual std::vector<std::string>& getChangedFields() = 0;
	virtual void display() const=0;
	virtual std::string getId() const=0;
	ISQLDataClass* getDataClass() const;
protected:
	ISQLDataClass* fDataClass;

};

#endif /* ISQLENTITY_H_ */
