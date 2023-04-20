#include <cstring>
#include "EjectorMetadata.h"

std::optional<EjectorInfo> getEjectorMetadata(const char *canonicalName) {
    for (EjectorInfo metadata : ejectorMetadata) {
        if (strcmp(metadata.canonicalName, canonicalName) == 0) {
            return metadata;
        }
    }

    // return none
    return {};
}

std::optional<EjectorInfo> getEjectorMetadata(const __uint8_t * canonicalName, unsigned int canonicalNameLength){
    char canonicalNameString[100] = {};

    memcpy(canonicalNameString, canonicalName, canonicalNameLength);

    return getEjectorMetadata(reinterpret_cast<const char *>(canonicalNameString));
}