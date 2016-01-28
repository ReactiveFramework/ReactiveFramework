/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <string>
#include <reactive/crypto/crc16.hpp>

namespace reactive {
namespace crypto {

    uint16_t crc16(const std::string& data_)
    {
        uint16_t crc = 0;

        for (std::size_t i = 0; i < data_.length(); ++i) {
            uint8_t byte = data_[i];
            crc = (crc << 8) ^ crc16_tab[((crc >> 8) ^ byte) & 0x00FF];
        }

        return crc;
    }

} // end of crypto namespace
} // end of reactive namespace
