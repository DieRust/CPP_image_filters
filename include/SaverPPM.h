
#pragma once
#include "Saver.h"

class SaverPPM: public Saver {
public:
    void save(const Image& image, const std::string &filename) override;
};
