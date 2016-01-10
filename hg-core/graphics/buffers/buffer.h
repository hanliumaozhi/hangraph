//
// Created by han on 16-1-10.
//

#ifndef HG_BUFFER_H
#define HG_BUFFER_H

#include <GL/glew.h>
#include "../../maths/maths.h"
#include "../../Common.h"

namespace hg{ namespace graphics{

        class buffer
        {
        private:
            //vbo id
            GLuint m_id;
            hg::maths::vec3 m_position[VBOSIZE];
            hg::maths::vec3 m_color[VBOSIZE];
            int m_used_size;
            bool m_is_corect;

        public:
            buffer();
            ~buffer();
            void bind();
            void unbind();
            bool init();
            bool flush();
            void set_item(hg::maths::vec3 & position, hg::maths::vec3 & color, int index);
            void set_used_size(int size);
        };

    }
}


#endif //HG_BUFFER_H
