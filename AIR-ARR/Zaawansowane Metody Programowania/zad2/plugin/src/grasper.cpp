/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z2/trunk/plugin/src/grasper.cpp $
$Author: dperdek $
$Date: 2015-12-06 20:40:26 +0100 (nie) $
$Revision: 5 $
*/

#include "grasper.hh"

using std::cout;
using std::endl;

/*!
 * \file
 * \brief Plik zawiera implementację metod klasy Grasper.
*/

extern "C" {
  	Command* CreateCmd(void);
}

Command* CreateCmd() { 
	return Grasper::CreateCmd(); 
}

void Grasper::PrintCmd() const {
  	cout << GetCmdName() << " " << _stan << endl;
}

const char* Grasper::GetCmdName() const {
	return "Grasper";
}

bool Grasper::ExecCmd(RobotPose *pRobPose) const {
	// tutaj trzeba zaimplementować działanie komendy
	return true;
}

bool Grasper::ReadParams(std::istream& Strm_CmdsList) {
	Strm_CmdsList >> _stan;
	if (Strm_CmdsList.fail())
		return false;
	Strm_CmdsList.ignore(1000,'\n');
	if (_stan != 0 && _stan != 1) {
		cout << "Podano bledny stan chwytaka." << endl;
		return false;
	}
	return true;
}

Command* Grasper::CreateCmd() {
	return new Grasper();
}

void Grasper::PrintSyntax() const {
	cout << "Grasper stan[0/1]" << endl;
}
