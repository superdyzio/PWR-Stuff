/*!
 * \file
 * \brief Plik źródłowy klasy Wykres.
*/

#include "Opcje.hpp"

void Opcje::setupUi(QDialog *Dialog) {
	if (Dialog->objectName().isEmpty())
        	Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(480, 234);
        fontComboBox = new QFontComboBox(Dialog);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(110, 120, 341, 27));
        fontComboBox_2 = new QFontComboBox(Dialog);
        fontComboBox_2->setObjectName(QStringLiteral("fontComboBox_2"));
        fontComboBox_2->setGeometry(QRect(110, 40, 341, 27));
        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 180, 201, 31));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 91, 16));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 161, 31));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 180, 99, 31));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 180, 99, 31));
        retranslateUi(Dialog);
        QMetaObject::connectSlotsByName(Dialog);
}

void Opcje::retranslateUi(QDialog *Dialog) {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        pushButton_3->setText(QApplication::translate("Dialog", "Zapisz jako domy\305\233lne", 0));
        label->setText(QApplication::translate("Dialog", "Wyb\303\263r portu", 0));
        label_2->setText(QApplication::translate("Dialog", "Wyb\303\263r pliku symulacji", 0));
        pushButton_2->setText(QApplication::translate("Dialog", "Anuluj", 0));
        pushButton->setText(QApplication::translate("Dialog", "OK", 0));
}
