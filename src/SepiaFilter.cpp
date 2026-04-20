
#include "SepiaFilter.h"
#include <algorithm>

Image SepiaFilter::apply(const Image& image) {
    std::vector<Pixel> pixelsVector = image.getPixelVector();
    for(auto& p : pixelsVector) {
        int r = std::min(255, int(0.393*p.r + 0.769*p.g + 0.189*p.b));
        int g = std::min(255, int(0.349*p.r + 0.686*p.g + 0.168*p.b));
        int b = std::min(255, int(0.272*p.r + 0.534*p.g + 0.131*p.b));
        p.r = r; p.g = g; p.b = b;
    }

    Image img = Image(pixelsVector,
                        image.getWidth(),
                        image.getHeight(),
                        image.getMaxVal());

    return img;
}
