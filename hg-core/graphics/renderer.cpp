//
// Created by han on 16-1-12.
//

#include "renderer.h"


namespace hg{ namespace graphics{
        renderer::renderer(const std::string &type, std::shared_ptr<vertexArray> vao, std::shared_ptr<buffer> buffer){
            m_buffer = buffer;
            m_shader = hg::shader::ShaderFactory::shader_maker(type);
            m_vao = vao;
            if(type == "line"){
                m_Draw_type = 1;
            }else{
                m_Draw_type = 2;
            }

            this->init();
        }

        bool renderer::init() {
            m_vao->bind();
            m_shader->Use();
            glVertexAttribPointer((*m_shader)["Vertex"], 3, GL_FLOAT, GL_FALSE, 0, 0);
            glVertexAttribPointer((*m_shader)["Color"], 3, GL_FLOAT, GL_TRUE, 0, (GLubyte *)(sizeof(hg::maths::vec3)*VBOSIZE));

            glEnableVertexAttribArray((*m_shader)["Vertex"]);
            glEnableVertexAttribArray((*m_shader)["Color"]);
            m_shader->UnUse();
            m_vao->unbind();

            if(glGetError() == GL_NO_ERROR){
                return true;
            }else{
                return false;
            }

        }

        void renderer::draw(hg::maths::mat4& MVP) {
            m_vao->bind();
            m_buffer->bind();
            m_buffer->flush();
            m_shader->Use();
            glUniformMatrix4fv((*m_shader)("MVP"), 1, GL_FALSE, glm::value_ptr(MVP));
            if(m_Draw_type==1){
                glDrawArrays(GL_LINES, 0, m_buffer->get_used_size());
            }else{
                glDrawArrays(GL_POINTS, 0, m_buffer->get_used_size());
            }
            m_shader->UnUse();
            m_buffer->unbind();
            m_vao->unbind();
        }

        renderer::~renderer() {
            m_shader->DeleteShaderProgram();
        }


    }
}