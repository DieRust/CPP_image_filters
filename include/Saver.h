#pragma once
#include <vector>
#include "Pixel.h"
#include "Image.h"

class Image;

class Saver {
public:
    virtual void save(const Image& image, const std::string &filename) = 0;
    virtual ~Saver() = default;
};
