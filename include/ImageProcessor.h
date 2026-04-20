#pragma once
#include <memory>
#include "Image.h"
#include "ImageLoader.h"
#include "Filter.h"
#include "Saver.h"

class ImageProcessor
{
  ImageLoader loader_;
  std::vector<std::unique_ptr<Filter>> filters_;
  std::unique_ptr<Saver> saver_;
public:
   ImageProcessor(ImageLoader imgLoader, std::vector<std::unique_ptr<Filter>> filters,std::unique_ptr<Saver> saver);

   void execute(const std::string &filename_in, const std::string &filename_out);
};