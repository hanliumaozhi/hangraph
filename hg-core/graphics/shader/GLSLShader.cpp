//
// Created by han on 16-1-6.
//

#include "GLSLShader.h"

namespace hg { namespace shader {

        GLSLShader::GLSLShader(void)
        {
            this->_totalShaders = 0;
            this->_shaders[VERTEX_SHADER] = 0;
            this->_shaders[FRAGMENT_SHADER] = 0;
            this->_shaders[GEOMETRY_SHADER] = 0;
            this->_attributeList.clear();
            this->_uniformLocationList.clear();
            this->_count_attr = 0;
        }

        GLSLShader::~GLSLShader(void)
        {
            this->_attributeList.clear();
            this->_uniformLocationList.clear();
        }

        void GLSLShader::DeleteShaderProgram() {
            glDeleteProgram(this->_program);
        }

        void GLSLShader::LoadFromString(GLenum type, const string& source) {
            GLuint shader = glCreateShader(type);

            const char * ptmp = source.c_str();
            glShaderSource(shader, 1, &ptmp, NULL);

            GLint status;
            glCompileShader(shader);
            glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
            if (status == GL_FALSE) {
                GLint infoLogLength;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
                GLchar *infoLog = new GLchar[infoLogLength];
                glGetShaderInfoLog(shader, infoLogLength, NULL, infoLog);
                cerr << "Compile log: " << infoLog << endl;
                delete[] infoLog;
            }
            this->_shaders[this->_totalShaders++] = shader;
        }


        void GLSLShader::CreateAndLinkProgram() {
            this->_program = glCreateProgram();
            if (this->_shaders[VERTEX_SHADER] != 0) {
                glAttachShader(this->_program, this->_shaders[VERTEX_SHADER]);
            }
            if (this->_shaders[FRAGMENT_SHADER] != 0) {
                glAttachShader(this->_program, this->_shaders[FRAGMENT_SHADER]);
            }
            if (this->_shaders[GEOMETRY_SHADER] != 0) {
                glAttachShader(this->_program, this->_shaders[GEOMETRY_SHADER]);
            }

            GLint status;
            glLinkProgram(this->_program);
            glGetProgramiv(this->_program, GL_LINK_STATUS, &status);
            if (status == GL_FALSE) {
                GLint infoLogLength;

                glGetProgramiv(this->_program, GL_INFO_LOG_LENGTH, &infoLogLength);
                GLchar *infoLog = new GLchar[infoLogLength];
                glGetProgramInfoLog(this->_program, infoLogLength, NULL, infoLog);
                cerr << "Link log: " << infoLog << endl;
                delete[] infoLog;
            }

            glDeleteShader(this->_shaders[VERTEX_SHADER]);
            glDeleteShader(this->_shaders[FRAGMENT_SHADER]);
            glDeleteShader(this->_shaders[GEOMETRY_SHADER]);
        }

        void GLSLShader::Use() {
            glUseProgram(this->_program);
        }

        void GLSLShader::UnUse() {
            glUseProgram(0);
        }

        void GLSLShader::AddAttribute(const string& attribute) {
            this->_attributeList[attribute] = this->_count_attr++;
        }

        GLuint GLSLShader::operator [](const string& attribute) {
            return this->_attributeList[attribute];
        }

        void GLSLShader::AddUniform(const string& uniform) {
            this->_uniformLocationList[uniform] = glGetUniformLocation(this->_program, uniform.c_str());
        }

        GLuint GLSLShader::operator()(const string& uniform) {
            return this->_uniformLocationList[uniform];
        }


        void GLSLShader::LoadFromFile(GLenum whichShader, const string& filename) {
            ifstream fp;
            fp.open(filename.c_str(), ios_base::in);
            if (fp) {
                string line, buffer;
                while (getline(fp, line)) {
                    buffer.append(line);
                    buffer.append("\r\n");
                }
                LoadFromString(whichShader, buffer);
            }
            else {
                cerr << "Error loading shader: " << filename << endl;
            }
        }

    }
}
