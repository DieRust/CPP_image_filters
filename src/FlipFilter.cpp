#include "FlipFilter.h"
#include <algorithm>
#include <numeric>
#include <execution>

FlipFilter::FlipFilter(FlipDirection rotation): rotation_{rotation} { };

Image FlipFilter::apply(const Image& image){
  std::vector<Pixel> pixels_original = image.getPixelVector();
  std::vector<Pixel> rotated_pixels = { };
  const int height = image.getHeight();
  int width = image.getWidth();
  rotated_pixels.resize(height*width);
  std::vector<int> loop_iteration(height);
  std::iota(loop_iteration.begin(), loop_iteration.end(), 0);
  switch (rotation_)
  {
  case VERTICAL:
    std::for_each(std::execution::par, loop_iteration.begin(), loop_iteration.end(),
        [&](int i){
            unsigned index_par = width * (height - i - 1);
            for(int j = 0; j < width; j++){
                unsigned index = index_par + j;
                rotated_pixels[i * width + j] = pixels_original[index];
            }
        }
    );
    break;
   case HORIZONTAL:
    std::for_each(std::execution::par, loop_iteration.begin(), loop_iteration.end(),
        [&](int i){
            for(int j = 0; j < width; j++){
                rotated_pixels[i * width + j] = pixels_original[i * width + (width - 1 - j)];
            }
        }
    );
    break;
  }


  Image img(rotated_pixels, width, height, image.getMaxVal());
  return img;
}