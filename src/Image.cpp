#include "Image.h"



Image::Image(std::vector<Pixel>& pixelsVector, size_t width, size_t height, size_t max_val = 0):
    pixels_{pixelsVector}, width_{width}, height_{height}, max_val_{max_val}
{
    if( pixelsVector.size() < width*height){
        throw std::invalid_argument("Vector has not the same size as given in height & width");
    }
}


const std::vector<Pixel>& Image::getPixelVector(){
    return pixels_;
}

const std::vector<Pixel>& Image::getPixelVector() const{
    return pixels_;
}

int Image::getWidth(){
    return width_;
}

int Image::getWidth() const{
    return width_;
}

int Image::getHeight(){
    return height_;
}

int Image::getHeight() const{
    return height_;
}

int Image::getMaxVal(){
    return max_val_;
}

int Image::getMaxVal() const{
    return max_val_;
}

bool Image::setImage(std::vector<Pixel>& pixelsVector, size_t width, size_t height, size_t max_val ){
    if( pixelsVector.size() < width*height){
        return false;
    }

    pixels_ = pixelsVector;
    width_ = width;
    height_ = height;
    max_val_ = max_val;

    return true;
}