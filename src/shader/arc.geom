#version 330 core
layout (points) in;
//layout (line_strip, max_vertices = 40) out;
layout (triangle_strip, max_vertices = 40) out;

uniform float angle;
uniform float size;

const float PI = 3.1415926;
const float multiplier = (PI * 2) / 360.0;

out vec2 textureCoordinate;

void main()
{
	float rClose = gl_in[0].gl_Position.y;
	float rFar = rClose + 0.1;

	float currentAngle = (angle - (size / 2.0)) * multiplier;
	float stepSize = (size / 20.0) * multiplier;

	vec4 pos = vec4(1.0);

	for (int i = 0; i < 20; i++)
	{
		// draw close
		pos = vec4(cos(currentAngle) * rClose, sin(currentAngle) * rClose, 0.0, 1.0);
		textureCoordinate = vec2((1.0 / 20.0) * i, 0.0);
		gl_Position = pos;
		EmitVertex();
	
		// draw far
		pos = vec4(cos(currentAngle) * rFar, sin(currentAngle) * rFar, 0.0, 1.0);
		textureCoordinate = vec2((1.0 / 20.0) * i, 0.1);
		gl_Position = pos;
		EmitVertex();

		currentAngle = currentAngle + stepSize;
	}
	
	EndPrimitive();
}
