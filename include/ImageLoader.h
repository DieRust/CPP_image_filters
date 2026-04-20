#pragma once
#include "Image.h"

class ImageLoader{
  public:
   Image load(const std::string &filename);
};