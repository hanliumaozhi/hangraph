//
// Created by han on 16-1-18.
//

#include "camera.h"

namespace hg{ namespace graphics {

        float camera::m_rY = 0;

        float camera::m_rX = 0;

        float camera::m_dist = -3;

        hg::maths::mat4 camera::m_P = hg::maths::mat4(1);

        hg::maths::mat4 camera::m_MV = hg::maths::mat4(1);

        hg::maths::mat4 camera::T = hg::maths::mat4(1);
        hg::maths::mat4 camera::Rx = hg::maths::mat4(1);

        double camera::m_old_x = 0.0;
        double camera::m_old_y = 0.0;
        bool camera::m_state = false;

        void camera::cal_mvp(hg::maths::mat4 &MVP) {
            T = hg::maths::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, m_dist));
            Rx = hg::maths::rotate(T, m_rX, glm::vec3(1.0f, 0.0f, 0.0f));
            m_MV = hg::maths::rotate(Rx, m_rY, glm::vec3(0.0f, 1.0f, 0.0f));
            MVP = m_P*m_MV;
        }

        void camera::windows_resize(int w, int h) {
            glViewport(0, 0, (GLsizei)w, (GLsizei)h);

            m_P = glm::perspective(45.0f, (GLfloat)w / h, 1.f, 1000.f);
        }

        camera::~camera() { }

        void camera::framebuffer_size_callback(GLFWwindow *window, int width, int height){
            glViewport(0, 0, width, height);

            m_P = glm::perspective(45.0f, (GLfloat)width / height, 1.f, 1000.f);
        }

        void camera::mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
            if ((button == GLFW_MOUSE_BUTTON_LEFT || button == GLFW_MOUSE_BUTTON_RIGHT) && action == GLFW_PRESS){
                glfwGetCursorPos(window, &m_old_x, &m_old_y);
            }
            if (button == GLFW_MOUSE_BUTTON_MIDDLE){
                m_state = true;
            }else{
                m_state = false;
            }
        }

        void camera::cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
            if(m_state){
                m_dist *= (1+ (ypos - m_old_y)/ 60.0);
            }else{
                m_rY += (xpos - m_old_x) / 5.0;
                m_rX += (ypos - m_old_y) / 5.0;
            }
            m_old_x = xpos;
            m_old_y = ypos;

        }

    }
}
