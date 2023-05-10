#include <iostream>

#include <rdlib/Renderer.h>

int main() {
    std::cout << "Hello, World!" << std::endl;

    rdlib::Renderer *renderer = rdlib::Renderer::instanciate();

    rdlib::Renderer::finalize();

    return 0;
}
