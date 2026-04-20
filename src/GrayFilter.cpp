#include "GrayFilter.h"

Image GrayFilter::apply(const Image& img) {
    std::vector<Pixel> pixels = img.getPixelVector();
    for(auto& p : pixels) {
        unsigned char gray = static_cast<unsigned char>(0.299 * p.r + 0.587 * p.g + 0.114 * p.b);
        p.r = p.g = p.b = gray;
    }
    Image out(pixels, img.getWidth(), img.getHeight(), img.getMaxVal());
    return out;
}