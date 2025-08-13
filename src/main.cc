#include <iostream>
#include <string>
#include <memory>

#include "horribleapp.hpp"

constexpr int const WIDTH {640};
constexpr int const HEIGHT {480};
std::string const TITLE = "GLFW window";

int main(int argc, char const **argv) {
    auto app = std::make_unique<App>();

    if (!app->init(WIDTH, HEIGHT, TITLE.c_str())) {

    }

    app->loop();
    app->cleanup();
}