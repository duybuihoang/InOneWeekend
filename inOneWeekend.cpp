#include "utils.h"
#include "hittableList.h"
#include "sphere.h"
#include "camera.h"
#include "material.h"
#include "lambertian.h"
#include "metal.h"
#include "dielectric.h"

int main() {

    hittableList world;

    //TODO: THỬ DÙNG GƯƠNG CẦU LÕM ĐỂ PHẢN XẠ ÁNH SÁNG
    
    auto groundMaterial = make_shared<lambertian>(vec3(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0, -1000, 0), 1000, groundMaterial));

    for (int i = -11; i < 11; i++)
    {
        for (int j = -11; j < 11; j++)
        {
            auto chooseMat = randomDouble();
            point3 center(i + 0.9 * randomDouble(), 0.2, j + 0.9 * randomDouble());
            if ((center - point3(4, 0.2, 0)).length() > 0.9)
            {
                shared_ptr<material> sphereMaterial;

                if (chooseMat < 0.8) // diffuse
                {
                    auto albedo = color::random() * color::random();
                    sphereMaterial = make_shared<lambertian>(albedo);
                    world.add(make_shared<sphere>(center, 0.2, sphereMaterial));
                }
                else if (chooseMat < 0.95) // metal
                {
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = randomDouble(0, 0.5);
                    sphereMaterial = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphereMaterial));
                }
                else // glass
                {
                    sphereMaterial = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphereMaterial));
                }
            }
        }
        
    }

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));
    
    

   camera cam;
   cam.aspectRatio = 16.0 / 9.0;
   cam.imageWidth = 1200;
   cam.samplePerPixel = 500;
   cam.maxDepth = 50;

   cam.vfov = 20;
   cam.lookFrom = point3(13, 2, 3);
    cam.lookAt = point3(0, 0, 0);
    cam.vUp = vec3(0, 1, 0);

    cam.defocusAngle = 0.6;
    cam.focusDist = 10.0;

   cam.render(world);
}