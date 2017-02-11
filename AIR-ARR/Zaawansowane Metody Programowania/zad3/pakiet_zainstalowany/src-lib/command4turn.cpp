/*
$HeadURL: file:///home/dperdek/repos/z1/trunk/plugin/src/command4turn.cpp $
$Author: dperdek $
$Date: 2015-11-17 02:39:31 +0100 (Tue, 17 Nov 2015) $
$Revision: 9 $
*/

#include "command4turn.hh"

using std::cout;
using std::endl;

/*!
 * \file
 * \brief Plik zawiera implementację metod klasy Command4Turn.
*/

extern "C" {
  	Command* CreateCmd(void);
}

Command* CreateCmd() { 
	return Command4Turn::CreateCmd(); 
}

void Command4Turn::PrintCmd() const {
  	cout << GetCmdName() << " " << _Speed_mmS  << " " << _Distance_mm << " " << _Radius_mm << endl;
}

const char* Command4Turn::GetCmdName() const {
	return "Turn";
}

bool Command4Turn::ExecCmd(RobotPose *pRobPose) const {
	double x, y, alpha, alphaRad, alphaAlt, cX, cY;
	pRobPose->Get(x,y,alpha);
	alphaRad = (alpha*M_PI)/180;
	double RotAngle =  _Distance_mm/_Radius_mm;
	double t = 100*(_Distance_mm/_Speed_mmS);
	double stepRad = RotAngle/t;
	cX = x - (sin(alphaRad)*_Radius_mm);
	cY = y + (cos(alphaRad)*_Radius_mm);
	if (_Radius_mm > 0) {
		for (int i = 0; i <= t; i++) {
			x = cX + ( sin( (i*stepRad)+alphaRad ) * _Radius_mm );
			y = cY - ( cos( (i*stepRad)+alphaRad ) * _Radius_mm );
			alphaAlt = alpha+(i*stepRad*180/(M_PI));
			pRobPose->Set(x,y,alphaAlt);
			usleep(10000);
		}
		x = cX + (sin(RotAngle+alphaRad)*_Radius_mm);
		y = cY - (cos(RotAngle+alphaRad)*_Radius_mm);
		alphaAlt = alpha+(RotAngle*180/(M_PI));
		pRobPose->Set(x,y,alphaAlt);
  	} else if (_Radius_mm < 0) {
		for (int i = 0; i <= t; i++) {
			x = cX - ( sin( (i*stepRad)-alphaRad ) * _Radius_mm );
			y = cY + ( cos( (i*stepRad)-alphaRad ) * _Radius_mm );
			alphaAlt = alpha-(-i*stepRad*180/(M_PI));
			pRobPose->Set(x,y,alphaAlt);
			usleep(10000);
		}
		x = cX - ( sin( RotAngle-alphaRad ) * _Radius_mm );
		y = cY + ( cos( RotAngle-alphaRad ) * _Radius_mm );
		alphaAlt = alpha-(-RotAngle*180/(M_PI));
		pRobPose->Set(x,y,alphaAlt);
	}
	return true;
}

bool Command4Turn::ReadParams(std::istream& Strm_CmdsList) {
	Strm_CmdsList >> _Speed_mmS >> _Distance_mm >> _Radius_mm;
	if (Strm_CmdsList.fail())
		return false;
	Strm_CmdsList.ignore(1000,'\n');
	if (_Radius_mm == 0) {
		cout << "Promień skrętu nie może być zerowy." << endl;
		return false;
	}
	else if (_Speed_mmS == 0 && _Distance_mm != 0) {
		cout << "Przy zerowej prędkości dystans również musi wynosić zero." << endl;
		return false;
	}
	else if (_Distance_mm <= 0) {
		cout << "Dystans musi być większy od zera." << endl;
		return false;
	}
	return true;
}

Command* Command4Turn::CreateCmd() {
	return new Command4Turn();
}

void Command4Turn::PrintSyntax() const {
	cout << "Turn speed[mm/s] distance[mm] radius[mm]" << endl;
}
