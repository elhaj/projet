/*
 * ISQLRow.cpp
 *
 *  Created on: 22 mai 2014
 *      Author: SIDI
 */
#include "ISQLRow.h"
using namespace std;


	int ISQLRow::getColumnCount(){
		return fColumns.size();
	}
	string ISQLRow::getColumnAsString(int index){
		return fColumns[index];
	}
	void ISQLRow::add(string& value)
	{
		fColumns.push_back(value);
	}
