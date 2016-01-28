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
#include <reactive/crypto/sha224.hpp>
//#include <cryptopp/sha.h>
//#include <cryptopp/filters.h>
//#include <cryptopp/hex.h>
#include <openssl/sha.h>

namespace reactive {
namespace crypto {

    std::string sha224(const std::string& data_)
    {
        unsigned char digest[SHA256_DIGEST_LENGTH];

        SHA256_CTX ctx;
        SHA224_Init(&ctx);
        SHA224_Update(&ctx, data_.c_str(), data_.length());
        SHA224_Final(digest, &ctx);

        char output[SHA224_DIGEST_LENGTH*2+1];
        for (int i = 0; i < SHA224_DIGEST_LENGTH; i++) {
            sprintf(&output[i*2], "%02x", (unsigned int)digest[i]);
        }

        std::string hash(output);

        std::transform(hash.begin(), hash.end(), hash.begin(), ::tolower);

        return hash;
    }

} // end of crypto namespace
} // end of reactive namespace
