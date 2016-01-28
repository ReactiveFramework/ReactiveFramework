/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <string>
#include <reactive/http/message.hpp>

namespace reactive {
namespace http {

    void message::setVersion(const std::string& version_)
    {
        m_version = version_;
    }

    const std::string& message::getVersion() const
    {
        return m_version;
    }

    void message::setContent(const std::string& content_)
    {
        m_content = content_;
    }

    const std::string& message::getContent() const
    {
        return m_content;
    }

    std::string& message::getContent()
    {
        return m_content;
    }

    void message::addHeader(const std::string& name_, const std::string& value_, bool unique_)
    {
        m_headers.add(name_, value_, unique_);
    }

    const header_bag& message::getHeaders() const
    {
        return m_headers;
    }

    header_bag& message::getHeaders()
    {
        return m_headers;
    }

} // end of http namespace
} // end of reactive namespace
