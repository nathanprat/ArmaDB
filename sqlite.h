/*
	
	ArmaDB - Arma Extension which allows to connect to SQLite
    Copyright (C) 2015  Nathan Prat

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#pragma once

#include <string>
#include "sqlite3/sqlite3.h"
#include "statement.h"

class sqlite
{
public:
	sqlite();
	sqlite(std::string filename);
	~sqlite();

	int open();	

	int close_db();
	const char * get_err_msg();

	int exec_simple(const char *sql);

	void addStatementFromConfig();

	void setName(std::string name) { dbname = name; }
	int get_rc() { return rc; }
private:
	bool sql_custom_only;
	sqlite3 *db;
	std::string dbname;
	std::string zErrMsg;
	int rc;
};

