#include "sqlite.h"



sqlite::sqlite()
{
	db = NULL;
	char *zErrMsg = "";
	int rc = 0;
}


sqlite::~sqlite()
{
}

int sqlite::setup_open(std::string filename)
{	

	rc = sqlite3_open_v2(filename.c_str(), &db, SQLITE_OPEN_READWRITE, nullptr);
	if (rc) {
		// Error opening DB
		sqlite3_close(db);
	}

	// TODO
	// stuff
	return 0;
}

int sqlite::setup_create(std::string filename)
{	

	rc = sqlite3_open_v2(filename.c_str(), &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,nullptr);
	if (rc) {
		// Error opening DB
		sqlite3_close(db);
	}

	// TODO
	// stuff
	return 0;
}

int sqlite::close_db()
{
	int rc = sqlite3_close(db);
	return 0;
}

const char * sqlite::get_err_msg()
{
	return sqlite3_errstr(rc);
}