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
#include <reactive/crypto/sha384.hpp>
//#include <cryptopp/sha.h>
//#include <cryptopp/filters.h>
//#include <cryptopp/hex.h>
#include <openssl/sha.h>

namespace reactive {
namespace crypto {

    std::string sha384(const std::string& data_)
    {
        unsigned char digest[SHA512_DIGEST_LENGTH];

        SHA512_CTX ctx;
        SHA384_Init(&ctx);
        SHA384_Update(&ctx, data_.c_str(), data_.length());
        SHA384_Final(digest, &ctx);

        char output[SHA384_DIGEST_LENGTH*2+1];
        for (int i = 0; i < SHA384_DIGEST_LENGTH; i++) {
            sprintf(&output[i*2], "%02x", (unsigned int)digest[i]);
        }

        std::string hash(output);

        std::transform(hash.begin(), hash.end(), hash.begin(), ::tolower);

        return hash;
    }

} // end of crypto namespace
} // end of reactive namespace
