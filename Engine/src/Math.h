#pragma once

#define PackedStruct struct __attribute__ ((packed))

namespace Engine::Math{
    PackedStruct Vec3{
        float x;
        float y;
        float z;
    };
}