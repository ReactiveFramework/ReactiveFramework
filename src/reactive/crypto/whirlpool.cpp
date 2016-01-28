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
#include <reactive/crypto/whirlpool.hpp>
//#include <cryptopp/whrlpool.h>
//#include <cryptopp/filters.h>
//#include <cryptopp/hex.h>
#include <openssl/whrlpool.h>

namespace reactive {
namespace crypto {

    std::string whirlpool(const std::string& data_)
    {
        unsigned char digest[WHIRLPOOL_DIGEST_LENGTH];

        WHIRLPOOL_CTX ctx;
        WHIRLPOOL_Init(&ctx);
        WHIRLPOOL_Update(&ctx, data_.c_str(), data_.length());
        WHIRLPOOL_Final(digest, &ctx);

        char output[WHIRLPOOL_DIGEST_LENGTH*2+1];
        for (int i = 0; i < WHIRLPOOL_DIGEST_LENGTH; i++) {
            sprintf(&output[i*2], "%02x", (unsigned int)digest[i]);
        }

        std::string hash(output);

        std::transform(hash.begin(), hash.end(), hash.begin(), ::tolower);

        return hash;
    }

} // end of crypto namespace
} // end of reactive namespace
