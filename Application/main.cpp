/*
 * main.cpp
 *
 *  Created on: 29 avr. 2014
 *      Author: SIDI
 */

#include <iostream>
#include "ISQLDataStore.h"
#include "MySQLEntity.h"
#include "ISQLEntity.h"
#include "ISQLEntityCollection.h"
#include "MySQLEntityCollection.h"
#include "MySQLDataStore.h"
#include <string>
using namespace std;
int main() {
	ISQLDataStore* ds=new MySQLDataStore("produits");
	string fields[2] = { "id", "quantite" };
	string condition = "WHERE id < 10";
	string tableName = "produits";
	string database="pfe";
	ISQLEntityCollection* col = ds->query(tableName, fields, condition, database);
	col->display();
	ISQLEntity* ent1 = ds->find(tableName, fields, condition, database);
	ent1->display();
	return 0;
}
