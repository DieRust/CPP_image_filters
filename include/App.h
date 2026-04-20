#pragma once
#include "ImageProcessor.h"
#include <memory>

#include "Filter.h"
#include "SepiaFilter.h"
#include "RotateFilter.h"
#include "FlipFilter.h"
#include "GrayFilter.h"

#include "Saver.h"
#include "SaverPNG.h"
#include "SaverPPM.h"

#include "ImageLoader.h"

class App
{
  private:
    std::string filename_in;
    std::string filename_out;
    std::vector<std::unique_ptr<Filter>> filters;
    std::unique_ptr<Saver> writer;
    ImageLoader reader;

    void help_argument();
    void argument_loader(int argc, char** argv);
  public:
   App(int argc, char** argv);
   void exec();
};