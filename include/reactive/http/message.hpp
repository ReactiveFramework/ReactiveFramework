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

#include <reactive/http/header_bag.hpp>

namespace reactive {
namespace http {

    class message
    {
    private:
        /**
         * HTTP Version of the response, by default this is version 1.1
         */
        std::string m_version;

        /**
         * Header bag
         */
        header_bag m_headers;

        /**
         * Message content
         */
        std::string m_content;
    public:
        /**
         * Set http version
         *
         * @param version_
         */
        void setVersion(const std::string& version_);

        /**
         * Get the version
         *
         * @return The http version string
         */
        const std::string& getVersion() const;

        /**
         * Set response content
         *
         * @param content_ The string of response content
         */
        void setContent(const std::string& content_);

        /**
         * Get response content
         *
         * @return The string of response content
         */
        const std::string& getContent() const;

        std::string& getContent();

        /**
         * Add header in header_bag
         *
         * @param name_   The string of header name
         * @param value_  The string of header value
         * @param unique_ Determin if header is unique
         */
        void addHeader(const std::string& name_, const std::string& value_, bool unique_ = true);

        /**
         * Get a const reference to the headers
         *
         * @return The header_bag object
         */
        const header_bag& getHeaders() const;

        /**
         * Get a mutable reference to the headers
         *
         * @return The header_bag object
         */
        header_bag& getHeaders();
    };

} // end of http namespace
} // end of reactive namespace
