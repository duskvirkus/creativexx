#ifndef CREATIVEXX_APPLICATION_H
#define CREATIVEXX_APPLICATION_H

#include <iostream>

namespace creative {

    class Application {
    public:

        Application();

        Application(const Application &) = delete;

        Application(const Application &&) = delete;

        Application &operator=(const Application &) = delete;

        Application &operator=(const Application &&) = delete;

        virtual ~Application() = default;

        virtual void setup();

        virtual void update();

        virtual void draw();

        void loop(bool looping);

        bool looping() const;

    protected:

        bool m_looping;

    };

}

#endif //CREATIVEXX_APPLICATION_H
