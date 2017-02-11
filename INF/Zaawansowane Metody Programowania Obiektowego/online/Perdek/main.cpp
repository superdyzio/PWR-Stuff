#include "CPathOrganizer.h"

int main() {
	CPathOrganizer c_org; 
	int i_main_id_0, i_main_id_1; 
	int i_sub_id_0, i_sub_id_1; 
	int i_error; 
 
	c_org.vSetRoot("d:/Users/ua07/Desktop/test");
	i_main_id_0 = c_org. iAddMainFolder("main_0"); 
	i_main_id_1 = c_org. iAddMainFolder("main_1"); 
	i_sub_id_0 = c_org. iAddSubFolder (i_main_id_0, "sub_0"); 
	i_sub_id_1 = c_org. iAddSubFolder (i_main_id_0, "sub_1"); 
	c_org. iAddSubFolder (i_sub_id_1, "sub_sub_0"); 
	c_org. iAddSubFolder (i_sub_id_1, "sub_sub_1"); 
	i_error = c_org.iGenerate();// w tym momencie generowane jest drzewo katalogów 
	if (i_error != 0) cout << "wystapil blad przy tworzeniu";
	i_error = c_org. iDestroy ();// w tym momencie niszczone jest drzewo katalogów 
	if (i_error != 0) cout << "wystapil blad przy niszczeniu";
	
	return 0;
}