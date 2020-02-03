#version 330 core
layout (points) in;
layout (triangle_strip, max_vertices = 77) out;

uniform float size;

const float PI = 3.1415926;
// max_vertices = (numSegments * 1.5) + 2
const int numSegments = 50;

out vec2 textureCoordinate;

void main()
{
    vec4 pos = vec4(1.0);

    for (int i = 0; i <= numSegments; i++)
    {
        if (i % 2 == 0) {
            gl_Position = gl_in[0].gl_Position;
            textureCoordinate = vec2(0.0, 0.0) + vec2(0.5, 0.5);
            EmitVertex();
        }

        float t = PI * 2.0 * i / numSegments;
        pos = vec4(gl_in[0].gl_Position.x + (sin(t) * size), gl_in[0].gl_Position.y + (cos(t) * size), 0.0, 1.0);
        textureCoordinate = vec2(sin(t) * 0.45, cos(t) * -0.45) + vec2(0.5, 0.49);
        gl_Position = pos;
        EmitVertex();
    }

    EndPrimitive();
}
