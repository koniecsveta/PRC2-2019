#include "pbmimage.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    PbmImage image;
    image.load("MARBLES.PBM");
    // image.setBit(1, 1, 0);
    image.seedFill4(1, 22, 0);
    image.printBits();
    image.save("MARBLES2.PBM");

    return 0;
}