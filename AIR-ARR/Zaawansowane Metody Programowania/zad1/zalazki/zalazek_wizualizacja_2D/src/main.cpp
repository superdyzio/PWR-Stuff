#include <iostream>
#include <iomanip>
#include <dlfcn.h>
#include <cassert>
#include <unistd.h>

#include "command.hh"
#include "RobotMobilny.hh"
#include "lacze_do_gnuplota.hh"

using namespace std;



int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  RobotMobilny  Robot(&Lacze);

  Lacze.Inicjalizuj();
  Lacze.ZmienTrybRys(PzG::TR_2D);

  Lacze.UstawZakresY(-10,40);
  Lacze.UstawZakresX(-10,40);

  Robot.Init();  // Tutaj następuje również rysowanie.


  void *pLibHnd_Move = dlopen("command4move.so",RTLD_LAZY);
  Command *(*pCreateCmd_Move)(void);
  void *pFun;

  if (!pLibHnd_Move) {
    cerr << "!!! Brak biblioteki: command4move.so" << endl;
    return 1;
  }


  pFun = dlsym(pLibHnd_Move,"CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Move = *reinterpret_cast<Command* (**)(void)>(&pFun);


  Command *pCmd = pCreateCmd_Move();

  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;
  cout << " Prosze zaczekac ... " << flush;
  sleep(1);
  cout << "\r Robot jedzie ;)    " << flush;
  pCmd->ExecCmd(&Robot);




  delete pCmd;

  dlclose(pLibHnd_Move);

  cout << "\r";
  cout << " Aby zakonczyc nacisnij ENTER." << flush;
  cin.ignore(1000,'\n');
}
