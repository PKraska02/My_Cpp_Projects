
#include "pch.h" 
#include <utility>
#include <limits.h>
#include "CPPColorRemoverLIB.h"
#include <Windows.h>
#include <iostream>
#include <fstream>


extern "C" __declspec(dllexport) void ProcessImageCPP(BYTE * imageData, int width, int height, int power, int xValues[32], int yValues[32], int pointcount, int new_red, int new_green, int new_blue,int y1,int y2)
{
    // Iterate through each pixel in the image
    for (int y = y1; y <y2; ++y)
    {
        for (int x = 5; x < width-5; ++x)
        {
            // Calculate the index of the current pixel
            int index = (y * width + x) * 3;

            // Check if the pixel is inside the polygon
            if (!IsPointInsidePolygon(x, y, xValues, yValues, pointcount))
            {
                // Extract RGB components
                // Modify RGB components based on power and update the image data directly
                imageData[index] = static_cast<BYTE>(max(0, min(255, imageData[index] - static_cast<int>(new_red * (power * 0.01)))));
                imageData[index + 1] = static_cast<BYTE>(max(0, min(255, imageData[index + 1] - static_cast<int>(new_green * (power * 0.01)))));
                imageData[index + 2] = static_cast<BYTE>(max(0, min(255, imageData[index + 2] - static_cast<int>(new_blue * (power * 0.01)))));

            }
        }
    }
}


extern "C" __declspec(dllexport) bool IsPointInsidePolygon(int x, int y, int xValues[32], int yValues[32], int pointcount)
{
    bool inside = false;
    int count = 0;

    for (int i = 0, j = pointcount - 1; i < pointcount; j = i++) {
        
        if ((yValues[i] > y) != (yValues[j] > y) &&
            (x < (xValues[j] - xValues[i]) * static_cast<double>(y - yValues[i]) / static_cast<double>(yValues[j] - yValues[i]) + xValues[i])) {
            count += 1;
        }
  
    }

    inside = (count % 2 == 1);
    return inside;
}





