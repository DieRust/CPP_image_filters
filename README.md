# CPP_image_filters

This project is a C++ application designed for applying various image processing filters to images. It provides a robust and modular framework for loading, manipulating, and saving images in different formats, offering functionalities like grayscale conversion, sepia toning, flipping, and rotation.


## Key Features & Benefits

This project aims to provide a flexible and extensible platform for basic image manipulation.

*   **Diverse Filters:** Apply a range of common image filters including:
    *   Grayscale conversion
    *   Sepia tone effect
    *   Horizontal and Vertical flipping
    *   Image rotation by specified degrees
*   **Multi-format Support:**
    *   Load images in PPM (Portable Pixmap) format.
    *   Save processed images in PPM and PNG (Portable Network Graphics) formats.
*   **Modular Design:** The filter system is designed with extensibility in mind, making it easy to add new image processing filters.
*   **Command-Line Interface:** Process images directly from the terminal, ideal for scripting and automation.
*   **C++ Performance:** Leverages the performance benefits of C++ for efficient image processing.

## Project Structure

The repository is organized as follows:

```
├── CMakeLists.txt
├── README.md
├── easter.ppm
├── include/
│   ├── App.h
│   ├── Filter.h
│   ├── FlipFilter.h
│   ├── GrayFilter.h
│   ├── Image.h
│   ├── ImageLoader.h
│   ├── ImageProcessor.h
│   ├── Pixel.h
│   ├── RotateFilter.h
│   ├── Saver.h
│   ├── SaverPNG.h
│   ├── SaverPPM.h
│   ├── SepiaFilter.h
│   └── png_utils.h
├── output.ppm
└── src/
    ├── App.cpp
    ├── Filter.cpp
    ├── FlipFilter.cpp
    ├── GrayFilter.cpp
    ├── Image.cpp
    ├── ImageLoader.cpp
    ├── ImageProcessor.cpp
    ├── Pixel.cpp
    ├── RotateFilter.cpp
    ├── Saver.cpp
    ├── SaverPNG.cpp
    ├── SaverPPM.cpp
    ├── SepiaFilter.cpp
    ├── main.cpp
    └── png_utils.cpp
```

## Prerequisites & Dependencies

Before you begin, ensure you have met the following requirements:

*   **C++ Compiler:** A C++20 compatible compiler (e.g., GCC, Clang, MSVC).
*   **CMake:** Version 3.10 or higher for building the project.
*   **Git:** For cloning the repository.
*   **libpng:** Development libraries for PNG image support.
    *   On Debian/Ubuntu: `sudo apt-get install libpng-dev`
    *   On Fedora/RHEL: `sudo dnf install libpng-devel`
    *   On macOS (with Homebrew): `brew install libpng`
    *   On Windows: You might need to build `libpng` from source or use a package manager like vcpkg.

## Installation & Setup Instructions

Follow these steps to get a local copy up and running on your machine.

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/DieRust/CPP_image_filters.git
    cd CPP_image_filters
    ```

2.  **Create a Build Directory:**
    ```bash
    mkdir build
    cd build
    ```

3.  **Configure CMake:**
    ```bash
    cmake ..
    ```

4.  **Build the Project:**
    ```bash
    make
    ```

    This will compile the executable `cpp_image_filters` (or similar, depending on your system and `CMakeLists.txt` configuration) in your `build` directory.

## Usage Examples

The compiled `cpp_image_filters` executable can be run from the command line. The general syntax is:

```bash
./image_filters [path_to_input_image] [filter_type1,filter_type2,...] [output_format] [*OPTIONAL*output_file_name]
```

Here are some examples of how to use the different filters:

*   **Grayscale Filter:**
    Applies a grayscale effect to `easter.ppm` and saves it as `output_gray.png`.
    ```bash
    ./image_filters easter.ppm gray png output_gray.png
    ```

*   **Sepia Filter:**
    Applies a sepia tone effect to `easter.ppm` and saves it as `output_sepia.png`.
    ```bash
    ./image_filters easter.ppm sepia png output_sepia.png
    ```

*   **Flip Filter:**
    Flips the image horizontally or vertically.
    ```bash
    # Flip horizontally
    ./image_filters easter.ppm flip_horizontal png

    # Flip vertically
    ./image_filters easter.ppm flip_vertical png
    ```

*   **Rotate Filter:**
    Rotates the image by a specified degree (e.g., 90, 180, 270).
    ```bash
    # Rotate 90 degrees clockwise
    ./image_filters easter.ppm rotate_R_90 png rotated.png
    ```

*   **Combining Operations (Conceptual, requires sequential execution or an 'apply-multiple' feature):**
    You can pass multiple filters types to apply to your image:
    ```bash
    ./image_filters easter.ppm rotate_R_90,sepia,flip_vertical png rotated.png
    ```

## Configuration Options

The primary way to configure the image processing is through the command-line arguments.

*   **Input/Output Paths:** Specified directly as the first two arguments.
*   **Filter Name:** Determines which filter to apply.
*   **Filter Parameters:** Specific options for certain filters (e.g., `horizontal`/`vertical` for flip, `degrees` for rotate).

Currently, there are no external configuration files or environment variables supported. All settings are passed dynamically at runtime via the CLI.



## Acknowledgments

*   This project makes use of **libpng** for robust PNG image handling, allowing for broad compatibility with modern image formats.
*   Thanks to the open-source community for providing valuable resources and tools like CMake that make project development and management easier.