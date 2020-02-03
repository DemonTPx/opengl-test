#version 330 core

out vec4 FragColor;

in vec2 textureCoordinate;

uniform sampler2D aTexture;

void main()
{
	FragColor = texture(aTexture, textureCoordinate);
}
