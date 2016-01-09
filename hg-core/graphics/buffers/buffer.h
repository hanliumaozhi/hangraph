//
// Created by han on 16-1-10.
//

#ifndef HG_BUFFER_H
#define HG_BUFFER_H

#include <GL/glew.h>
#include "vertex.h"
#include "../../Common.h"

namespace hg{ namespace buffer{

        class buffer
        {
        private:
            //vbo id
            GLuint m_id;
            vertexData m_data[VBOSIZE];
            int m_used_size;
            bool m_is_corect;

        public:
            buffer();
            ~buffer();
            void bind();
            void unbind();
            bool init();
        };

    }
}


#endif //HG_BUFFER_H
