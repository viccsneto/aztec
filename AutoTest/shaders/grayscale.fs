#version 130
in vec3 color;
in vec2 texOffset;
out vec4 frag_color;
uniform sampler2D texture1;
uniform float time;
vec4 grayscale(vec4 value)
{	
	float cvalue = (0.25*value.r)+(0.5*value.g)+(0.25*value.b);
	return vec4(cvalue,cvalue,cvalue,value.a);
}

void main ()
{
	frag_color =  grayscale(texture(texture1,texOffset.xy)); 
}