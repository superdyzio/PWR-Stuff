/****************************************************************************
** Meta object code from reading C++ file 'OknoGlowne.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "inc/OknoGlowne.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OknoGlowne.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Okienko_t {
    QByteArrayData data[4];
    char stringdata[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Okienko_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Okienko_t qt_meta_stringdata_Okienko = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 16),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 17)
    },
    "Okienko\0zapiszUstawienia\0\0wczytajUstawienia\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Okienko[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a,
       3,    0,   25,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Okienko::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Okienko *_t = static_cast<Okienko *>(_o);
        switch (_id) {
        case 0: _t->zapiszUstawienia(); break;
        case 1: _t->wczytajUstawienia(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Okienko::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Okienko.data,
      qt_meta_data_Okienko,  qt_static_metacall, 0, 0}
};


const QMetaObject *Okienko::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Okienko::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Okienko.stringdata))
        return static_cast<void*>(const_cast< Okienko*>(this));
    return QDialog::qt_metacast(_clname);
}

int Okienko::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_OknoGlowne_t {
    QByteArrayData data[14];
    char stringdata[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_OknoGlowne_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_OknoGlowne_t qt_meta_stringdata_OknoGlowne = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 13),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 14),
QT_MOC_LITERAL(4, 41, 10),
QT_MOC_LITERAL(5, 52, 13),
QT_MOC_LITERAL(6, 66, 14),
QT_MOC_LITERAL(7, 81, 15),
QT_MOC_LITERAL(8, 97, 10),
QT_MOC_LITERAL(9, 108, 24),
QT_MOC_LITERAL(10, 133, 20),
QT_MOC_LITERAL(11, 154, 6),
QT_MOC_LITERAL(12, 161, 20),
QT_MOC_LITERAL(13, 182, 13)
    },
    "OknoGlowne\0moznaOdczytac\0\0dokonajOdczytu\0"
    "wizualizuj\0utworzOkienko\0odpalSymulacje\0"
    "obslugaZakladek\0nrZakladki\0"
    "obslugaZamknieciaOkienka\0obslugaWybraniaPliku\0"
    "indeks\0obslugaWybraniaPortu\0obslugaTimera\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OknoGlowne[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x0a,
       4,    0,   66,    2, 0x0a,
       5,    0,   67,    2, 0x0a,
       6,    0,   68,    2, 0x0a,
       7,    1,   69,    2, 0x0a,
       9,    0,   72,    2, 0x0a,
      10,    1,   73,    2, 0x0a,
      12,    1,   76,    2, 0x0a,
      13,    0,   79,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

void OknoGlowne::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OknoGlowne *_t = static_cast<OknoGlowne *>(_o);
        switch (_id) {
        case 0: _t->moznaOdczytac(); break;
        case 1: _t->dokonajOdczytu(); break;
        case 2: _t->wizualizuj(); break;
        case 3: _t->utworzOkienko(); break;
        case 4: _t->odpalSymulacje(); break;
        case 5: _t->obslugaZakladek((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->obslugaZamknieciaOkienka(); break;
        case 7: _t->obslugaWybraniaPliku((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->obslugaWybraniaPortu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->obslugaTimera(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OknoGlowne::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OknoGlowne::moznaOdczytac)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject OknoGlowne::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_OknoGlowne.data,
      qt_meta_data_OknoGlowne,  qt_static_metacall, 0, 0}
};


const QMetaObject *OknoGlowne::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OknoGlowne::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OknoGlowne.stringdata))
        return static_cast<void*>(const_cast< OknoGlowne*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int OknoGlowne::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void OknoGlowne::moznaOdczytac()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
