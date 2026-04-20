#include "SaverPPM.h"
#include <fstream>
#include <stdexcept>

void SaverPPM::save(const Image& image, const std::string &filename) {
    std::ofstream file(filename, std::ios::binary);
    if(!file){
        throw std::runtime_error("can't create a file");
    }
    std::vector<Pixel> pixels = image.getPixelVector();
    file << "P6\n" << image.getWidth()
         << " " << image.getHeight() << "\n"
         << image.getMaxVal() << "\n";
    file.write(reinterpret_cast<char*>(pixels.data()),
                                image.getWidth()*image.getHeight()*3);
}