uniform sampler2D texture;
uniform vec2 TexCoord;

uniform float t;

void main()
{

    // lookup the pixel in the texture
    //vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    vec4 pixel = vec4(sin(t),sin(t),sin(t),0.2);
    pixel = pixel * vec4(0, 0, 1, 1);

    // multiply it by the color
    gl_FragColor = gl_Color * pixel;
}
