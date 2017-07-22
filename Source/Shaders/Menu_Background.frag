#version 120

#ifdef GL_ES
precision mediump float;
#endif

uniform float t;
uniform vec2 resolution;

void main( void ) {
	vec2 p = gl_FragCoord.xy / resolution.xy;

    vec3 stripes = vec3(step(0.25, mod(p.x - 0.2*t, 0.5)));

    // vignette
    vec2 center = p - vec2(1,1);
    float len = length(center);
    float vignette = smoothstep(1.5, 0.5, len);

    vec3 pixel = vec3(.3,.3,.3);
    pixel -= 0.1*stripes;
    pixel = mix(pixel, pixel * vec3(vignette), 0.5);

	gl_FragColor = vec4(pixel.xyz, 1.0);
}
