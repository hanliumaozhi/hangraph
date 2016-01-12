//
// Created by han on 16-1-12.
//

#ifndef HG_RENDERER_H
#define HG_RENDERER_H


#include "buffers/vertexArray.h"


namespace hg{ namespace graphics {
        class renderer {
        private:
            vertexArray m_vao;


        public:
            renderer();
            ~renderer();
            void draw();
        };
    }
}


#endif //HG_RENDERER_H
