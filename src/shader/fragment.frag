#version 330 core

out vec4 FragColor;

in vec2 textureCoordinate;

uniform sampler2D aTexture1;
uniform sampler2D aTexture2;

void main()
{
	FragColor = mix(texture(aTexture1, textureCoordinate), texture(aTexture2, textureCoordinate), 0.2);
}