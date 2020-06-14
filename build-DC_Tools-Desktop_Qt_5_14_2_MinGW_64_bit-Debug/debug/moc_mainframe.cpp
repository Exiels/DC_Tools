/****************************************************************************
** Meta object code from reading C++ file 'mainframe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DC_Tools/mainframe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainFrame_t {
    QByteArrayData data[21];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainFrame_t qt_meta_stringdata_MainFrame = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MainFrame"
QT_MOC_LITERAL(1, 10, 12), // "generateCode"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "generateCodeIa"
QT_MOC_LITERAL(4, 39, 17), // "generateCodeGlace"
QT_MOC_LITERAL(5, 57, 5), // "About"
QT_MOC_LITERAL(6, 63, 10), // "newProgram"
QT_MOC_LITERAL(7, 74, 7), // "Program"
QT_MOC_LITERAL(8, 82, 8), // "newGlace"
QT_MOC_LITERAL(9, 91, 5), // "Glace"
QT_MOC_LITERAL(10, 97, 6), // "config"
QT_MOC_LITERAL(11, 104, 5), // "newIa"
QT_MOC_LITERAL(12, 110, 2), // "Ia"
QT_MOC_LITERAL(13, 113, 7), // "updater"
QT_MOC_LITERAL(14, 121, 8), // "uGlaceCm"
QT_MOC_LITERAL(15, 130, 4), // "etat"
QT_MOC_LITERAL(16, 135, 5), // "addCM"
QT_MOC_LITERAL(17, 141, 6), // "addLvl"
QT_MOC_LITERAL(18, 148, 12), // "stateChanged"
QT_MOC_LITERAL(19, 161, 4), // "Slvl"
QT_MOC_LITERAL(20, 166, 10) // "uniqIDShow"

    },
    "MainFrame\0generateCode\0\0generateCodeIa\0"
    "generateCodeGlace\0About\0newProgram\0"
    "Program\0newGlace\0Glace\0config\0newIa\0"
    "Ia\0updater\0uGlaceCm\0etat\0addCM\0addLvl\0"
    "stateChanged\0Slvl\0uniqIDShow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainFrame[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x0a /* Public */,
       7,    0,  104,    2, 0x0a /* Public */,
       8,    0,  105,    2, 0x0a /* Public */,
       9,    0,  106,    2, 0x0a /* Public */,
      10,    0,  107,    2, 0x0a /* Public */,
      11,    0,  108,    2, 0x0a /* Public */,
      12,    0,  109,    2, 0x0a /* Public */,
      13,    0,  110,    2, 0x0a /* Public */,
      14,    1,  111,    2, 0x0a /* Public */,
      16,    0,  114,    2, 0x0a /* Public */,
      17,    0,  115,    2, 0x0a /* Public */,
      18,    1,  116,    2, 0x0a /* Public */,
      20,    0,  119,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void,

       0        // eod
};

void MainFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->generateCode(); break;
        case 1: _t->generateCodeIa(); break;
        case 2: _t->generateCodeGlace(); break;
        case 3: _t->About(); break;
        case 4: _t->newProgram(); break;
        case 5: _t->Program(); break;
        case 6: _t->newGlace(); break;
        case 7: _t->Glace(); break;
        case 8: _t->config(); break;
        case 9: _t->newIa(); break;
        case 10: _t->Ia(); break;
        case 11: _t->updater(); break;
        case 12: _t->uGlaceCm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->addCM(); break;
        case 14: _t->addLvl(); break;
        case 15: _t->stateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->uniqIDShow(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainFrame.data,
    qt_meta_data_MainFrame,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainFrame.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
