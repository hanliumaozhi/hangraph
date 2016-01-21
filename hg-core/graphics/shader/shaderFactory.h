//
// Created by han on 16-1-13.
//

#ifndef HG_SHADERFACTORY_H
#define HG_SHADERFACTORY_H

#include <memory>

#include "GLSLShader.h"
#include "shader_str.h"


namespace hg { namespace shader { namespace ShaderFactory {

            shared_ptr<GLSLShader> shader_maker(const std::string &type);
        }
    }
}


#endif //HG_SHADERFACTORY_H
