#shader vertex
#version 430 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 normal;
layout(location = 2) in vec4 color;

uniform mat4 u_MVP;
out vec4 outColor;

void main()
{
	outColor = vec4(color.r, color.g, color.b, color.a);
	gl_Position = u_MVP * position;
};


#shader fragment
#version 430 core

in vec4 outColor;
layout(location = 0) out vec4 color;

void main()
{
	color = outColor;
};