
#pragma once
#include "Filter.h"

class SepiaFilter : public Filter {
public:
    Image apply(const Image& image) override;
};
