//
// Created by han on 16-1-18.
//

#ifndef HG_CAMERA_H
#define HG_CAMERA_H

#include <GL/glew.h>

#include "../../maths/maths.h"
#include <GLFW/glfw3.h>


namespace hg{ namespace graphics {

        class camera {
        private:
            static hg::maths::mat4 m_P;
            static hg::maths::mat4 m_MV;
            static hg::maths::mat4 T;
            static hg::maths::mat4 Rx;
            static float m_rX;
            static float m_rY;
            static float m_dist;
            static double m_old_x;
            static double m_old_y;
            static bool m_state;

        public:
            explicit camera(GLFWwindow* window){
                glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
                glfwSetMouseButtonCallback(window, mouse_button_callback);
                glfwSetCursorPosCallback(window, cursor_position_callback);
            }

            ~camera();
            void windows_resize(int w, int h);
            void cal_mvp(hg::maths::mat4 &MVP);
            static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
            static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
            static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
        };
    }
}


#endif //HG_CAMERA_H
