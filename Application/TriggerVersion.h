/*
 * TriggerVersion.h
 *
 *  Created on: 13 mai 2014
 *      Author: SIDI
 */

#ifndef TRIGGERVERSION_H_
#define TRIGGERVERSION_H_
#include "IVersion.h"
class TriggerVersion : IVersion
{
public:
	IVersion* getVersion() const;
private:
	 int version;

};
bool operator ==(const TriggerVersion& lhs, const TriggerVersion& rhs) {
	return lhs.version == rhs.version;
}
#endif /* TRIGGERVERSION_H_ */

