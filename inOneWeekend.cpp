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

    // //TODO: THỬ DÙNG GƯƠNG CẦU LÕM ĐỂ PHẢN XẠ ÁNH SÁNG
    
    // auto materialGround = std::make_shared<lambertian>(color(0.8, 0.8, 0.0));
    // auto materialCenter = std::make_shared<lambertian>(color(0.1, 0.2, 0.5));
    // //auto materialLeft = std::make_shared<metal>(color(0.8, 0.8, 0.8), 0.3);
    // auto materialLeft = std::make_shared<dielectric>(1.5);
    // auto materialBubble = std::make_shared<dielectric>(1.0 / 1.5);
    // auto materialRight = std::make_shared<metal>(color(0.8, 0.6, 0.2), 0.8);


    // world.add(std::make_shared<sphere>(point3(0,-100.5,-1), 100, materialGround));
    // world.add(std::make_shared<sphere>(point3(0,0.5,-1.2), 0.5, materialCenter));
    // world.add(std::make_shared<sphere>(point3(-1,0,-1), 0.5, materialLeft));
    // world.add(std::make_shared<sphere>(point3(-1,0,-1), 0.2, materialBubble));
    // world.add(std::make_shared<sphere>(point3(1,0,-1), 0.5, materialRight));

    // // auto R = cos(pi/4);

    // // auto materialLeft = std::make_shared<lambertian>(color(0, 0, 1));
    // // auto materialRight = std::make_shared<lambertian>(color(1, 0, 0));

    // // world.add(std::make_shared<sphere>(point3(-R, 0, -1), R, materialLeft));
    // // world.add(std::make_shared<sphere>(point3( R, 0, -1), R, materialRight));

    auto groundMaterial = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, groundMaterial));

    for (int i = -11; i < 11; i++)
    {
        for (int j = -11; j < 11; j++)
        {
            auto chooseMat = randomDouble();   
            point3 center = point3(i + 0.9*randomDouble(), 0.2, j + 0.9*randomDouble());

            if((center - point3(4, 0.2, 0)).length() > 0.9)
            {
                shared_ptr<material> sphereMaterial;

                if(chooseMat < 0.8)
                {
                    //diffuse
                    auto albedo = color::random() * color::random();
                    sphereMaterial = make_shared<lambertian>(albedo);
                    auto center2 = center + vec3(0, randomDouble(0, 0.5), 0);   
                    world.add(make_shared<sphere>(center, center2, 0.2, sphereMaterial));
                }
                else if(chooseMat < 0.95)
                {
                    //metal
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = randomDouble(0, 0.5);
                    sphereMaterial = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphereMaterial));
                }
                else
                {
                    //glass
                    sphereMaterial = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphereMaterial));
                }
            }
        }
        
    }
    

   camera cam;
   cam.aspectRatio = 16.0 / 9.0;
   cam.imageWidth = 400;
   cam.samplePerPixel = 100;
   cam.maxDepth = 50;

   cam.vfov = 20;
   cam.lookFrom = point3(13, 2, 3);
    cam.lookAt = point3(0, 0, 0);
    cam.vUp = vec3(0, 1, 0);

    cam.defocusAngle = 0.6;
    cam.focusDist = 10.0;

   cam.render(world);

}