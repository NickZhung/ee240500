/****************************************************************************
** Meta object code from reading C++ file 'ImageProcess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt_opencv_2015/ImageProcess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageProcess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageProcess_t {
    QByteArrayData data[10];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageProcess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageProcess_t qt_meta_stringdata_ImageProcess = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ImageProcess"
QT_MOC_LITERAL(1, 13, 12), // "processImage"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "cv::Mat&"
QT_MOC_LITERAL(4, 36, 5), // "image"
QT_MOC_LITERAL(5, 42, 14), // "changeToNormal"
QT_MOC_LITERAL(6, 57, 21), // "changeToEdgeDetection"
QT_MOC_LITERAL(7, 79, 23), // "changeToCircleDetection"
QT_MOC_LITERAL(8, 103, 23), // "changeToSquareDetection"
QT_MOC_LITERAL(9, 127, 21) // "changeToLineDetection"

    },
    "ImageProcess\0processImage\0\0cv::Mat&\0"
    "image\0changeToNormal\0changeToEdgeDetection\0"
    "changeToCircleDetection\0changeToSquareDetection\0"
    "changeToLineDetection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageProcess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,
       8,    0,   50,    2, 0x0a /* Public */,
       9,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImageProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageProcess *_t = static_cast<ImageProcess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processImage((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->changeToNormal(); break;
        case 2: _t->changeToEdgeDetection(); break;
        case 3: _t->changeToCircleDetection(); break;
        case 4: _t->changeToSquareDetection(); break;
        case 5: _t->changeToLineDetection(); break;
        default: ;
        }
    }
}

const QMetaObject ImageProcess::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ImageProcess.data,
      qt_meta_data_ImageProcess,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcess.stringdata0))
        return static_cast<void*>(const_cast< ImageProcess*>(this));
    return QThread::qt_metacast(_clname);
}

int ImageProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
