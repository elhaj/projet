/*
 * ISQLDataClass.cpp
 *
 *  Created on: 22 mai 2014
 *      Author: SIDI
 */

#include "ISQLDataClass.h"
#include "MySQLEntity.h"
#include "SQLSession.h"
#include "EntityManager.h"
#include <algorithm>
using namespace std;

ISQLDataClass::ISQLDataClass(string source, string schema, string name,
		string dbms) :
		fSource(source), fSchema(schema), fName(name), fDbms(dbms) {
}
void ISQLDataClass::addAttribute(ISQLAttribute* attribute) {
	attributes.push_back(attribute);
}

string ISQLDataClass::getName() {
	return fName;
}
string ISQLDataClass::getSchema() {
	return fSchema;
}

string ISQLDataClass::getSource() {
	return fSource;
}

ISQLAttribute* ISQLDataClass::getAttribute(int index) {
	return attributes[index];
}

int ISQLDataClass::getAttributesCount() {
	return attributes.size();
}
ISQLAttribute* ISQLDataClass::getAttributeByName(string name) {
	ISQLAttribute* att(0);
	for (int i = 0; i < this->getAttributesCount(); i++) {
		if ((this->getAttribute(i)->getName()) == name) {
			att = this->getAttribute(i);
			break;
		}
	}
	return att;
}

ISQLEntity* ISQLDataClass::find( vector<string>& fields,
		string& filtre) {
	ISQLEntity* entity(0);
	if (fDbms == "mysql") {
		entity = new MySQLEntity(this);
		filtre += string(" LIMIT 1");
	}

	//add primary key fields
	for (int i = 0; i < this->getAttributesCount(); i++) {
		if (this->getAttribute(i)->isPrimaryKey()) {
			if (std::find(fields.begin(), fields.end(),
					this->getAttribute(i)->getName()) == fields.end()) {
				fields.push_back(this->getAttribute(i)->getName());
			}
		}
	}

	SQLSession session(this->getSource());

	ISQLResultSet* rs = session.select(this->fName, fields, filtre);
	// set entity fields

	ISQLRow* row = rs->getRowByIndex(0);
	for (int j = 0; j < row->getColumnCount(); j++) {
		entity->setFieldValue(fields[j], row->getColumnAsString(j));
	}
	// set id
	string id = this->getName();
	for (int i = 0; i < this->getAttributesCount(); i++) {
		if (this->getAttribute(i)->isPrimaryKey()) {
			id += string("_")
					+ *entity->getField(this->getAttribute(i)->getName());
		}
	}

	//setVersion
	EntityManager* em = EntityManager::getInstance();
	entity->setVersion(em->getVersion(entity));
	delete row;
	delete rs;
	session.close();
	return entity;
}
