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

using MatchId = std::uint64_t;

inline constexpr Price PRICE_SCALE = 10'000;

enum class Side : std::uint8_t {
    BUY,
    SELL,
};

enum class OrderType: std::uint8_t {
    LIMIT,
    MARKET,
    IOC,  // Immediate or Cancel order -- it fills what it can
    FOK, // fill or kill --- no partial trades (all now or nothing)
    GTC, // 
    STOP,
    STOP_LIMIT,
    ICEBERG, // hidden reserve when trade in masses
    POST_ONLY,
    
};

}
