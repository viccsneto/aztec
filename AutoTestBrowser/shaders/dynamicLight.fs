#version 130
in vec3 color;
in vec2 texOffset;
out vec4 frag_color;
uniform sampler2D texture1;
uniform float time;
vec3 lightIntensity = vec3(100,100,100);
float attenuation_c = 0.02;
float attenuation_l = 0.02;
float attenuation_q = 0.02;

uniform vec3 lightPos;

vec4 calcLight(vec4 value)
{
	float d= distance(lightPos.xy,gl_FragCoord.xy);
	value.xyz = value.xyz * (lightIntensity /  (attenuation_c + attenuation_l*d + attenuation_q*pow(d,2)));
	return value;
}

void main ()
{	
	frag_color =  calcLight(texture(texture1,texOffset));	
}
