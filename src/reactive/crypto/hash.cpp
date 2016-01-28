/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <string>
#include <stdexcept>
#include <reactive/crypto/hash.hpp>
#include <reactive/crypto/md5.hpp>
#include <reactive/crypto/sha1.hpp>
#include <reactive/crypto/sha224.hpp>
#include <reactive/crypto/sha256.hpp>
#include <reactive/crypto/sha384.hpp>
#include <reactive/crypto/sha512.hpp>
#include <reactive/crypto/whirlpool.hpp>

namespace reactive {
namespace crypto {

    std::string hash(const hash_type_t& type_, const std::string& data_)
    {
        switch (type_) {
            case MD5:       return md5(data_);
            case SHA1:      return sha1(data_);
            case SHA224:    return sha224(data_);
            case SHA256:    return sha256(data_);
            case SHA384:    return sha384(data_);
            case SHA512:    return sha512(data_);
            case WHIRLPOOL: return whirlpool(data_);
            default:
                throw std::runtime_error("Unknown hash type");
        }
    }

} // end of crypto namespace
} // end of reactive namespace
