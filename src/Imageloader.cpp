#include "ImageLoader.h"
#include <fstream>
#include <stdexcept>

Image ImageLoader::load(const std::string &filename){
  std::ifstream file(filename, std::ios::binary);
    if(!file){
        throw std::runtime_error("can't read a file");
    }

    std::string format;
    std::getline(file, format);
    //file >> format;
    if(format != "P6"){
        throw std::runtime_error("wrong type of file");
    }

    std::string null;
//    file >> null;
    std::getline(file, null);

    size_t width = 0, height = 0, max_val = 0;

    file >> width >> height >> max_val;
    file.get();

    std::vector<Pixel> pixelVector = { };

    pixelVector.resize(width*height);
    file.read(reinterpret_cast<char*>(pixelVector.data()), width*height*3);

    return Image(pixelVector, width, height, max_val);
}