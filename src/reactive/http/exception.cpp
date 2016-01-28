/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <string>
#include <reactive/http/exception.hpp>

namespace reactive {
namespace http {

    const status_t& exception::getHttpStatusCode() const
    {
        return m_http_status_code;
    }

} // end of http namespace
} // end of reactive namespace
