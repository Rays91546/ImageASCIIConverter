#include "image.h"
#include <algorithm>

// Needed for loading and writing image files
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

Image::Image(int width, int height, int components) : width_(width), height_(height), components_(components) {
    // Create the pixels array
    int size = width*height*components_;
    pixels_ = new unsigned char[size];
}

Image::Image(const std::string& fileName) {
    // Load an image into memory
    unsigned char *data = stbi_load(fileName.c_str(), &width_, &height_, &components_, STBI_rgb_alpha);
    // Even though the function might return 3 (if the image is an rgb instead of rgba we still format STBI_rgb_alpha)
    components_ = 4;

    // Create the pixels array and copy data from the loaded image
    int size = width_*height_*components_;
    pixels_ = new unsigned char[size];
    std::copy(data, data+width_*height_*components_, pixels_);

    // Free the memory for the loaded image
	stbi_image_free(data);
}

Image::~Image() {
    // Delete the array from memory
    delete[] pixels_;
}

Image::Image(const Image& image) : pixels_(NULL) {
    // Be sure to initialize the pixel_ array to NULL since it could point anywhere
    // in memory when the Image is created.

    // Use the assignment operator to copy the image
    *this = image;
}

void Image::operator=(const Image& image) {
    // Get width, height, and component information from the image
    width_ = image.width_;
    height_ = image.height_;
    components_ = image.components_;

    // Delete the old pixel array
    delete[] pixels_;

    // Allocated the new pixel array with the new size
    int size = width_*height_*components_;
    pixels_ = new unsigned char[size];

    // copy the bytes from one image to another
    // std::copy(src_begin, src_end, dest)
    std::copy(image.pixels_, image.pixels_ + size, this->pixels_);
}

Color Image::GetPixel(int x, int y) const {
    // Get the pixel pointer location (see slides 09-Factory.pdf)
    unsigned char* pixel = &pixels_[(width_ * y + x) * components_];

    // set the color values from the pixel (each component is a byte 0-255)
    float red = (1.0*pixel[0])/255.0;
    float green = (1.0*pixel[1])/255.0;
    float blue = (1.0*pixel[2])/255.0;
    float alpha = (1.0*pixel[3])/255.0;

    // Return the color
    return Color(red, green, blue, alpha);
}

void Image::SetPixel(int x, int y, const Color& color) {
    // Get the pixel pointer location (see slides 09-Factory.pdf)
    unsigned char* pixel = &pixels_[(width_ * y + x) * components_];

    // Set the color values as bytes
    pixel[0] = color.Red() * 255;
    pixel[1] = color.Green() * 255;
    pixel[2] = color.Blue() * 255;
    pixel[3] = color.Alpha() * 255;
}

void Image::SaveAs(const std::string& fileName) {
    // Saves a png image
    stbi_write_png(fileName.c_str(), width_, height_, components_, pixels_, width_*components_);
}