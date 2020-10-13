#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>
#include "Color.h"

class Image {
public:
    // Constructor that creates a blank image
    Image(int width, int height, int components);
    // Constructor that load in an image
    Image(const std::string& fileName);

    /******** Big Three (for dynamic memory) *********/
    // Destructor
    virtual ~Image();
    // Copy constructor
    Image(const Image& image);
    // Assignment operator
    void operator=(const Image& image);

    // Gets the pixel color
    Color GetPixel(int x, int y) const;
    // Sets the pixel color
    void SetPixel(int x, int y, const Color& color);

    // Saves an image
    void SaveAs(const std::string& fileName);

    // Gets the width
    int GetWidth() const { return width_; }
    // Gets the height
    int GetHeight() const { return height_; }
    // Gets the number of components
    int GetComponents() const { return components_; }

private:
    // The width of an image
    int width_;
    // The height of an image
    int height_;
    // The number of components
    int components_;

    // dynamic memory (width and height are not known at compile time!)
    unsigned char* pixels_; // bytes (0-255 - 2^8) r (1 byte), g (1 byte), b (1 byte), a (1 byte)
};

#endif