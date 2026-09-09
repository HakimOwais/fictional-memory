#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <string_view>
#include <type_traits>

namespace exchange::core {

using Price = std::int64_t;

using Quantity = std::uint32_t;

using OrderId = std::uint64_t;

using SequenceNumber = std::uint64_t;

using Timestamp = std::uint64_t;

using ParticipantId = std::uint32_t;


}