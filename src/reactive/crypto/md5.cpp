/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <string>
#include <algorithm>
#include <reactive/crypto/md5.hpp>
//#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
//#include <cryptopp/md5.h>
//#include <cryptopp/filters.h>
//#include <cryptopp/hex.h>
#include <openssl/md5.h>

namespace reactive {
namespace crypto {

    std::string md5(const std::string& data_)
    {
        unsigned char digest[16];

        MD5_CTX ctx;
        MD5_Init(&ctx);
        MD5_Update(&ctx, data_.c_str(), data_.length());
        MD5_Final(digest, &ctx);

        char output[33];
        for (int i = 0; i < 16; i++) {
            sprintf(&output[i*2], "%02x", (unsigned int)digest[i]);
        }

        std::string hash(output);

        std::transform(hash.begin(), hash.end(), hash.begin(), ::tolower);

        return hash;
    }

} // end of crypto namespace
} // end of reactive namespace
