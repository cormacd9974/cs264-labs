#include <iostream>
#include "Module.h"
#include "Programme.h"
#include "Placement.h"

int main() {
    Module cs264("CS264", 5, 181);
    Module cs357("CS357", 5, 155);

    Placement placement("CS399", "Placement in software company", 50);

    if (cs264 == cs357) {
        std::cout << "CS264 and CS357 are identical modules.\n";
    } else {
        std::cout << "CS264 and CS357 are'nt identical modules.\n";
    }

    Programme csse("CSSE", 3, 10);
    csse.addModule(&cs264);
    csse.addModule(&cs357);
    csse.addModule(&placement);
    std::cout << csse.toStr() << std::endl;

    return 0;
}
