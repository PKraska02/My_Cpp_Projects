#pragma once
#include <Windows.h>
#ifdef CPPCOLORREMOVERLIB_EXPORTS
#define CPPCOLORREMOVERLIB_API __declspec(dllexport)
#else
#define CPPCOLORREMOVERLIB_API __declspec(dllimport)
#endif

//extern "C" CPPCOLORREMOVERLIB_API void fibonacci_init(
//    const unsigned long long a, const unsigned long long b);
//
//extern "C" CPPCOLORREMOVERLIB_API bool fibonacci_next();
//
//// Get the current value in the sequence.
//extern "C" CPPCOLORREMOVERLIB_API unsigned long long fibonacci_current();
//
//// Get the position of the current value in the sequence.
//extern "C" CPPCOLORREMOVERLIB_API unsigned fibonacci_index();
extern "C" __declspec(dllexport) COLORREF RemoveColor(COLORREF inputColor, int power);
extern "C" __declspec(dllexport) void ProcessImageCPP(BYTE * imageData, int width, int height, int power, int xValues[32], int yValues[32], int pointcount);
extern "C" __declspec(dllexport) bool IsPointInsidePolygon(int x, int y, int xValues[32], int yValues[32], int pointcount);