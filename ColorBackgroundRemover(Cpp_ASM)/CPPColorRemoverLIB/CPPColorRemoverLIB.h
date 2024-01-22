#pragma once
#include <Windows.h>
#ifdef CPPCOLORREMOVERLIB_EXPORTS
#define CPPCOLORREMOVERLIB_API __declspec(dllexport)
#else
#define CPPCOLORREMOVERLIB_API __declspec(dllimport)
#endif

extern "C" __declspec(dllexport) void ProcessImageCPP(BYTE * imageData, int width, int height, int power, int xValues[32], int yValues[32],int pointcount, int new_red,int new_green,int new_blue);
//extern "C" __declspec(dllexport) void ProcessImageCPP2(int& red, int& green, int& blue, int power, int new_red, int new_green, int new_blue);
extern "C" __declspec(dllexport) bool IsPointInsidePolygon(int x, int y, int xValues[32], int yValues[32], int pointcount);