/*
 * DataStore.cpp
 *
 *  Created on: 30 avr. 2014
 *      Author: SIDI
 */

#include <string>
#include "MySQLEntity.h"
#include "ISQLDataStore.h"
#include "MySQLEntityCollection.h"
#include "ISQLEntity.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "dirent.h"
#include "ISQLDataClass.h"

using namespace std;
string repDataSources = "SQLDataSources";
ISQLDataStore::ISQLDataStore() {

	DIR* dir;
	dirent* pdir;
	std::vector<std::string> files;
	string line;

	dir = opendir(repDataSources.c_str());

	while (pdir = readdir(dir)) {

		string filePath = repDataSources + string("/") + pdir->d_name;
		if (pdir->d_name == string(".") || pdir->d_name == string(".."))
			continue;
		ifstream myfile(filePath.c_str());
		if (myfile.is_open()) {
			getline(myfile, line);
			line.erase(line.end() - 1, line.end());
			string dbms = line.substr(line.find("=") + 1);
			getline(myfile, line);
			line.erase(line.end() - 1, line.end());
			string dsn = line.substr(line.find("=") + 1);
			getline(myfile, line);
			line.erase(line.end() - 1, line.end());
			string database = line.substr(line.find("=") + 1);
			getline(myfile, line);
			line.erase(line.end() - 1, line.end());
			string user = line.substr(line.find("=") + 1);
			getline(myfile, line);
			line.erase(line.end() - 1, line.end());
			string password = line.substr(line.find("=") + 1);

			SQLSession session(dsn);

			vector<string> fields;
			vector<string> fields1;
			string inTable;
			string filtre;
			if (dbms == string("mysql")) {
				inTable = " information_schema.tables ";
				filtre = string("table_schema='") + database + string("' ");
				fields.push_back("table_name");
				fields.push_back("table_schema");
				ISQLResultSet* rsDataClasses = session.select(inTable, fields,
						filtre);
				fields1.push_back("column_name");
				fields1.push_back("column_type");
				fields1.push_back("column_key");
				inTable = "information_schema.columns";
				for (int i = 0; i < rsDataClasses->getRowCount(); i++) {
					ISQLRow* row = rsDataClasses->getRowByIndex(i);
					ISQLDataClass* dc = new ISQLDataClass(dsn,
							row->getColumnAsString(1),
							row->getColumnAsString(0), dbms);

					filtre = string(" table_name='") + dc->getName()
							+ "' AND table_schema='" + dc->getSchema() + "' ";
					ISQLResultSet* rc1 = session.select(inTable, fields1,
							filtre);
					for (int j = 0; j < rc1->getRowCount(); j++) {

						ISQLRow* row1 = rc1->getRowByIndex(j);
						string name = row1->getColumnAsString(0);
						string type = row1->getColumnAsString(1);
						string key = row1->getColumnAsString(2);
						bool primary = (key == string("PRI"));
						bool foreign = (key == string("MUL"));
						ISQLAttribute* att = new ISQLAttribute(name, type,
								primary, foreign);
						dc->addAttribute(att);
					}

					fDataClasses.push_back(dc);
				}

			}
			myfile.close();
		}

		else
			cout << "Unable to open file";
	}
}

ISQLDataClass* ISQLDataStore::getDataClass(int i) {
	if (i >= this->getDataClassesCount()) {
		ISQLDataClass* dc(0);
		return dc;
	}
	return fDataClasses[i];
}
ISQLDataClass* ISQLDataStore::getDataClass(string name) {
	ISQLDataClass* dc(0);
	for (int i = 0; i < fDataClasses.size(); i++) {
		if (fDataClasses[i]->getName() == name) {
			dc = fDataClasses[i];
		}
	}

	return dc;
}
int ISQLDataStore::getDataClassesCount() {
	return fDataClasses.size();
}

ISQLDataStore::~ISQLDataStore() {

}

