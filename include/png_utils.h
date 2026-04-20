#ifndef IMAGEFILTERS_PNG_UTILS_H
#define IMAGEFILTERS_PNG_UTILS_H

#include<vector>
#include<string>
#include <Pixel.h>

bool savePNG(const std::string& filename, int width, int height, const std::vector<Pixel>& pixels);

#endif //IMAGEFILTERS_PNG_UTILS_H