/*
$HeadURL: file:///home/dperdek/repos/z1/trunk/plugin/src/command4rotate.cpp $
$Author: dperdek $
$Date: 2015-11-17 02:39:31 +0100 (Tue, 17 Nov 2015) $
$Revision: 9 $
*/

#include "command4rotate.hh"

using std::cout;
using std::endl;

/*!
 * \file
 * \brief Plik zawiera implementację metod klasy Command4Rotate.
*/

extern "C" {
  	Command* CreateCmd(void);
}

Command* CreateCmd() { 
	return Command4Rotate::CreateCmd(); 
}

void Command4Rotate::PrintCmd() const {
	cout << GetCmdName() << " " << _Speed_oS  << " " << _Angle_o << endl;
}

const char* Command4Rotate::GetCmdName() const {
  	return "Rotate";
}

bool Command4Rotate::ExecCmd(RobotPose *pRobPose) const {
	double x, y, alpha, Time_ms, rotate_step;
	Time_ms = 100*(_Angle_o/_Speed_oS);
	rotate_step = _Angle_o/Time_ms;
	pRobPose->Get(x,y,alpha);
	for (int i = 0; i < Time_ms; i++) {
		alpha += rotate_step;
		pRobPose->SetAlpha(alpha);
		usleep(10000);
	}
	return true;
}

bool Command4Rotate::ReadParams(std::istream& Strm_CmdsList) {
	Strm_CmdsList >> _Speed_oS >> _Angle_o ;
	if (Strm_CmdsList.fail())
		return false;
	Strm_CmdsList.ignore(1000,'\n');
	if (_Speed_oS == 0 && _Angle_o != 0) {
		cout << "Przy zerowej prędkości kątowej kąt obrotu musi być zerowy." << endl;
		return false;
	}
	else if (_Angle_o <= 0) {
		cout << "Kąt obrotu musi być większy od zera." << endl;
		return false;
	}
	return true;
}

Command* Command4Rotate::CreateCmd() {
  	return new Command4Rotate();
}

void Command4Rotate::PrintSyntax() const {
  	cout << "Rotate speed[o/s] angle[o]" << endl;
}
