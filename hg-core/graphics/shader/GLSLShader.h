//
// Created by han on 16-1-6.
//

#ifndef HG_GLSLSHADER_H
#define HG_GLSLSHADER_H

#include <GL/glew.h>

#include <iostream>
#include <map>
#include <string>
#include <fstream>

namespace hg { namespace shader {
        using namespace std;
        class GLSLShader
        {
        public:
            GLSLShader(void);
            ~GLSLShader(void);
            void LoadFromString(GLenum whichShader, const string& source);
            void LoadFromFile(GLenum whichShader, const string& filename);
            void CreateAndLinkProgram();
            void Use();
            void UnUse();
            void AddAttribute(const string& attribute);
            void AddUniform(const string& uniform);

            GLuint operator[](const string& attribute);
            GLuint operator()(const string& uniform);
            void DeleteShaderProgram();

        private:
            enum ShaderType { VERTEX_SHADER, FRAGMENT_SHADER, GEOMETRY_SHADER };
            GLuint	_program;
            int _totalShaders;
            GLuint _count_attr;
            GLuint _shaders[3];//0->vertexshader, 1->fragmentshader, 2->geometryshader
            map<string, GLuint> _attributeList;
            map<string, GLuint> _uniformLocationList;
        };
    }
}

#endif //HG_GLSLSHADER_H
