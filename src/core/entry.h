#ifndef CREATIVEXX_ENTRY_H
#define CREATIVEXX_ENTRY_H

#include "init.h"

extern creative::Application *create_application();

int main(int argc, char **argv) {
    creative::initialize();

    auto app = create_application();
    app->setup();
    while (app->looping()) {
        app->update();
        app->draw();
    }
    delete app;
    return 0;
}

#endif //CREATIVEXX_ENTRY_H
