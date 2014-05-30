/*
 * TriggerVersion.h
 *
 *  Created on: 13 mai 2014
 *      Author: SIDI
 */

#ifndef INCREMENTALVERSION_H_
#define INCREMENTALVERSION_H_
#include <iostream>
#include "IVersion.h"
class IncrementalVersion: public IVersion {
public:
	IncrementalVersion(std::string fVersionType, int fVersion) : IVersion(fVersionType),fVersion(fVersion) {
	}
	~IncrementalVersion() {
	}
	void update() {
		fVersion = fVersion + 1;
	}
	void displayVersion() const {
		std::cout << fVersion << std::endl;
	}
	bool operator==(const IncrementalVersion& other) {
		return fVersion == other.fVersion;
	}

	const int getVersion()
	{
		return fVersion;
	}

private:
	int fVersion;
	bool doCompare(const IVersion& rhs) { // compare deux IncrementalVersions
		bool bRetval = false;
		const IncrementalVersion* rhV =
				dynamic_cast<const IncrementalVersion*>(&rhs);
		if (rhV) {
			bRetval = fVersion == rhV->fVersion;
		}
		return bRetval;
	}
};
#endif /* INCREMENTALVERSION_H_ */

