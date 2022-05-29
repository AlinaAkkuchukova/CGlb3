#ifndef GLUT_BACKEND_H
#define GLUT_BACKEND_H

#include "callbacks.h"

void GLUTBackendInit(int argc, char** argv); //упрощает инициализацию GLUT'а и создает окно использу€ простую функцию

bool GLUTBackendCreateWindow(unsigned int Width, unsigned int Height, unsigned int bpp, bool isFullScreen, const char* pTitle);

void GLUTBackendRun(ICallbacks* pCallbacks); //интерфейс ICallbacks, который поможет в регистрации функций обратного вызова

#endif /* GLUT_BACKEND_H */

