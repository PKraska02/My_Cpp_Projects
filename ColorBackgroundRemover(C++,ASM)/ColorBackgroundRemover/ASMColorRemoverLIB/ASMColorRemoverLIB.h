#pragma once

#include <Windows.h>
#ifdef ASMCOLORREMOVERLIB_EXPORTS
#define ASMCOLORREMOVERLIB_API __declspec(dllexport)
#else
#define ASMCOLORREMOVERLIB_API __declspec(dllimport)
#endif

//extern ASMCOLORREMOVERLIB_API int testx1;
extern "C" ASMCOLORREMOVERLIB_API void inline ProcessImageASM(int red, int green, int blue, int power);
