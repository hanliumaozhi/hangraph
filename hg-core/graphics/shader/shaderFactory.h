//
// Created by han on 16-1-13.
//

#ifndef HG_SHADERFACTORY_H
#define HG_SHADERFACTORY_H

#include <memory>

#include "GLSLShader.h"
#include "shader_str.h"


namespace hg { namespace shader { namespace ShaderFactory {

            shared_ptr<GLSLShader> shader_maker(const std::string &type){
                if(type == "cube"){
                    shared_ptr<GLSLShader> cube_shader;
                    cube_shader->LoadFromString(GL_VERTEX_SHADER, cube_vert.c_str());
                    cube_shader->LoadFromString(GL_GEOMETRY_SHADER, cube_geoc.c_str());
                    cube_shader->LoadFromString(GL_FRAGMENT_SHADER, cube_frag.c_str());
                    cube_shader->CreateAndLinkProgram();

                    cube_shader->Use();
                    cube_shader->AddAttribute("Vertex");
                    cube_shader->AddAttribute("Color");
                    cube_shader->AddUniform("MVP");
                    cube_shader->UnUse();

                    return cube_shader;
                }else if(type == "line"){
                    shared_ptr<GLSLShader> line_shader;
                    line_shader->LoadFromString(GL_VERTEX_SHADER, line_vert.c_str());
                    line_shader->LoadFromString(GL_FRAGMENT_SHADER, line_frag.c_str());

                    line_shader->CreateAndLinkProgram();

                    line_shader->Use();
                    line_shader->AddAttribute("Vertex");
                    line_shader->AddAttribute("Color");
                    line_shader->AddUniform("MVP");
                    line_shader->UnUse();

                    return line_shader;
                }else if(type == "sphere"){
                    shared_ptr<GLSLShader> shader;
                    shader->LoadFromString(GL_VERTEX_SHADER, sphere_vert.c_str());
                    shader->LoadFromString(GL_GEOMETRY_SHADER, sphere_geoc.c_str());
                    shader->LoadFromString(GL_FRAGMENT_SHADER, sphere_frag.c_str());
                    shader->CreateAndLinkProgram();

                    shader->Use();
                    shader->AddAttribute("Vertex");
                    shader->AddAttribute("Color");
                    shader->AddUniform("MVP");
                    shader->UnUse();
                    return shader;
                }else{
                    return nullptr;
                }

            }
        }
    }
}


#endif //HG_SHADERFACTORY_H
