#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "command.hh"

/*!
 * \file
 * \brief Definicja klasy Command4Move
 *
 * Plik zawiera definicję klasy Command4Move ...
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego ruch do przodu
 *
 *  Klasa modeluje ...
 */
class Command4Move: public Command {
  /*
   *  Tu należy zdefiniować pola, które są niezbędne
   *  do przechowywania wartości parametrów danego polecenia.
   *  Ponieżej zdefiniowane jest tylko jedno pole jako przykład.
   */
  double  _Speed_mmS;
 public:
  /*!
   * \brief
   */
  Command4Move();  
  /*!
   * \brief
   */
  virtual void PrintCmd() const;
  /*!
   * \brief
   */
  virtual void PrintSyntax() const;
  /*!
   * \brief
   */
  virtual const char* GetCmdName() const;
  /*!
   * \brief
   */
  virtual bool ExecCmd( RobotPose  *pRobPose  ) const;
  /*!
   * \brief
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  /*!
   * \brief
   *
   *  Ta metoda nie musi być zdefiniowna w klasie bazowej.
   */
  static Command* CreateCmd();
 };

#endif
