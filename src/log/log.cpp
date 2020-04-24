#include "log.h"

namespace creative::log {

    void initialize() {
        s_creative_logger = std::make_shared<Logger>("CR");
        CREATIVE_TRACE("Creative Logger Ready!")
        s_masterpiece_logger = std::make_shared<Logger>("MP");
        LOG_TRACE("Masterpiece Logger Ready!")
    }

    std::shared_ptr<Logger> &get_creative_logger() {
        return s_creative_logger;
    }

    std::shared_ptr<Logger> &get_masterpiece_logger() {
        return s_masterpiece_logger;
    }

}