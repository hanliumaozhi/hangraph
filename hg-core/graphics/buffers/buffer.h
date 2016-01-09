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
            GLuint id;
            vertexData data[VBOSIZE];

        public:
            buffer();
            ~buffer();
            void bind();
            void unbind();

        };

    }
}


#endif //HG_BUFFER_H
