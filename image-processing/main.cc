#include <iostream>

using namespace std;

#include "image.h"

int main() {
    Image img(512, 512, 4);
    cout << img.GetWidth() << " " << img.GetHeight() << endl;
    Image img2(256, 256, 4);
    img = img2;
    cout << img.GetWidth() << " " << img.GetHeight() << endl;

    for (int x = 0; x < img.GetWidth(); x++) {
        for (int y = 0; y < img.GetHeight(); y++) {
            img.SetPixel(x, y, Color(1.0, 0.0, 0.0, 1.0));
        }
    }

    Color color = img.GetPixel(100, 100);
    cout << color.Red() << " " << color.Green() << " " << color.Blue() << " " << color.Alpha() << endl;

    img.SaveAs("images/red.png");

    Image dog("images/dog.png");
    cout << dog.GetWidth() << " " << dog.GetHeight() << " " << dog.GetComponents() << endl;
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            dog.SetPixel(x, y, Color(1.0, 0.0, 0.0, 1.0));
        }
    }
    dog.SaveAs("images/dog_modified.png");

    Image copiedImage(dog);
    copiedImage.SaveAs("images/copied.png");

    return 0;
}