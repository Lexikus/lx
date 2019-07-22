#version 400 core

uniform mat4 uLights;
uniform float uBrightness;
uniform float uContrast;
uniform float uGrayscale;

in vec4 vCol;
in vec2 vUV;
in vec3 vNor;
in vec3 vPos;
in vec3 vNormalWorldSpace;

out vec4 fragColor;

uniform sampler2D tex;

void setBrightness(inout vec3 c ) {
    c = clamp(c + uBrightness, 0.0f, 1.0f);
}

void setContrast(inout vec3 c) {
    float f = (uContrast + 1.0f) / (1.0f - uContrast);
    c = f * (c - 0.5f) + 0.5f;
}

void setGrayscale(inout vec3 c) {
    float f = (c.x + c.y + c.z) / 3;
    c = mix(vec3(f), c, uGrayscale);
}

vec3 ambientReflection (float intesity, float factor, vec3 lightColor) {
    return intesity * factor * lightColor;
}

vec3 diffuseReflection(float intensity, float factor, vec3 lightColor, vec3 lightDirection, vec3 normal) {
    return clamp(dot(lightDirection, normal), 0.0f, 1.0f) * intensity * factor * lightColor;
}

vec3 specularReflection(float intensity, float factor, vec3 lightColor, float hardness, vec3 viewDirection, vec3 reflextionDirection) {
    return pow(clamp(dot(viewDirection, reflextionDirection), 0.0f, 1.0f), hardness) * intensity * factor * lightColor;
}

vec3 specularBlinnReflection(float intensity, float factor, vec3 lightColor, float hardness, vec3 viewDirection, vec3 lightDirection, vec3 normal) {
    vec3 reflextionDirection = normalize(viewDirection + lightDirection);
    return pow(clamp(dot(normal, reflextionDirection), 0.0f, 1.0f), hardness) * intensity * factor * lightColor;
}

void main() {
    vec3 color = texture(tex, vUV).rgb;
    vec3 c = color * vCol.rgb;

    vec3 lightPosition = uLights[0].xyz;
    vec3 ambientLightColor = uLights[1].xyz;
    vec3 lightColor = uLights[2].xyz;
    vec3 viewPosition = uLights[3].xyz;

    float ambientIntensity = uLights[0].w;
    float diffuseIntensity = uLights[1].w;
    float specularIntensity = uLights[2].w;
    float hardness = uLights[3].w;

    vec3 lightDirection = lightPosition;

    float diffuseFactor = 1.0f;
    float ambientFactor = 1.0f;
    float specularFactor = 1.0f;

    vec3 normal = normalize(vNormalWorldSpace);
    vec3 viewDirection = normalize(viewPosition - vPos);
    vec3 reflectionDirection = reflect(-lightDirection, normal);

    vec3 ambient = ambientReflection(ambientIntensity, ambientFactor, ambientLightColor);
    vec3 diffuse = diffuseReflection(diffuseIntensity, diffuseFactor, lightColor, lightDirection, normal);
    // vec3 specular = specularReflection(specularIntensity, specularFactor, lightColor, hardness, viewDirection, reflectionDirection);
    vec3 specular = specularBlinnReflection(specularIntensity, specularFactor, lightColor, hardness, viewDirection, lightDirection, normal);

    vec3 finalColor = (ambient + diffuse + specular) * c;

    fragColor = vec4(finalColor, 1.0f);
}