#pragma once
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "ClassThatUsesDB.h"

const char* TEST_QUERY = "SELECT * FROM users";

class MockDBConnection :public DBConnection {
public:
	MOCK_METHOD(int, open, (), (override)) {};
	MOCK_METHOD(void, close, (), (override)) {};
	MOCK_METHOD(MYSQL_RES, execQuery, (const char* query), (override)) {};
};

TEST(ClassThatUsesDB, test_openConnection)
{
	MockDBConnection connection;
	EXPECT_CALL(connection, open).Times(::testing::AtLeast(1));
	ClassThatUsesDB userDB(&connection);
	userDB.openConnection();
}

TEST(ClassThatUsesDB, test_useConnection)
{
	MockDBConnection connection;
	EXPECT_CALL(connection, execQuery).Times(::testing::AtLeast(1));
	ClassThatUsesDB userDB(&connection);
	userDB.useConnection(TEST_QUERY);
}

TEST(ClassThatUsesDB, test_closeConnection)
{
	MockDBConnection connection;
	EXPECT_CALL(connection, close).Times(::testing::AtLeast(1));
	ClassThatUsesDB userDB(&connection);
	userDB.closeConnection();
}