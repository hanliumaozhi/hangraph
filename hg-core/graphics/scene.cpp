//
// Created by han on 16-1-22.
//

#include "scene.h"


namespace hg{ namespace graphics{
        scene::scene(const char *title, int weight, int height)
        {
            m_window_title = title;
            m_window = std::make_shared<hg::app::window>(m_window_title, weight, height);

            glewExperimental = GL_TRUE;
            glewInit();

            m_MVP = hg::maths::mat4(1);

            m_vao = std::make_shared<hg::graphics::vertexArray>();
            m_vao->bind();
            std::shared_ptr<hg::graphics::buffer> vbo = std::make_shared<hg::graphics::buffer>();
            m_vao->unbind();
            //std::shared_ptr<hg::graphics::renderer> render = std::make_shared<hg::graphics::renderer>("cube", vao, vbo);

            m_camera = std::make_shared<hg::graphics::camera>(m_window->GetWindow());

            init_renderer();
        }

        void scene::init_renderer()
        {
            m_name2type["cube"] = 1;
            m_renderer_dict[1] = std::make_shared<hg::graphics::renderer>("cube", m_vao, m_vbo);

            m_name2type["line"] = 2;
            m_renderer_dict[2] = std::make_shared<hg::graphics::renderer>("line", m_vao, m_vbo);

            m_name2type["sphere"] = 3;
            m_renderer_dict[3] = std::make_shared<hg::graphics::renderer>("sphere", m_vao, m_vbo);
        }
    }
}