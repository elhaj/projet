/*
 * ISQLRow.h
 *
 *  Created on: 22 mai 2014
 *      Author: SIDI
 */

#ifndef ISQLROW_H_
#define ISQLROW_H_
#include <string>
#include <vector>
class ISQLRow {
public:
	int getColumnCount();
	std::string getColumnAsString(int index);
	void add(std::string& value);
private:
	std::vector<std::string> fColumns;
};

#endif /* ISQLROW_H_ */
