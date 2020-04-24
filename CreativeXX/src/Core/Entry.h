#ifndef CREATIVEXX_ENTRY_H
#define CREATIVEXX_ENTRY_H

extern Creative::Application* createApplication();

int main(int argc, char** argv) {
    auto app = createApplication();
    app->setup();
    while (true) {
        app->update();
        app->draw();
    }
    delete app;
    return 0;
}

#endif //CREATIVEXX_ENTRY_H
