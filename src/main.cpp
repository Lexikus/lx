#include <iostream>
#include <string>

#include "core/graphic/context.h"

// settings
const short WIDTH = 800;
const short HEIGHT = 800;
const std::string TITLE = "OPENGL";

int main() {
    Context ctx = {};
    ctx.Init(TITLE, WIDTH, HEIGHT);
    while(true){

    }
    return 0;
}