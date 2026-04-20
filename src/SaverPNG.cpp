#include "SaverPNG.h"
#include "png_utils.h"
#include <stdexcept>

void SaverPNG::save(const Image& image, const std::string &filename) {
    int width = image.getWidth();
    int height = image.getHeight();
    std::vector<Pixel> pixels = image.getPixelVector();
    if(!savePNG(filename, width, height, pixels)){
        throw std::runtime_error("can't create a file");
    }
}