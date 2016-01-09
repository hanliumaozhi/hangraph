//
// Created by han on 16-1-10.
//

#include "buffer.h"

namespace hg{ namespace buffer{
        buffer::buffer() {
            m_used_size = 0;
            glGenBuffers(1, &m_id);
            if(glGetError() != GL_NO_ERROR){
                m_is_corect = false;
            }else{
                m_is_corect = true;
            }
        }
        buffer::~buffer() {
            glDeleteBuffers(1, &m_id);
        }

        void buffer::bind() {
            glBindVertexArray(m_id);
        }

        void buffer::unbind() {
            glBindVertexArray(0);
        }

        bool buffer::init() {
            if(m_is_corect) {
                glBindBuffer(GL_ARRAY_BUFFER, m_id);
                glBufferData(GL_ARRAY_BUFFER, sizeof(m_data), NULL, GL_DYNAMIC_DRAW);
                if(glGetError() == GL_NO_ERROR){
                    return true;
                }
            }
            return false;
        }
    }
}
