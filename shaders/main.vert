#version 400 core
layout (location = 0) in vec4 vertex; // <vec2 pos, vec2 tex>
out vec2 TexCoords;

uniform double dim;
uniform double asp;

void main()
{
    gl_Position = vec4(vertex.x / (dim * asp), vertex.y / dim, 0.0, 1.0);
    TexCoords = vertex.zw;
}  