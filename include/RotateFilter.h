
#pragma once
#include "Filter.h"

enum class FilterRotation{
    R90,
    L90,
    RL180
};

class RotateFilter : public Filter {
    FilterRotation rotation;
public:
    RotateFilter(FilterRotation _rotation);
    Image apply(const Image& image) override;
};
