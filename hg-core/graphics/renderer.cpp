//
// Created by han on 16-1-12.
//

#include "renderer.h"


namespace hg{ namespace graphics{
        renderer::renderer(const std::string &type, std::shared_ptr<buffer> buffer){
            m_buffer = buffer;
            m_shader = hg::shader::ShaderFactory::shader_maker(type);
            m_vao = std::make_shared<vertexArray>();

            this->init();
        }

        bool renderer::init() {
            m_vao->bind();
            m_shader->Use();
            glVertexAttribPointer(m_shader["Vertex"], 3, GL_FLOAT, GL_FALSE, 0, 0);
            glVertexAttribPointer(m_shader["Color"], 3, GL_FLOAT, GL_TRUE, 0, (GLubyte *)(sizeof(hg::maths::vec3)*VBOSIZE));

            glEnableVertexAttribArray(m_shader["Vertex"]);
            glEnableVertexAttribArray(m_shader["Color"]);
            m_shader->UnUse();
            m_vao->unbind();

            if(glGetError() == GL_NO_ERROR){
                return true;
            }else{
                return false;
            }

        }

        void renderer::draw() {

        }

        void renderer::~renderer() {
            m_shader->DeleteShaderProgram();
        }


    }
}