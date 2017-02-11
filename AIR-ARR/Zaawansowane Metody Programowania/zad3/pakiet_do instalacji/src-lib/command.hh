#ifndef  COMMAND_HH
#define  COMMAND_HH

#include <iostream>
#include "robotpose.hh"

/*!
 * \file
 * \brief Definicja klasy Command
 *
 * Plik zawiera definicję klasy Command ...
 */

/*!
 * \brief Modeluje abstrakcyjne polecenie dla robota mobilnego
 *
 *  Klasa modeluje ...
 */
 class Command {
  public:
   /*!
    * \brief Destruktor wirtualny ze wzgledu na klasy pochodne
    *
    *  
    */
   virtual ~Command() {}
   /*!
    * \brief
    */
   virtual void PrintCmd() const = 0;
   /*!
    * \brief
    */
   virtual void PrintSyntax() const = 0;
   /*!
    * \brief
    */
   virtual const char* GetCmdName() const = 0;
   /*!
    * \brief
    */
   virtual bool ExecCmd(  RobotPose  *pRobPose  ) const = 0;
   /*!
    * \brief
    */
   virtual bool ReadParams(std::istream& Strm_CmdsList) = 0;
 };

#endif
