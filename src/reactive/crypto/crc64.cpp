/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <string>
#include <reactive/crypto/crc64.hpp>

namespace reactive {
namespace crypto {

    uint64_t crc64(const std::string& data_)
    {
        uint64_t crc = 0;

        for (std::size_t i = 0; i < data_.length(); ++i) {
            uint8_t byte = data_[i];
            crc = crc64_tab[(uint8_t) crc ^ byte] ^ (crc >> 8);
        }

        return crc;
    }

} // end of crypto namespace
} // end of reactive namespace
