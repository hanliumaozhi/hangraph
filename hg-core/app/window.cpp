//
// Created by han on 16-1-5.
//

#include <iostream>
#include "window.h"

namespace hg{
    namespace app{
        window::window(const char *title, int weight, int height) {
            m_Title = title;
            m_Width = weight;
            m_Height = height;
            if(!Init()){
                std::cout<<"init error"<<std::endl;
            };
        }

        window::~window() {
            glfwTerminate();
        }

        bool window::Init() {
            if(!glfwInit()){
                return false;
            }
            m_Windows = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
            if(!m_Windows){
                glfwTerminate();
                return false;
            }

            glfwMakeContextCurrent(m_Windows);
            glfwSwapInterval(0);
            return true;

        }

        bool window::isClosed() const {
            return glfwWindowShouldClose(m_Windows) == 1;
        }

        void window::Update(){
            if(!m_Is_close){
                m_Is_close = isClosed();
                glfwSwapBuffers(m_Windows);

                glfwPollEvents();
            }

        }

        void window::Clear() const {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
    }
}
