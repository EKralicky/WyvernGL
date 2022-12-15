#shader vertex
#version 430 core

layout(location = 0) in vec2 position;

uniform mat4 u_Ortho;
out vec4 out_color;

void main()
{
	gl_Position = u_Ortho * vec4(position, 0, 1.0);
};


#shader fragment
#version 430 core

layout(location = 0) out vec4 color;

void main()
{
	color = vec4(1.0, 1.0, 1.0, 1.0);
};