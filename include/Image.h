
#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include "Pixel.h"
#include "Filter.h"
#include "Saver.h"


class Image {
private:
    size_t width_, height_, max_val_;
    std::vector<Pixel> pixels_;

public:
    Image() = default;
    Image(std::vector<Pixel>& pixelsVector, size_t width, size_t height, size_t max_val);

    //Define getters
    const std::vector<Pixel>& getPixelVector();
    const std::vector<Pixel>& getPixelVector() const;
    int getWidth();
    int getWidth() const;

    int getHeight();
    int getHeight() const;

    int getMaxVal();
    int getMaxVal() const;

    // Define setters
    bool setImage(std::vector<Pixel>& pixelsVector, size_t width, size_t height, size_t max_val=0);

};
