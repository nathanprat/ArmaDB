#include "stdafx.h"
#include "CppUnitTest.h"

#include "../dllmain.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		// If "function" arg is empty, should reply "Hello World!!"
		TEST_METHOD(TEST_helloworld)
		{			
			char out[50], fun[50] = "";
			int outSize = 50;
			RVExtension(out, outSize, fun);			
			Assert::AreEqual(
				// Expected value:
				"Hello World!!",
				// Actual value:
				out,
				//"Hello World!!",
				// Tolerance:
				0.01,
				// Message:
				L"Hello World failed",
				// Line number - used if there is no PDB file:
				LINE_INFO());
		}

		TEST_METHOD(TEST_too_many_args)
		{
			char out[50], fun[] = "sdf:aze:hg:xcv:jgh:oiu:qsd:xcv:ytuiy:sdfsfdg";
			int outSize = 50;
			RVExtension(out, outSize, fun);
			Assert::AreEqual("INPUT not recognized", out, 0.01, L"too_many_args failed", LINE_INFO());
		}

		TEST_METHOD(TEST_split_to_container_1)
		{			
			const char *function = "dfgfd:xcwb:poiuyt:dsgf";
			std::string str_test(function);

			std::vector<std::string> fields;
			split_to_container(fields, str_test, ":", split::no_empties);

			Assert::AreNotEqual(3, fields.size(), 0.01, L"split_to_container failed", LINE_INFO());
		}

		TEST_METHOD(TEST_split_to_container_2)
		{
			const char *function = "dfgfd:xcwb::poiuyt";
			std::string str_test(function);

			std::vector<std::string> fields;
			split_to_container(fields, str_test, ":", split::no_empties);

			Assert::AreEqual(3, fields.size(), 0.01, L"split_to_container failed", LINE_INFO());
		}

		
		/*TEST_METHOD(TEST_sqlite_open_close)
		{
			sqlite3 *db;
			char *zErrMsg = 0;
			int rc;
			std::string res("ok"),ok("ok");

			rc = sqlite3_open("test_db.sql", &db);
			if (rc) {
				res = "Can't open database";
				sqlite3_close(db);	
			}

			sqlite3_close(db);

			Assert::AreEqual(ok.c_str(), res.c_str(), 0.01, L"sqlite_open_close failed", LINE_INFO());
		}*/
	};
}