/*
 * IVersion.h
 *
 *  Created on: 13 mai 2014
 *      Author: SIDI
 */

#ifndef IVERSION_H_
#define IVERSION_H_

class IVersion
{
public :
	virtual ~IVersion();
	virtual IVersion* getVersion() const=0;
};


#endif /* IVERSION_H_ */
