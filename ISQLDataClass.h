/*
 * ISQLDataclass.h
 *
 *  Created on: 21 mai 2014
 *      Author: SIDI
 */

#ifndef ISQLDATACLASS_H_
#define ISQLDATACLASS_H_
#include "ISQLAttribute.h"
#include "ISQLEntity.h"
#include <string>
#include <vector>
class ISQLDataClass {

public:
	ISQLDataClass(std::string source, std::string schema, std::string name, std::string dbms);
	void addAttribute(ISQLAttribute* attribute);
	std::string getName();
	std::string getSchema();
	std::string getSource();
	int getAttributesCount();
	ISQLAttribute* getAttribute(int index);
	ISQLAttribute* getAttributeByName(std::string name);
	ISQLEntity* find( std::vector<std::string>& fields, std::string& filtre);

private:
	std::string fSource;
	std::string fSchema;
	std::string fName;
	std::string fDbms;
	std::vector<ISQLAttribute*> attributes;
};

#endif /* ISQLDATACLASS_H_ */
