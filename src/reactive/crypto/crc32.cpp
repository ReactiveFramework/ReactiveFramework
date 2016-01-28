/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <string>
#include <reactive/crypto/crc32.hpp>

namespace reactive {
namespace crypto {

    uint32_t crc32(const std::string& data_)
    {
        uint32_t crc = 0 ^ 0xFFFFFFFF;

        for (std::size_t i = 0; i < data_.length(); ++i) {
            uint8_t byte = data_[i];
            crc = ((crc >> 8) & 0x00FFFFFF) ^ crc32_tab[(crc ^ byte) & 0xFF];
        }

        return crc ^ 0xFFFFFFFF;
    }

} // end of crypto namespace
} // end of reactive namespace
