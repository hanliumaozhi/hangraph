//
// Created by han on 16-1-18.
//

#ifndef HG_CAMERA_H
#define HG_CAMERA_H

#include <GL/glew.h>

#include "../../maths/maths.h"


namespace hg{ namespace graphics {

        class camera {
        private:
            hg::maths::mat4 m_P;
            hg::maths::mat4 m_MV;
            float m_rX;
            float m_rY;
            float m_dist;
        public:
            camera();
            ~camera();
            void windows_resize(int w, int h);
            void cal_mvp(hg::maths::mat4 &MVP);
        };
    }
}


#endif //HG_CAMERA_H
