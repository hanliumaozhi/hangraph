//
// Created by han on 16-1-10.
//

#include "buffer.h"

namespace hg{ namespace graphics{
        buffer::buffer() {
            m_used_size = 0;
            glGenBuffers(1, &m_id);
            if(glGetError() != GL_NO_ERROR){
                m_is_corect = false;
            }else{
                m_is_corect = true;
            }
            this->init();
        }
        buffer::~buffer() {
            glDeleteBuffers(1, &m_id);
        }

        void buffer::bind() {
            glBindBuffer(GL_ARRAY_BUFFER, m_id);
        }

        void buffer::unbind() {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        bool buffer::init() {
            if(m_is_corect) {
                glBindBuffer(GL_ARRAY_BUFFER, m_id);
                glBufferData(GL_ARRAY_BUFFER, sizeof(m_position) + sizeof(m_color), NULL, GL_DYNAMIC_DRAW);
                glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(m_position), m_position);
                glBufferSubData(GL_ARRAY_BUFFER, sizeof(m_position), sizeof(m_color), m_color);
                if(glGetError() == GL_NO_ERROR){
                    return true;
                }
            }
            return false;
        }

        bool buffer::flush() {
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(hg::maths::vec3)*m_used_size, m_position);
            glBufferSubData(GL_ARRAY_BUFFER, sizeof(m_position), sizeof(hg::maths::vec3)*m_used_size, m_color);
            if(glGetError() == GL_NO_ERROR){
                return true;
            }else{
                return false;
            }
        }

        void buffer::set_item(hg::maths::vec3 & position, hg::maths::vec3 & color, int index){
            m_position[index] = position;
            m_color[index] = color;
        }

        void buffer::set_used_size(int size){
            m_used_size = size;
        }

        GLsizei buffer::get_used_size() {
            return m_used_size;
        }
    }
}
