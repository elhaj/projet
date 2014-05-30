/*
 * ISQLAttribute.h
 *
 *  Created on: 21 mai 2014
 *      Author: SIDI
 */

#ifndef ISQLATTRIBUTE_H_
#define ISQLATTRIBUTE_H_
#include <string>
class ISQLAttribute {
public :
	ISQLAttribute(std::string name, std::string type, bool primary, bool foreign);
	std::string getType();
	std::string getName();
	bool isPrimaryKey();
	bool isForeignKey();

private :
	std::string fName;
	std::string fType;
	bool fPrimary;
	bool fForeign;
};




#endif /* ISQLATTRIBUTE_H_ */
