#include "ClassThatUsesDB.h"

ClassThatUsesDB::ClassThatUsesDB(DBConnection* connection) :connection_(connection) {}

int ClassThatUsesDB::openConnection()
{
	return connection_->open();
}

MYSQL_RES ClassThatUsesDB::useConnection(const char* command)
{
	return connection_->execQuery(command);
}

void ClassThatUsesDB::closeConnection()
{
	connection_->close();
}
