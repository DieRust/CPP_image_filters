#include "png_utils.h"

#include <png.h>
#include <cstdio>
#include <vector>
#include <iostream>

#include "Pixel.h"


static_assert(sizeof(Pixel) == 3, "Pixel musi miec 3 bajty!");

bool savePNG(const std::string& filename, int width, int height, const std::vector<Pixel>& pixels )
{
    FILE* fp = fopen(filename.c_str(), "wb");
    if (!fp) {
        std::cerr << "Nie mozna otworzyc pliku\n";
        return false;
    }

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png) return false;

    png_infop info = png_create_info_struct(png);
    if (!info) return false;

    if (setjmp(png_jmpbuf(png))) {
        std::cerr << "Blad podczas zapisu PNG\n";
        return false;
    }

    png_init_io(png, fp);

    // ustawienia obrazu
    png_set_IHDR(
        png,
        info,
        width,
        height,
        8, // bit depth
        PNG_COLOR_TYPE_RGB,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );

    png_write_info(png, info);

    // przygotowanie danych (wiersze)
    std::vector<png_bytep> rows(height);
    for (int y = 0; y < height; y++) {
        rows[y] = (png_bytep)&pixels[y * width];
    }

    png_write_image(png, rows.data());
    png_write_end(png, nullptr);

    fclose(fp);
    png_destroy_write_struct(&png, &info);

    return true;
}
