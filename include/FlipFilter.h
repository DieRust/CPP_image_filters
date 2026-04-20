#pragma once
#include "Filter.h"

enum FlipDirection { HORIZONTAL, VERTICAL };

class FlipFilter : public Filter {
private:
    FlipDirection rotation_;
public:
    FlipFilter(FlipDirection rotation);
    Image apply(const Image& image) override;
};
