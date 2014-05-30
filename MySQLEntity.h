/*
 * MySQLEntity.h
 *
 *  Created on: 2 mai 2014
 *      Author: SIDI
 */

#ifndef MYSQLENTITY_H_
#define MYSQLENTITY_H_
#include <map>
#include <string>
#include "ISQLEntity.h"
#include "IVersion.h"
class MySQLEntity : public ISQLEntity
{
public :
	 MySQLEntity(ISQLDataClass* dc);
	 ~MySQLEntity();
	 bool save();
	 std::string* getField(std::string fieldName) const;
	 void setFieldValue(std::string fieldName, std::string value);
	 void display() const;
	 std::string getId() const;
	 void setId(std::string id);
	 IVersion* getVersion() const;
	 void setVersion(IVersion* version);
	 std::vector<std::string>& getChangedFields();
private :
	 std::string fId;
	 std::map<std::string, std::string> fFields;
	 IVersion* fVersion;
	 std::vector<std::string> fChangedFields;
};
#endif /* MYSQLENTITY_H_ */
