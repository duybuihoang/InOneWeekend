#include "camera.h"
#include "material.h"

void camera::render(const hittable& world) {
   initialize();

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = 0; j < imageHeight; j++)
    {
        //std::clog << "\rScanlines remaining: " << (imageHeight - j) << ' ' << std::flush;
        for (int i = 0; i < imageWidth; i++)
        {  
            color pixelColor(0,0,0);
            for (int sample = 0; sample < samplePerPixel; sample++)
            {
                ray r = getRay(i, j);
                pixelColor += rayColor(r, maxDepth, world);
            }
            write_color(std::cout, pixelSampleScale * pixelColor);
        }
    }

    std::clog << "\nDone.\t\n";
    
}

void camera::initialize(){
    imageHeight = int(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight;

    pixelSampleScale = 1.0 / samplePerPixel;

    center = lookFrom;

    auto focalLength = (lookFrom - lookAt).length();

    auto theta = degreesToRadians(vfov);
    auto h = tan(theta / 2);
    auto viewportHeight = 2.0 * h * focalLength;
    auto viewportWidth = viewportHeight * (double (imageWidth) / imageHeight);

    w = unitVector(lookFrom - lookAt);
    u = unitVector(cross(vUp, w));
    v = cross(w, u);

    auto viewportU = viewportWidth * u;
    auto viewportV = viewportHeight * -v;

    pixelDeltaU = viewportU / imageWidth;
    pixelDeltaV = viewportV / imageHeight;

    auto viewportUpperLeft = center - (focalLength * w) - viewportU/2 - viewportV/2;
    pixel00Loc = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

    std::clog << "viewportWidth: " << viewportWidth << " viewportHeight: " << viewportHeight << "\n";
    std::clog << "viewportU: " << viewportU << " viewportV: " << viewportV << "\n";
    std::clog << "imageWidth: " << imageWidth << " imageHeight: " << imageHeight << "\n";
    std::clog << "pixelDeltaU: " << pixelDeltaU << " pixelDeltaV: " << pixelDeltaV << "\n";

    std::clog << "viewportUpperLeft: " << viewportUpperLeft << "\n";
    std::clog << "pixel00Loc: " << pixel00Loc << "\n";
}



color camera::rayColor(const ray& r,int depth, const hittable& world) const{

    hitRecord rec;

    if (depth <= 0)
    {
        return color(0,0,0);
    }
    
    if(world.hit(r, 0.001, infinity, rec))
    {
        // vec3 direction = randomOnHemiSphere(rec.normal) + randomUnitVector();
        // return 0.5 * rayColor(ray(rec.p, direction), depth-1, world);

        ray scattered;
        color attenuation;
        if(rec.mat->scatter(r, rec, attenuation, scattered)){
            return attenuation * rayColor(scattered, depth-1, world);
        }
        return color(0,0,0);

    }

    vec3 unitDirection = unitVector(r.direction());
    auto t = 0.5 * (unitDirection.y() + 1.0);
    return (1.0 - t) * color(1,1,1) + t * color(0.5, 0.7, 1.0);

}

ray camera::getRay(int i, int j) const{
    auto offset = sampleSquare();
    auto pixelSample = pixel00Loc 
                        + (i + offset.x()) * pixelDeltaU
                        + (j + offset.y()) * pixelDeltaV;

    auto rayOrigin = center;
    auto rayDirection = pixelSample - rayOrigin;

    return ray(rayOrigin, rayDirection);
}

vec3 camera::sampleSquare() const{
    return vec3(randomDouble() - 0.5, randomDouble() - 0.5, 0);
}