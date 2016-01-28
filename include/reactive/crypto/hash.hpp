/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#pragma once

#include <string>

namespace reactive {
namespace crypto {

    typedef enum {
        MD5,
        SHA1,
        SHA224,
        SHA256,
        SHA384,
        SHA512,
        WHIRLPOOL
    } hash_type_t;

    std::string hash(const hash_type_t& type_, const std::string& data_);

} // end of crypto namespace
} // end of reactive namespace
