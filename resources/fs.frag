#version 330 core
uniform sampler2D tex;

uniform vec2 uResolution;
out vec4 FragColor;

void main()
{
	vec2 uv = gl_FragCoord.xy/uResolution;
	FragColor = texture(tex, uv);
}
