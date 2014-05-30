/*
 * MySQLEntity.cpp
 *
 *  Created on: 2 mai 2014
 *      Author: SIDI
 */

#include "MySQLEntity.h"
#include "EntityManager.h"
#include "IncrementalVersion.h"
#include "IVersion.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string kQuotedTypes[] = {"char", "varchar", "binary", "varbinary", "blob", "text", "enum",  "set","date", "time", "datetime", "timestamp", "year"};
const int kQuotedSize(13);
string toLower(string& in)
{
	string lower="";
	for(unsigned  i=0;i<in.size();i++)
	{
		char c=in[i];
		if(c<='Z'&&c>='A')
		{
			 c-=('Z'-'z');
		}
		lower+=c;
	}
	return lower;
}

bool isQuoted(string& att)
{
	string lower=toLower(att);
				for(int j=0;j<kQuotedSize;j++)
				{
					if(lower.find(kQuotedTypes[j])!=string::npos)
					{
						return true;
						break;
					}
				}

return false;

}
MySQLEntity::MySQLEntity(ISQLDataClass* fDataClass) :
		ISQLEntity(fDataClass) {
	fVersion = 0;
}
MySQLEntity::~MySQLEntity() {
delete fVersion;
}

string* MySQLEntity::getField(string fieldName) const{
	string* result = NULL;
	map<string, string>::const_iterator it( fFields.find(fieldName));
	if (it != fFields.end()) {
		result = new string(it->second);
	}
	return result;
}

void MySQLEntity::setFieldValue(string fieldName, string value) {
	if (fFields.find(fieldName) != fFields.end()&&fFields.find(fieldName)->second!=value)
		fChangedFields.push_back(fieldName);

	fFields[fieldName] = value;

}
std::vector<std::string>& MySQLEntity::getChangedFields(){
	return this->fChangedFields;
}

void MySQLEntity::display() const{
	map<string, string>::const_iterator mit(fFields.begin()), mend(fFields.end());

	for (; mit != mend; mit++)
		cout << mit->first << ": " << mit->second << endl;
	cout << endl;
}
string MySQLEntity::getId() const {
	return fId;
}
void MySQLEntity::setId(string id) {
	this->fId = id;
}

void MySQLEntity::setVersion(IVersion* version) {
	this->fVersion = version;
}
IVersion* MySQLEntity::getVersion() const{
	return this->fVersion;
}
bool MySQLEntity::save() {
	if(fChangedFields.size()==0)
			return true;

	EntityManager* em = EntityManager::getInstance();

	if(!(*(em->getVersion(this))==*(fVersion)))
		return false;

	string query=string("UPDATE ")+this->getDataClass()->getName()+string(" SET ");
		string value="";
		ISQLDataClass* dc=this->getDataClass();
		for(unsigned i=0;i<this->getChangedFields().size();i++)
		{
			if(i>0)
				query+=string(" AND ");

			string& changedField=this->getChangedFields()[i];
			query+=changedField+string(" = ");

			value=*(this->getField(changedField));
			ISQLAttribute* att=dc->getAttributeByName(changedField);
			string type=att->getType();

			if(isQuoted(type))
			{
				query+=string(" '")+value+string("' ");
			}
			else
			{
				query+=string(" ")+value+(" ");
			}
		}

		query+=" WHERE ";
		for(int i=0;i<dc->getAttributesCount();i++)
		{
			if(dc->getAttribute(i)->isPrimaryKey())
			{
				string att=dc->getAttribute(i)->getName();
				query+=att+string(" = ");
				if(isQuoted(att))
				{
					query+=string(" '")+(*this->getField(att))+string("' ");
				}
				else query+=*(this->getField(att));
			}
		}
		query+=string(";");
		SQLSession session(dc->getSource());
		long long int affectedRows=session.update(query);
		session.close();
		if(affectedRows==1)
		{
			string type=em->getType();
			if(type=="ORM")
			{
				em->updateVersion(this);
				IncrementalVersion* iv1=static_cast<IncrementalVersion *>(fVersion);
				iv1->update();
			}
			this->fChangedFields.clear();
		}
		return affectedRows==1;
}
