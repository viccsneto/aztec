#version 130

in vec3 vertexPosition;
in vec3 vertexColor;
uniform mat4 projectionMatrix,modelMatrix,viewMatrix;
out vec4 color;
void main()
{
  color = vec4(vertexColor,1);
	gl_Position  = projectionMatrix * viewMatrix * modelMatrix * vec4(vertexPosition, 1);
}