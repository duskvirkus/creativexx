#include "init.h"
#include <torch/torch.h>

namespace creative {

    void initialize() {
        CREATIVE_INFO("Creative++ Was Initialized!")

        torch::Tensor tensor = torch::rand({2, 3});
        std::cout << tensor << std::endl;
        CREATIVE_INFO("torch include worked if you see a random tensor here: " + tensor.toString())
    }

}
