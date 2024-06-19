TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        inference.cpp \
        main.cpp

HEADERS += \
    inference.h

INCLUDEPATH += /usr/local/include \
               /usr/local/include/opencv4/opencv2 \
               /usr/local/include/opencv4 \
               /home/cj/chaintwork/onnxruntime-linux-x64-1.17.1/include \



LIBS += /usr/local/lib/libopencv_*.so \
        /home/cj/chaintwork/onnxruntime-linux-x64-1.17.1/lib/libonnxruntime.so \

# Set ONNXRUNTIME_ROOT variable
ONNXRUNTIME_VERSION = 1.17.1
ONNXRUNTIME_ROOT = /home/cj/chaintwork/onnxruntime-linux-x64-$${ONNXRUNTIME_VERSION}
INCLUDEPATH += $$ONNXRUNTIME_ROOT/include
LIBS += -L$$ONNXRUNTIME_ROOT/lib -lonnxruntime


