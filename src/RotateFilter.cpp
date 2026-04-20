
#include "RotateFilter.h"
#include <algorithm>
#include <numeric>
#include <execution>

RotateFilter::RotateFilter(FilterRotation _rotation) : rotation(_rotation) { };

Image RotateFilter::apply(const Image& image) {
    std::vector<Pixel> pixels_original = image.getPixelVector();
    int height = image.getHeight();
    int width = image.getWidth();

    switch(rotation){
        case FilterRotation::R90:
        {
            std::vector<Pixel> rotated_pixels = { };
            rotated_pixels.resize(height*width);
            std::vector<int> loop_iteration(width);
            std::iota(loop_iteration.begin(), loop_iteration.end(), 0);
            std::for_each(std::execution::par, loop_iteration.begin(), loop_iteration.end(),
                [&](int i){
                    unsigned index_par = width * (height -1) + i;
                    for(int j = 0; j < height; j++){
                        unsigned index = index_par - j*width;
                        rotated_pixels[i * height + j] = pixels_original[index];
                    }
                }
            );
            Image img(rotated_pixels, height, width, image.getMaxVal());
            return img;

        }
        case FilterRotation::L90:
        {
            std::vector<Pixel> rotated_pixels = { };
            rotated_pixels.resize(height*width);
            std::vector<int> loop_iteration(width);
            std::iota(loop_iteration.begin(), loop_iteration.end(), 0);
            std::for_each(std::execution::par, loop_iteration.begin(), loop_iteration.end(),
                [&](int i){
                    unsigned index_par = width - 1 - i;
                    for(int j = 0; j < height; j++){
                        unsigned index = index_par + j*width;
                        rotated_pixels[i * height + j] = pixels_original[index];
                    }
                }
            );
            Image img(rotated_pixels, height, width, image.getMaxVal());
            return img;

        }
        case FilterRotation::RL180:
        {
            std::reverse(pixels_original.begin(), pixels_original.end());
            Image img(pixels_original, width, height, image.getMaxVal());
            return img;
            break;
        }
    }
    Image img(pixels_original, width, height, image.getMaxVal());
    return img;
}
