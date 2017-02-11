/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z2/trunk/plugin/src/command4move.cpp $
$Author: dperdek $
$Date: 2015-12-04 22:30:22 +0100 (pią) $
$Revision: 2 $
*/

#include "command4move.hh"

using std::cout;
using std::endl;

/*!
 * \file
 * \brief Plik zawiera implementację metod klasy Command4Move.
 */

extern "C" {
  	Command* CreateCmd(void);
}

Command* CreateCmd() { 
	return Command4Move::CreateCmd(); 
}
void Command4Move::PrintCmd() const {
  	cout << GetCmdName() << " " << _Speed_mmS  << " " << _Distance_mm << endl;
}

const char* Command4Move::GetCmdName() const {
  	return "Move";
}

bool Command4Move::ExecCmd(RobotPose *pRobPose) const {
	double x, y, alpha, stepSize, xStepSize, yStepSize, Time_ms, alphaRad;
	Time_ms = 100*(_Distance_mm/_Speed_mmS);
	stepSize = _Distance_mm/Time_ms;
	pRobPose->Get(x,y,alpha);
	alphaRad = (alpha*M_PI)/180;
	xStepSize = cos(alphaRad) * stepSize;
	yStepSize = sin(alphaRad) * stepSize;
	for (int i = 0; i < Time_ms; i++) {
		x += xStepSize;
		y += yStepSize;
		if (!pRobPose->Set(x,y))
			return false;
		usleep(10000);
	}
	return true;
}

bool Command4Move::ReadParams(std::istream& Strm_CmdsList) {
	Strm_CmdsList >> _Speed_mmS >> _Distance_mm;
	if (Strm_CmdsList.fail())
		return false;
	Strm_CmdsList.ignore(1000,'\n');
	if (_Speed_mmS == 0 && _Distance_mm != 0) {
		cout << "Przy zerowej prędkości dystans również musi wynosić zero." << endl;
		return false;
	}
	else if (_Distance_mm <= 0) {
		cout << "Dystans musi być większy od zera." << endl;
		return false;
	}
  	return true;
}

Command* Command4Move::CreateCmd() {
  	return new Command4Move();
}

void Command4Move::PrintSyntax() const {
  	cout << "Move speed[mm/s] dist[mm/s]" << endl;
}
