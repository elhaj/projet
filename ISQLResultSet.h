/*
 * ISQLResultSet.h
 *
 *  Created on: 22 mai 2014
 *      Author: SIDI
 */

#ifndef ISQLRESULTSET_H_
#define ISQLRESULTSET_H_
#include "ISQLRow.h"
class ISQLResultSet{
public :
	ISQLRow* getRowByIndex(int index);
	int getRowCount();
	void addRow(ISQLRow* row);
private:
	std::vector<ISQLRow*> fRows;
};

#endif /* ISQLRESULTSET_H_ */
