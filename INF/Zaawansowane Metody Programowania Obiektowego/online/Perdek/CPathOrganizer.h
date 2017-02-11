#ifndef CPATHORGANIZER_H
#define CPATHORGANIZER_H

#include <cstdlib>
#include <direct.h>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <Windows.h>

#define MAXSIZE 5

using namespace std;

class CElement {

public:
	int i_id;
	int i_parent;
	string s_name;
	CElement(int iId, int iParent, string sName):i_id(iId),i_parent(iParent),s_name(sName) {};
} typedef CElement;


class CPathOrganizer {
	int i_dir_nr;
	string s_root;
	vector<CElement> c_tab;

public:
	CPathOrganizer():i_dir_nr(0),s_root("") {};
	~CPathOrganizer() {}

	void vSetRoot(string sPath) { s_root = sPath; }
	int iAddMainFolder(string sFolderName);
	int iAddSubFolder(int iParentFolderId, string sFolderName);

	int iGenerate();
	int iDestroy();
} typedef CPathOrganizer;

#endif