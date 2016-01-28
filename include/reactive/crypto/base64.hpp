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

    class base64
    {
    private:
        static const std::string chars;
    public:
        static std::string encode(const std::string& data_);

        static std::string decode(const std::string& data_);
    };

} // end of crypto namespace
} // end of reactive namespace
