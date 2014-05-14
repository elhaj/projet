/*
 * MySQLEntity.cpp
 *
 *  Created on: 2 mai 2014
 *      Author: SIDI
 */

#include "MySQLEntity.h"
#include <iostream>
#include <string>

using namespace std;
MySQLEntity::MySQLEntity() {
version=0;
}

string MySQLEntity::getId() const{
	return id;
}

string* MySQLEntity::getField(string fieldName) {
	string* result = NULL;
	map<string, string>::iterator it = fields.find(fieldName);
	if (it != fields.end()) {
		result = new string(it->second);
	}
	return result;
}
void MySQLEntity::setVersion(IVersion* version)
{
	this->version=version;}
IVersion* MySQLEntity::getVersion()
{
	return this->version;
}
void MySQLEntity::setId(string id)
{this->id=id;}
void MySQLEntity::setFieldValue(string fieldName, string value) {
	fields[fieldName] = value;
}
MySQLEntity::~MySQLEntity() {

}
bool MySQLEntity::save(SQLSession session) {
	return true;
}
void MySQLEntity::display() {
	map<string, string>::const_iterator mit(fields.begin()), mend(fields.end());

	for (; mit != mend; mit++)
		cout << mit->first << ": " << mit->second << endl;
	cout << endl;
}
