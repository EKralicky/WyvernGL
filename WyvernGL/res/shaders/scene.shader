#shader vertex
#version 430 core

layout(location = 0) in vec4 vPosition;
layout(location = 1) in vec4 vNormal;
layout(location = 2) in vec4 vColor;
uniform mat4 u_Model;
uniform mat4 u_MVP;
out vec4 objectColor;
out vec4 normal;
out vec4 fragPos;

void main()
{
	normal = mat4(transpose(inverse(u_Model))) * vNormal;
	objectColor = vColor;
	gl_Position = u_MVP * vec4(vPosition);
	// gets a fragment position in world space
	fragPos = vec4(u_Model * vPosition);
};


#shader fragment  
#version 430 core

layout(location = 0) out vec4 outColor;
uniform vec4 u_LightColor;
uniform vec4 u_LightPos;
uniform vec4 u_ViewPos;
in vec4 objectColor;
in vec4 normal;
in vec4 fragPos;
in vec4 viewPos;

void main()
{
	float ambientStrength = 0.1;
	vec4 ambient = ambientStrength * u_LightColor;

	//diffuse
	vec4 norm = normal;
	// calculate direction vector between the light vertex and the fragment pos 
	vec4 lightDir = normalize(u_LightPos - fragPos);
	// diffuse impact
	// darker diffuse component the greater the angle between two vectors
	// If the angle is greater than 90, the diffuse component will become zero
	// This is useful for faces that dont intersect light rays directly
	float diff = max(dot(norm, lightDir), 0.0);
	vec4 diffuse = diff * u_LightColor;
	  
	// Specular
	float specularStrength = 0.5;
	vec4 viewDir = normalize(u_ViewPos - fragPos);
	vec4 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);
	vec4 specular = specularStrength * spec * u_LightColor;

	vec4 result = (ambient + diffuse + specular) * objectColor;


	outColor = result;
};