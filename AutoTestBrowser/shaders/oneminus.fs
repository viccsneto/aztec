#version 130
in vec3 color;
in vec2 texOffset;
out vec4 frag_color;
uniform sampler2D texture1;
uniform float time;
vec4 oneminus(vec4 value)
{	
	return vec4(1-value.r,1-value.g,1-value.b,value.a);
}

void main ()
{
	frag_color =  oneminus(texture(texture1,texOffset.xy)); 
}


