#include "ImageProcessor.h"

ImageProcessor::ImageProcessor(ImageLoader imgLoader, std::vector<std::unique_ptr<Filter>> filters, std::unique_ptr<Saver> saver):
loader_{imgLoader}, filters_{std::move(filters)}, saver_{std::move(saver)}
{ }

void ImageProcessor::execute(const std::string &filename_in, const std::string &filename_out)
{
    Image img = loader_.load(filename_in);
    Image img_out;
    for(size_t i = 0; i<filters_.size(); i++){
      img_out = filters_[i]->apply(img);
      img = img_out;
    }
    saver_->save(img_out, filename_out);
}