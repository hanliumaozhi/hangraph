//
// Created by han on 16-1-7.
//

#include "shader_str.h"

namespace hg { namespace  shader{

        const std::string sphere_vert = "#version 330 core \n \
						layout(location = 0) in vec3 vVertex; \
						layout(location = 1) in vec3 vColor;\
						out vec4 gcolor;\n \
						void main()\
						{\
							gl_Position = vec4(vVertex, 1);\
							gcolor = vec4(vColor, 1);\
						}";

        const std::string sphere_geoc = "#version 330 core\n \
\
					layout ( points ) in;\
					in vec4 gcolor[];\
\
					layout(triangle_strip, max_vertices = 128) out;\
					out vec4 color;\
					uniform mat4 MVP;\
\
					vec3 V00, V01, V02;\
					mat3 scale_rate = mat3(0.2, 0., 0., 0., 0.2, 0., 0., 0., 0.2);\
					int num_layers = 3;\
\
void produce_vertex(vec3 V0, vec3 V1, vec3 V2, float s, float t)\
{\
	vec3 v = V0 + s*V1 + t*V2;\
	v = scale_rate*normalize(v);\
	gl_Position = MVP*(vec4(v, 0) + gl_in[0].gl_Position);\
	color = gcolor[0];\
	EmitVertex();\
}\
\
void produce_octo(vec3 V0, vec3 V1, vec3 V2)\
{\
	V01 = (V1 - V0);\
	V02 = (V2 - V0);\
	V00 = V0;\
\
	float dt = 1. / float(num_layers);\
	float t_top = 1.;\
	for (int it = 0; it < num_layers; ++it) {\
\
		float t_bot = t_top - dt;\
		float smax_top = 1. - t_top;\
		float smax_bot = 1. - t_bot;\
\
		int nums = it + 1;\
		float ds_top = smax_top / float(nums - 1);\
		float ds_bot = smax_bot / float(nums);\
\
		float s_top = 0.;\
		float s_bot = 0.;\
\
		for (int is = 0; is < nums; is++) {\
			produce_vertex(V00, V01, V02, s_bot, t_bot);\
			produce_vertex(V00, V01, V02, s_top, t_top);\
			s_top += ds_top;\
			s_bot += ds_bot;\
		}\
		produce_vertex(V00, V01, V02, s_bot, t_bot);\
		EndPrimitive();\
\
		t_top = t_bot;\
		t_bot -= dt;\
\
	}\
\
}\
\n \
void main()\
{\
	produce_octo(vec3(1., 0, 0), vec3(0, 1., 0), vec3(0, 0, 1.));\
	produce_octo(vec3(1., 0, 0), vec3(0, -1., 0), vec3(0, 0, 1.));\
	produce_octo(vec3(-1., 0, 0), vec3(0, 1., 0), vec3(0, 0, 1.));\
	produce_octo(vec3(-1., 0, 0), vec3(0, -1., 0), vec3(0, 0, 1.));\
	produce_octo(vec3(1., 0, 0), vec3(0, 1., 0), vec3(0, 0, -1.));\
	produce_octo(vec3(1., 0, 0), vec3(0, -1., 0), vec3(0, 0, -1.));\
	produce_octo(vec3(-1., 0, 0), vec3(0, 1., 0), vec3(0, 0, -1.));\
	produce_octo(vec3(-1., 0, 0), vec3(0, -1., 0), vec3(0, 0, -1.));\
\
}";

        const std::string sphere_frag = "#version 330 core \n \
			in vec4 color;\
layout(location = 0) out vec4 vFragColor; \
\n \
void main()\
{\
	vFragColor = color;\
}";

        const std::string cube_vert = "#version 330 core \n \
						layout(location = 0) in vec3 vVertex; \
						layout(location = 1) in vec3 vColor;\
						out vec4 gcolor;\n \
						void main()\
						{\
							gl_Position = vec4(vVertex, 1);\
							gcolor = vec4(vColor, 1);\
						}";

        const std::string cube_geoc =	"#version 330 core \n \
\
										layout ( points ) in;\
										in vec4 gcolor[];\
\
										layout(triangle_strip, max_vertices = 20) out;\
										out vec4 color;\
\
										uniform mat4 MVP;\
\
										void main()\
										{\
											mat4 m = MVP;\
											color = gcolor[0];\
											vec4 points_center = gl_in[0].gl_Position;\
\
											gl_Position = m * (vec4(-0.1, 0.1, -0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(0.1, 0.1, -0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(-0.1, -0.1, -0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(0.1, -0.1, -0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(-0.1, -0.1, 0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(0.1, -0.1, 0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(-0.1, 0.1, 0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(0.1, 0.1, 0.1, 0) + points_center);\
											EmitVertex();\
											EndPrimitive();\
\
											gl_Position = m * (vec4(-0.1, -0.1, -0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(-0.1, -0.1, 0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(-0.1, 0.1, -0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(-0.1, 0.1, 0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(0.1, 0.1, -0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(0.1, 0.1, 0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(0.1, -0.1, -0.1, 0) + points_center);\
											EmitVertex();\
\
											gl_Position = m * (vec4(0.1, -0.1, 0.1, 0) + points_center);\
											EmitVertex();\
											EndPrimitive();\
											}";

        const std::string cube_frag = "#version 330 core \n \
								in vec4 color;\
								layout(location = 0) out vec4 vFragColor; \
								\n \
								void main()\
								{\
									vFragColor = color;\
								}";

        const std::string font_vert = "#version 330 core\n \
								layout(location = 0) in vec3 vertex;\
								layout(location = 1) in vec2 tex_coord;\
								layout(location = 2) in vec4 color;\
\
								uniform mat4 MVP; \
								void main()\
								{\
									gl_TexCoord[0].xy = tex_coord.xy;\
									gl_FrontColor = color;\
									gl_Position = MVP*vec4(vertex, 1.0);}";


        const std::string font_frag =  "#version 330 core\n \
								uniform sampler2D texture;\
								void main()\
								{\
									float a = texture2D(texture, gl_TexCoord[0].xy).r;\
									gl_FragColor = vec4(gl_Color.rgb, gl_Color.a*a);\
								}";

        const std::string line_vert = "#version 330 core \n \
								layout(location = 0) in vec3 vertex; \
								layout(location = 1) in vec3 color;\
								uniform mat4 MVP; \
								out vec4 gcolor;\
					\
								void main()\
								{\
									gl_Position = MVP*vec4(vertex, 1.0); \
									gcolor = vec4(color, 1.0);\
								}";

        const std::string line_geoc = "#version 330 core \n \
								layout(lines) in;\
								in vec4 gcolor;\
								out vec4 scolor;\
								layout(line_strip, max_vertices = 2) out;\
								void main()\
								{\
									scolor=gcolor;\
									gl_Position = gl_in[0].gl_Position;\
									EmitVertex(); \
									gl_Position = gl_in[1].gl_Position;\
									EmitVertex();\
									EndPrimitive();\
								}";

        const std::string line_frag = "#version 330 core \n \
								in vec4 gcolor;\
								layout(location=0) out vec4 vFragColor;	\
								void main()\
								{\
									vFragColor = gcolor;\
								}";
    }

}
