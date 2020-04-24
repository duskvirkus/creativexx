#ifndef CREATIVEXX_APPLICATION_H
#define CREATIVEXX_APPLICATION_H

#include <iostream>

namespace Creative {

    class Application {

    public:

        Application() = default;
        Application(const Application&) = delete;
        Application(const Application&&) = delete;
        Application& operator=(const Application&) = delete;
        Application& operator=(const Application&&) = delete;
        virtual ~Application() = default;

        virtual void setup();
        virtual void update();
        virtual void draw();

    };

}

#endif //CREATIVEXX_APPLICATION_H
