//
// Created by han on 16-1-18.
//

#include "camera.h"

namespace hg{ namespace graphics {
        camera::camera():m_rX(0), m_rY(0), m_dist(-10) {
            m_P = hg::maths::mat4(1);
            m_MV = hg::maths::mat4(1);
        }

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
    }
}
