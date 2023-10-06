#pragma once

#include <mysql.h>
#pragma comment(lib, "libmysql.lib")
class DBConnection
{
public:
	virtual ~DBConnection() = default;
	virtual int open() = 0;
	virtual void close() = 0;
	virtual MYSQL_RES execQuery(const char* command) = 0;
};

