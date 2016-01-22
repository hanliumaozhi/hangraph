//
// Created by han on 16-1-22.
//

#ifndef HG_SCENE_H
#define HG_SCENE_H

#include <memory>

#include "renderer.h"
#include "buffers/buffer.h"
#include "buffers/vertexArray.h"

namespace hg{ namespace graphics{
        class scene {
        private:
            std::shared_ptr<vertexArray> m_vao;
            std::shared_ptr<buffer> m_vbo;


        public:

        };

    }
}


#endif //HG_SCENE_H
