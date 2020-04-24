#include <CreativeXX.h>

class Sandbox : public Creative::Application {
public:
    Sandbox() {}
    ~Sandbox() {}
};

Creative::Application* createApplication() {
    return new Sandbox();
}
