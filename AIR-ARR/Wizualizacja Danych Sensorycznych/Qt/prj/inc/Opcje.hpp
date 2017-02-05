/*!
 * \file
 * \brief Plik nagłówkowy klasy Wykres.
*/

#ifndef OPCJE_H
#define OPCJE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

/*!
 * \brief Klasa odpowiedzialna wybór opcji programu.
 *
 * Klasa Opcje dziedziczy po klasie QDialog i odpowiada za wybór opcji programu.
*/
class Opcje : public QDialog {
public:
/*!
 * \brief Wskaźnik na obiekt typu QFontComboBox odpowiedzialny za rozwijaną listę wyboru portu.
*/
    	QFontComboBox *fontComboBox;
/*!
 * \brief Wskaźnik na obiekt typu QFontComboBox odpowiedzialny za rozwijaną listę wyboru pliku.
*/
    	QFontComboBox *fontComboBox_2;
/*!
 * \brief Wskaźnik na obiekt typu QPushButton odpowiedzialny za przycisk zapisu ustawień jako domyślne.
*/
    	QPushButton *pushButton_3;
/*!
 * \brief Wskaźnik na obiekt typu QLabel odpowiedzialny za etykietę wyboru portu.
*/
    	QLabel *label;
/*!
 * \brief Wskaźnik na obiekt typu QLabel odpowiedzialny za etykietę wyboru pliku.
*/
    	QLabel *label_2;
/*!
 * \brief Wskaźnik na obiekt typu QPushButton odpowiedzialny za przycisk anulowania wyboru.
*/
    	QPushButton *pushButton_2;
/*!
 * \brief Wskaźnik na obiekt typu QPushButton odpowiedzialny za przycisk potwierdzenia zmian.
*/
    	QPushButton *pushButton;
/*!
 * \brief Metoda odpowiedzialna za ustawienie interfejsu użytkownika. 
 * \param[in] Dialog - wskaźnik na obiekt typu QDialog
 * \return Nic nie jest zwracane.
*/
    	void setupUi(QDialog *Dialog);
/*!
 * \brief Metoda odpowiedzialna za ustawienie interfejsu użytkownika.
 * \param[in] Dialog - wskaźnik na obiekt typu QDialog 
 * \return Nic nie jest zwracane.
*/
    	void retranslateUi(QDialog *Dialog);
};

#endif
