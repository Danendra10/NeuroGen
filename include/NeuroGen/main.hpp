#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <NeuroGen/Objects.hpp>

// To have a dynamic ammount of hidden layers
class Layers {
protected:
    uint16_t total_layers;
};

class NeuroGen : public Layers {
public:
    void SetLayers(uint16_t _total_layers) {
        total_layers = _total_layers;
    }

    uint16_t GetLayers() {
        return total_layers;
    }
};

#endif  // MAIN_HPP_