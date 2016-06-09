/****************************************************************************
** Meta object code from reading C++ file 'ImageCapture.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt_opencv_2015/ImageCapture.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageCapture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageCapture_t {
    QByteArrayData data[17];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageCapture_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageCapture_t qt_meta_stringdata_ImageCapture = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ImageCapture"
QT_MOC_LITERAL(1, 13, 13), // "imageCaptured"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "QImage&"
QT_MOC_LITERAL(4, 36, 5), // "image"
QT_MOC_LITERAL(5, 42, 12), // "processImage"
QT_MOC_LITERAL(6, 55, 8), // "cv::Mat&"
QT_MOC_LITERAL(7, 64, 17), // "captureFromCamera"
QT_MOC_LITERAL(8, 82, 11), // "cameraIndex"
QT_MOC_LITERAL(9, 94, 9), // "timerTick"
QT_MOC_LITERAL(10, 104, 14), // "setDelayTo50ms"
QT_MOC_LITERAL(11, 119, 15), // "setDelayTo250ms"
QT_MOC_LITERAL(12, 135, 15), // "setDelayTo500ms"
QT_MOC_LITERAL(13, 151, 12), // "setDelayTo1s"
QT_MOC_LITERAL(14, 164, 14), // "setModeToVideo"
QT_MOC_LITERAL(15, 179, 14), // "setModeToImage"
QT_MOC_LITERAL(16, 194, 15) // "captureOneFrame"

    },
    "ImageCapture\0imageCaptured\0\0QImage&\0"
    "image\0processImage\0cv::Mat&\0"
    "captureFromCamera\0cameraIndex\0timerTick\0"
    "setDelayTo50ms\0setDelayTo250ms\0"
    "setDelayTo500ms\0setDelayTo1s\0"
    "setModeToVideo\0setModeToImage\0"
    "captureOneFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageCapture[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   80,    2, 0x0a /* Public */,
       7,    0,   83,    2, 0x2a /* Public | MethodCloned */,
       9,    0,   84,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    0,   88,    2, 0x0a /* Public */,
      14,    0,   89,    2, 0x0a /* Public */,
      15,    0,   90,    2, 0x0a /* Public */,
      16,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImageCapture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageCapture *_t = static_cast<ImageCapture *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageCaptured((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->processImage((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 2: _t->captureFromCamera((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->captureFromCamera(); break;
        case 4: _t->timerTick(); break;
        case 5: _t->setDelayTo50ms(); break;
        case 6: _t->setDelayTo250ms(); break;
        case 7: _t->setDelayTo500ms(); break;
        case 8: _t->setDelayTo1s(); break;
        case 9: _t->setModeToVideo(); break;
        case 10: _t->setModeToImage(); break;
        case 11: _t->captureOneFrame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageCapture::*_t)(QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageCapture::imageCaptured)) {
                *result = 0;
            }
        }
        {
            typedef void (ImageCapture::*_t)(cv::Mat & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageCapture::processImage)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ImageCapture::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageCapture.data,
      qt_meta_data_ImageCapture,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageCapture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageCapture::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageCapture.stringdata0))
        return static_cast<void*>(const_cast< ImageCapture*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageCapture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ImageCapture::imageCaptured(QImage & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageCapture::processImage(cv::Mat & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
