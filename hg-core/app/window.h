//
// Created by han on 16-1-5.
//

#ifndef HG_WINDOW_H
#define HG_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

namespace hg {
    namespace app {

        class window {
            private:

                GLFWwindow* m_Windows;
                //const char* m_Title;
                std::string m_Title;
                int m_Width;
                int m_Height;

                bool m_Is_close;

            public:
                window(std::string title, int weight, int height);
                ~window();
                void Clear() const;
                void Update();
                bool isClosed() const;

                inline int GetWidth() const { return m_Width; };
                inline int GetHeight() const { return m_Height; };
                GLFWwindow* GetWindow();


            private:

                bool Init();
        };
    }
}


#endif //HG_WINDOW_H
