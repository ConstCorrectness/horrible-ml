#ifndef HORRIBLE_APP_HPP_
#define HORRIBLE_APP_HPP_

#include <string_view>
#include <GLFW/glfw3.h>


class App {
public:
    bool init(int, int, std::string_view);
    void cleanup();
    void loop();
private:
    GLFWwindow *window_ { };
};


#endif              // HORRIBLE_APP_HPP_