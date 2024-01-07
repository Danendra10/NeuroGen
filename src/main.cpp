#include <NeuroGen/main.hpp>
#include <logger/logger.hpp>

using namespace Literals;

int main() {
    NeuroGen nn;
    nn.SetLayers(10);

    logging::Logger logger_instance;
    logger_instance.Log(logging::RED, "TOTAL LAYERS %d", nn.GetLayers());
}
