#pragma once
#include "DBConnection.h"

class ClassThatUsesDB
{
private:
	DBConnection* connection_;
public:
	ClassThatUsesDB(DBConnection* connection);
	~ClassThatUsesDB() = default;

	int openConnection();
	MYSQL_RES useConnection(const char* command);
	void closeConnection();

};

