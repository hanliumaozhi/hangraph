//
// Created by han on 16-1-10.
//

#ifndef HG_VERTEXARRAY_H
#define HG_VERTEXARRAY_H

#include <GL/glew.h>


namespace hg{ namespace graphics {
        class vertexArray {
        private:
            GLuint m_id;

        public:
            vertexArray();
            ~vertexArray();
            void bind();
            void unbind();
        };
    }
}


#endif //HG_VERTEXARRAY_H
