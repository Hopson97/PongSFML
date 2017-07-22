#ifdef GL_ES
precision mediump float;
#endif

uniform float t;
uniform vec2 resolution;

void main( void ) {
	vec2 p = gl_FragCoord.xy / resolution.xy;




	gl_FragColor = vec4(cos(t)/2 + sin(p.y)/2, p.y - sin(t), p.x/p.y, 0.5);

}
