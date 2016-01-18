//
// Created by han on 16-1-12.
//

#ifndef HG_RENDERER_H
#define HG_RENDERER_H

#include <memory>


#include "buffers/vertexArray.h"
#include "buffers/buffer.h"

#include "shader/shaderFactory.h"

#include "../Common.h"

#include "../maths/maths.h"


namespace hg{ namespace graphics {
        class renderer {
        private:
            std::shared_ptr<vertexArray> m_vao;
            std::shared_ptr<buffer> m_buffer;
            std::shared_ptr<hg::shader::GLSLShader> m_shader;
            int m_Draw_type;
            bool init();

        public:
            renderer(const std::string &type, std::shared_ptr<vertexArray> vao, std::shared_ptr<buffer> buffer);
            ~renderer();
            void draw(hg::maths::mat4& MVP);
        };
    }
}


#endif //HG_RENDERER_H
