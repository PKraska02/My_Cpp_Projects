
#include "pch.h" 
#include <utility>
#include <limits.h>
#include "CPPColorRemoverLIB.h"
#include <Windows.h>


extern "C" __declspec(dllexport) void ProcessImageCPP(BYTE * imageData, int width, int height, int power, int xValues[32], int yValues[32],int pointcount)
{
    // Iterate through each pixel in the image
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            // Check if the pixel is inside the polygon defined by xValues and yValues
            if (!IsPointInsidePolygon(x, y, xValues, yValues,pointcount))
            {
                // Calculate the index of the current pixel
                int index = (y * width + x) * 3;

                // Extract RGB components
                int red = imageData[index];
                int green = imageData[index + 1];
                int blue = imageData[index + 2];

                // Modify RGB components based on power
                red = max(0, min(255, red - (red * (power * 0.01))));
                green = max(0, min(255, green - (green * (power * 0.01))));
                blue = max(0, min(255, blue - (blue * (power * 0.01))));

                // Update the image data with the modified color
                imageData[index] = static_cast<BYTE>(red);
                imageData[index + 1] = static_cast<BYTE>(green);
                imageData[index + 2] = static_cast<BYTE>(blue);
            }
        }
    }
}
extern "C" __declspec(dllexport) void ProcessImageCPP2(int& red, int& green, int& blue, int power) {

    red = max(0, min(255, red - (red * (power * 0.01))));
    green = max(0, min(255, green - (green * (power * 0.01))));
    blue = max(0, min(255, blue - (blue * (power * 0.01))));
}

extern "C" __declspec(dllexport) bool IsPointInsidePolygon(int x, int y, int xValues[32], int yValues[32], int pointcount)
{
    bool inside = false;

    for (int i = 0, j = pointcount - 1; i < pointcount; j = i++) {
        if ((yValues[i] > y) != (yValues[j] > y) &&
            (x < (xValues[j] - xValues[i]) * (y - yValues[i]) / (yValues[j] - yValues[i]) + xValues[i])) {
            inside = !inside;
        }
    }

    return inside;
}


