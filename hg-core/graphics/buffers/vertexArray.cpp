//
// Created by han on 16-1-10.
//

#include "vertexArray.h"

namespace hg{ namespace graphics {

            vertexArray::vertexArray(){
                glGenVertexArrays(1, &m_id);
            };

            vertexArray::~vertexArray(){
                glDeleteVertexArrays(1, &m_id);
            };

            void vertexArray::bind(){
                glBindVertexArray(m_id);
            };

            void vertexArray::unbind(){
                glBindVertexArray(0);
            };
    }
}
