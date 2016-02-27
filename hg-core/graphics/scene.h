//
// Created by han on 16-1-22.
//

#ifndef HG_SCENE_H
#define HG_SCENE_H

#include <memory>
#include <string>
#include <unordered_map>

#include "renderer.h"
#include "buffers/buffer.h"
#include "buffers/vertexArray.h"

#include "camera/camera.h"
#include "../app/window.h"

namespace hg{ namespace graphics{
        class scene {
        private:
            std::shared_ptr<vertexArray> m_vao;
            std::shared_ptr<buffer> m_vbo;
            std::shared_ptr<camera> m_camera;
            std::shared_ptr<hg::app::window> m_window;
            std::string m_window_title;
            hg::maths::mat4 m_MVP;

            std::unordered_map<std::string, int8_t > m_name2type;
            std::unordered_map<int8_t, std::shared_ptr<hg::graphics::renderer>> m_renderer_dict;

        public:
            scene(const char* title, int weight, int height);


        private:
            void init_renderer();


        };

    }
}


#endif //HG_SCENE_H
