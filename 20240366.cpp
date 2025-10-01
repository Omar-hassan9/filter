//
#include <iostream>
using namespace std;
#include "Image_Class.h"
int main() {
    string filename;
   cout << "Pls enter colored image name that you want to apply filter: ";
    cin >> filename;
    Image image(filename);
    int filter;
    cout << "enter the filter that you want to apply (grayscale/darken / lighten): \n";
    cout << "1: grayscale\n2: darken\n3: lighten\n4:exit\n";
    cin >> filter;
if(filter==1)
{
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0;

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); 
            }
            avg /= 3; 

            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
}
else if(filter==2)
{
        for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int newPixels = image(i, j, k) * 0.5;


                if (newPixels > 255) newPixels = 255;
                if (newPixels < 0) newPixels = 0;

                image(i, j, k) = newPixels;
            }
        }
    }
}
else if(filter==3)
{
        for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int newPixels = image(i, j, k) * 1.5;

                if (newPixels > 255) 
                {
                    newPixels = 255;
                }
                if (newPixels < 0) 
                {
                    newPixels = 0;
                }

                image(i, j, k) = newPixels;
            }
        }
    }
}
 else
 {
    return 0;
 }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);

    return 0;
}
