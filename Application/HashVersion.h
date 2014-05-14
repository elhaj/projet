/*
 * HashVersion.h
 *
 *  Created on: 13 mai 2014
 *      Author: SIDI
 */

#ifndef HASHVERSION_H_
#define HASHVERSION_H_
#include "IVersion.h"
#include <string>
class HashVersion: IVersion {
public:
	IVersion* getVersion() const;
private:
	std::string hash;
};
/*bool operator ==(const HashVersion& lhs, const HashVersion& rhs) {
	return lhs.hash == rhs.hash;
}*/
#endif /* HASHVERSION_H_ */
