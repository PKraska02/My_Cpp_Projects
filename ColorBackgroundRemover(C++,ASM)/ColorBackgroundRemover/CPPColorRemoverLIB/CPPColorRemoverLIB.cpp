
#include "pch.h" 
#include <utility>
#include <limits.h>
#include "CPPColorRemoverLIB.h"
#include <Windows.h>


extern "C" __declspec(dllexport) void ProcessImageCPP(BYTE * imageData, int width, int height, int power)
{
    // Iterate through each pixel in the image
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            // Calculate the index of the current pixel
            int index = (y * width + x) * 3;

            // Extract RGB components
            int red = imageData[index];
            int green = imageData[index + 1];
            int blue = imageData[index + 2];

            // Modify RGB components based on power
            red = max(0, min(255, red * ((power * 0.01))));
            green = max(0, min(255, green * ((power * 0.01))));
            blue = max(0, min(255, blue * ((power * 0.01))));

            // Update the image data with the modified color
            imageData[index] = static_cast<BYTE>(red);
            imageData[index + 1] = static_cast<BYTE>(green);
            imageData[index + 2] = static_cast<BYTE>(blue);
        }
    }
}


extern "C" __declspec(dllexport) COLORREF RemoveColor(COLORREF inputColor, int power)
{
    // Extract RGB components
    int red = GetRValue(inputColor);
    int green = GetGValue(inputColor);
    int blue = GetBValue(inputColor);

    // Modify RGB components based on power
    red = max(0, min(255, red * ((power * 0.01))));
    green = max(0, min(255, green * ((power * 0.01))));
    blue = max(0, min(255, blue * ((power * 0.01))));

    // Return the modified color
    return RGB(red, green, blue);
}
