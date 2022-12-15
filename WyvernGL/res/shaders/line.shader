#shader vertex
#version 430 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

uniform mat4 u_MVP;
out vec4 out_color;

void main()
{
	out_color = color;
	gl_Position = u_MVP * position;
};


#shader fragment
#version 430 core

in vec4 out_color;
layout(location = 0) out vec4 color;

void main()
{
	color = out_color;
};