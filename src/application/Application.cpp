#include "Application.h"

namespace creative {

    Application::Application() :
            m_looping(true) {}

    void Application::setup() {
        std::cout << "Setup" << '\n';
    }

    void Application::update() {
        std::cout << "Update" << '\n';
    }

    void Application::draw() {
        std::cout << "Draw" << '\n';
    }

    void Application::loop(bool looping) {
        m_looping = looping;
    }

    bool Application::looping() const {
        return m_looping;
    }

}