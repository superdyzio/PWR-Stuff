#include "CPathOrganizer.h"

int CPathOrganizer::iAddMainFolder(string CFolderName) {
	i_dir_nr++;
	CElement* cPom = new CElement(i_dir_nr,0,CFolderName);
	c_tab.push_back(*cPom);
	return i_dir_nr;
}

int CPathOrganizer::iAddSubFolder(int iParentFolderId, string CFolderName) {
	i_dir_nr++;
	CElement* cPom = new CElement(i_dir_nr,iParentFolderId,CFolderName);
	c_tab.push_back(*cPom);
	return i_dir_nr;
}

int CPathOrganizer::iGenerate() {
	string sSlash = "/";
	for (CElement cEl:c_tab) 
		if (cEl.i_parent == 0) _mkdir((s_root+sSlash+cEl.s_name).c_str());
	for (CElement cEl:c_tab)
		if (cEl.i_parent > 0) {

		}
	return 0;
}

int CPathOrganizer::iDestroy() {
	for (int i = c_tab.size()-1; i>=0; i--) {
		CElement cPom = c_tab.at(i);
		_rmdir((cPom.s_name).c_str());
	}
	return 0;
}