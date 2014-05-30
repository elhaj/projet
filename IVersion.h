/*
 * IVersion.h
 *
 *  Created on: 13 mai 2014
 *      Author: SIDI
 */

#ifndef IVERSION_H_
#define IVERSION_H_
#include "ISQLEntity.h"
class IVersion {
public:
	IVersion(std::string fVersionType) :fVersionType(fVersionType){
	}
	virtual ~IVersion(){}
	bool operator==(const IVersion& rhs)
		{
			return this->doCompare(rhs);
		}
	virtual void displayVersion() const=0;
private:
	virtual bool doCompare(const IVersion& rhs) = 0;
	std::string fVersionType;
};

#endif /* IVERSION_H_ */
