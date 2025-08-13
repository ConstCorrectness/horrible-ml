#include "horribleapp.hpp"

bool App::init(int width, int height, std::string_view title) {
    window_ = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if (!window_) {
        return false;
    }

    return true;
}


void App::cleanup() {

}

void App::loop() {

}