// PrintAllLastErrorString.cpp : コンソール アプリケーション用のエントリ ポイントの定義
//

#include "stdafx.h"
#include "../MyUtility/GetLastErrorString.h"
#include "sqlite3.h"

using namespace std;



static int callback(void *string, int argc, char **argv, char **azColName)
{
	string* pResult = (string*)pString;
	for(int i=0; i<argc; i++)
	{
		string strT;
		strT.Format("%s = %s\r\n", azColName[i], argv[i] ? argv[i] : "NULL");
		(*pResult) += strT;
	}
	return 0;
}
 
void CreateDB(LPCTSTR pFile, LPCTSTR pTableName
{
	sqlite3* pDB = NULL;
	string strResult;
	char* pErr = NULL;
 
	if ( SQLITE_OK != sqlite3_open(pFile, &pDB) )
	{
		goto Error_;
	}
 

	p = 
		"CREATE TABLE [%s] ("
		"[c0] INTEGER NOT NULL,"
		"[c2] TEXT,"
		"[c3] TEXT,"
		"[c4] TEXT,"
		"[c5] TEXT,"
		"[c6] TEXT,"
		"[c7] TEXT,"
		"[c8] TEXT,"
		"[c9] TEXT);";

	// akita



	wsprintf(pBuff, pTableName
	if ( SQLITE_OK != fn_sqlite3_exec(db_, 
		p,
		callbackt,
		&strResult,
		&pErr) || pErr)
	{
		goto Error_;
	}

	if ( SQLITE_OK != sqlite3_exec(
		pDB, 
		"insert into select * from testtable",
		callback,
		&strResult,
		&pErr) )
	{
		AfxMessageBox(pErr);
		goto Error_;
	}
 
 
	MessageBox(strResult);
 
Error_:
	if ( pErr )
		sqlite3_free(pErr);
 
	if ( pDB )
		sqlite3_close(pDB);
 
 
}
int main(int argc, char* argv[])
{
	for(DWORD dw=0 ; dw <= 0xFFFFFFFF ; ++dw)
	{
		BOOL b=FALSE;
		string str = GetLastErrorString(dw, &b);
		
		if(b)
			cout << dw << _T("\t") << str << endl;
	}
		
		
	return 0;
}

