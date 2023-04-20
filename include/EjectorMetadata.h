#pragma once

#include <optional>
#include <c_types.h>

struct EjectorInfo {
    const char *canonicalName;
    class Ejector *ejector;
    float distanceInCm;
};

extern EjectorInfo ejectorMetadata[4];

#pragma region METADATA HELPERS
std::optional<EjectorInfo> getEjectorMetadata(const char *canonicalName);
std::optional<EjectorInfo> getEjectorMetadata(const uint8 * canonicalName, unsigned int canonicalNameLength);
#pragma endregion
