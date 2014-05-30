/*
 * HashVersion.h
 *
 *  Created on: 13 mai 2014
 *      Author: SIDI
 */

#ifndef HASHVERSION_H_
#define HASHVERSION_H_
#include "IVersion.h"
#include "ISQLEntity.h"
#include <iostream>

#include <string>
class HashVersion:public IVersion {
public:
	HashVersion(std::string fVersionType,std::string fhash):IVersion(fVersionType)
	{
		this->fhash=fhash;
	}
	~HashVersion()
	{
	}
	 void displayVersion() const {
		 std::cout<<fhash<<std::endl;
	 }
private:
	bool doCompare(const IVersion& rhs); //   compare deux hashs versions
	std::string fhash; // hash stocké sous forme d'un string
};

bool HashVersion::doCompare(const IVersion& rhs)
	{
		 bool bRetval = false;
		         const HashVersion* rhV = static_cast<const HashVersion*>(&rhs);
		         if (rhV)
		         {
		            bRetval = fhash == rhV->fhash;
		         }
		         return bRetval;
	}
#endif /* HASHVERSION_H_ */
