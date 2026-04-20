
#pragma once
#include "Image.h"

class Image;

class Filter {
public:
    virtual Image apply(const Image& Image) = 0;
    virtual ~Filter() = default;
};
