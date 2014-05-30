/*
 * ISQLResultSet.cpp
 *
 *  Created on: 22 mai 2014
 *      Author: SIDI
 */
#include "ISQLResultSet.h"

ISQLRow* ISQLResultSet::getRowByIndex(int index) {
	return fRows[index];
}

int ISQLResultSet::getRowCount() {
	return fRows.size();
}

void ISQLResultSet::addRow(ISQLRow* row) {
	fRows.push_back(row);
}

