//
// Created by han on 16-1-10.
//

#ifndef HG_VERTEX_H
#define HG_VERTEX_H

#include "../../maths/maths.h"


namespace hg{ namespace buffer{
        struct vertexData{
            hg::maths::vec3 position;
            hg::maths::vec3 color;
        };
    }
}

#endif //HG_VERTEX_H
