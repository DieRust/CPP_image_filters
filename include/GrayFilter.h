#pragma once
#include "Filter.h"

class GrayFilter : public Filter {
public:
    Image apply(const Image& img) override;
};