#include "App.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <map>
#include <bits/stdc++.h>

using FilterFactory = std::function<std::unique_ptr<Filter>()>;

static const std::map<std::string, FilterFactory> filter_map = {
    {"sepia",           []() { return std::make_unique<SepiaFilter>(); }},
    {"gray",            []() { return std::make_unique<GrayFilter>(); }},
    {"rotate",          []() { return std::make_unique<RotateFilter>(FilterRotation::R90); }},
    {"rotate_r_90",     []() { return std::make_unique<RotateFilter>(FilterRotation::R90); }},
    {"rotate_l_270",    []() { return std::make_unique<RotateFilter>(FilterRotation::R90); }},
    {"rotate_r_180",    []() { return std::make_unique<RotateFilter>(FilterRotation::RL180); }},
    {"rotate_l_180",    []() { return std::make_unique<RotateFilter>(FilterRotation::RL180); }},
    {"rotate_r_270",    []() { return std::make_unique<RotateFilter>(FilterRotation::L90); }},
    {"rotate_l_90",     []() { return std::make_unique<RotateFilter>(FilterRotation::L90); }},
    {"flip_horizontal", []() { return std::make_unique<FlipFilter>(FlipDirection::HORIZONTAL); }},
    {"flip_vertical",   []() { return std::make_unique<FlipFilter>(FlipDirection::VERTICAL); }},
};

App::App(int argc, char** argv){
  if(argc < 2){
    std::cout<<"You put too few arguments. If you don't know how to use this app give: -help argument\n";
    exit(EXIT_FAILURE);
  }

  if(argc == 2){
    std::string argument = argv[1];
    if(argument == "-help"){
      help_argument();
    } else {
      std::cout<<"You put too few arguments. If you don't know how to use this app give: -help argument\n";
      exit(EXIT_FAILURE);
    }
  }

  if(argc <= 5){
    argument_loader(argc, argv);
  }

  if(argc > 5){
    std::cout<<"You put too much arguments. If you don't know how to use this app give: -help argument\n";
    exit(EXIT_FAILURE);
  }

}

void App::exec(){
  ImageProcessor processor(reader, std::move(filters), std::move(writer));
  processor.execute(filename_in, filename_out);
}

void App::help_argument(){
  std::cout<<"Instruction to use this app.\n";
  std::cout<<"* Correct application launch:\n";
  std::cout<<"\r ./image_filters [path_to_input_image] [filter_type1,filter_type2,...] [output_format] [*OPTIONAL*output_file_name]\n";
  std::cout<<"* Supported filters types:\n";
  std::cout<<"\r- sepia\n"
          <<"\r- rotate_R/L_90/180/270\n"
          <<"\r- flip_horizontal\n"
          <<"\r- flip_vertical\n"
          <<"\r- gray\n";
  std::cout<<"* Supported output file format:\n";
  std::cout<<"\r- ppm\n"
          <<"\r- png\n";
  std::cout<<"If you dont specify an output file name the result will be write in filter_output\n";
  std::cout<<"Example use case:\n./image_filters easter.ppm rotate_R_270 png rotated.png\n";
  exit(EXIT_SUCCESS);
}

void App::argument_loader(int argc, char** argv){
  //getting input filename
  filename_in = argv[1];

  //getting which filter use
  std::string filter_types_str = argv[2];
  std::transform(filter_types_str.begin(), filter_types_str.end(), filter_types_str.begin(), ::tolower);

  std::regex del{","};

  std::sregex_token_iterator regex_it(filter_types_str.begin(), filter_types_str.end(), del, -1);
  std::sregex_token_iterator end;

  while(regex_it != end){
    auto map_it = filter_map.find(*regex_it);

    if(map_it != filter_map.end()){
      filters.push_back(map_it->second());
    } else {
      std::cout<<"Wrong type of filter\n";
      exit(EXIT_FAILURE);
    }

    ++regex_it;
  }

  //getting which output file format use to save an image
  std::string save_type_str = argv[3];
  std::transform(save_type_str.begin(), save_type_str.end(), save_type_str.begin(), ::tolower);

  std::string prefix;
  if(save_type_str == "ppm"){
    writer = std::make_unique<SaverPPM>();
    prefix = ".ppm";
  } else if(save_type_str =="png"){
    writer = std::make_unique<SaverPNG>();
    prefix = ".png";
  } else{
    std::cout<<"Wrong type of file save\n";
    exit(EXIT_FAILURE);
  }

  filename_out = (argc == 5)? argv[4] : "filter_output"+prefix;
}