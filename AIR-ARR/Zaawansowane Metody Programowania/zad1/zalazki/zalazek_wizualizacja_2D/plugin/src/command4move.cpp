#include <iostream>
#include <unistd.h>
#include "command4move.hh"

using std::cout;
using std::endl;


extern "C" {
  Command* CreateCmd(void);
}




/*!
 * \brief
 *
 *
 */
Command* CreateCmd(void)
{
  return Command4Move::CreateCmd();
}


/*!
 *
 */
Command4Move::Command4Move(): _Speed_mmS(0)
{}


/*!
 *
 */
void Command4Move::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " " << _Speed_mmS  << " 300" << endl;
}


/*!
 *
 */
const char* Command4Move::GetCmdName() const
{
  return "Move";
}


/*!
 *
 */
bool Command4Move::ExecCmd( RobotPose     *pRobPose ) const
{
  // To jest tylko przyklad

  pRobPose->Set(5,5,45);
  usleep(300000);
  pRobPose->Set(10,10,45);
  usleep(300000);
  pRobPose->Set(15,15,45);
  usleep(300000);
  pRobPose->Set(20,20,45);
  usleep(300000);

  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Command4Move::ReadParams(std::istream& Strm_CmdsList)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
Command* Command4Move::CreateCmd()
{
  return new Command4Move();
}


/*!
 *
 */
void Command4Move::PrintSyntax() const
{
  cout << "   Move speed[mm/s] dist[mm/s]" << endl;
}
