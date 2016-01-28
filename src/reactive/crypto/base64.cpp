/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <string>
#include <reactive/crypto/base64.hpp>
#include <reactive/string.hpp>
#include <errno.h>
#include <stdexcept>

namespace reactive {
namespace crypto {

    const std::string base64::chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string base64::encode(const std::string& data_)
    {
        std::string result;
        int i = 0;
        int j = 0;
        unsigned char array3[3];
        unsigned char array4[4];
        const char* bytesToEncode = data_.c_str();
        std::size_t length = data_.size();

        while (length--) {
            array3[i++] = *(bytesToEncode++);
            if (i == 3) {
                array4[0] = (array3[0] & 0xfc) >> 2;
                array4[1] = ((array3[0] & 0x03) << 4) + ((array3[1] & 0xf0) >> 4);
                array4[2] = ((array3[1] & 0x0f) << 2) + ((array3[2] & 0xc0) >> 6);
                array4[3] = array3[2] & 0x3f;
                for (i = 0; i < 4; i++) {
                    result += base64::chars[array4[i]];
                }
                i = 0;
            }
        }

        if (i != 0) {
            for (j = i; j < 3; j++) {
                array3[j] = '\0';
            }
            array4[0] = (array3[0] & 0xfc) >> 2;
            array4[1] = ((array3[0] & 0x03) << 4) + ((array3[1] & 0xf0) >> 4);
            array4[2] = ((array3[1] & 0x0f) << 2) + ((array3[2] & 0xc0) >> 6);
            array4[3] = array3[2] & 0x3f;
            for (j = 0; j < i + 1; j++) {
                result += base64::chars[array4[j]];
            }
            while (i++ < 3) {
                result += '=';
            }
        }

        return result;
    }

    std::string base64::decode(const std::string& data_)
    {
        auto isBase64 = [](unsigned char c) -> bool {
            return (isalnum(c) || (c == '+') || (c == '/'));
        };

        std::size_t i = 0;
        unsigned char array3[3];
        unsigned char array4[4];
        std::string result;

        for (unsigned char c : data_) {
        //foreach (unsigned char c, data_) {
            if (c == '=') {
                // TODO(bmahler): Note that this does not validate that
                // there are the correct number of '=' characters!
                break; // Reached the padding.
            }

            if (!isBase64(c)) {
                throw std::runtime_error("Invalid character '" + reactive::string::stringify(c) + "'");
                //return Error("Invalid character '" + reactive::string::stringify(c) + "'");
            }

            array4[i++] = c;

            if (i == 4) {
                for (i = 0; i < 4; i++) {
                    array4[i] = static_cast<unsigned char>(chars.find(array4[i]));
                }
                array3[0] = (array4[0] << 2) + ((array4[1] & 0x30) >> 4);
                array3[1] = ((array4[1] & 0xf) << 4) + ((array4[2] & 0x3c) >> 2);
                array3[2] = ((array4[2] & 0x3) << 6) + array4[3];
                for (i = 0; i < 3; i++) {
                    result += array3[i];
                }
                i = 0;
            }
        }

        if (i != 0) {
            std::size_t j;

            for (j = i; j < 4; j++) {
                array4[j] = 0;
            }

            for (j = 0; j < 4; j++) {
                array4[j] = static_cast<unsigned char>(chars.find(array4[j]));
            }
            array3[0] = (array4[0] << 2) + ((array4[1] & 0x30) >> 4);
            array3[1] = ((array4[1] & 0xf) << 4) + ((array4[2] & 0x3c) >> 2);
            array3[2] = ((array4[2] & 0x3) << 6) + array4[3];
            for (j = 0; (j < i - 1); j++) {
                result += array3[j];
            }
        }

        return result;
    }

} // end of crypto namespace
} // end of reactive namespace
