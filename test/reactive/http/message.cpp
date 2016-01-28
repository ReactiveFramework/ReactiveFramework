/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <boost/test/unit_test.hpp>
#include <reactive/http/message.hpp>

BOOST_AUTO_TEST_SUITE(reactive_http_message)

BOOST_AUTO_TEST_CASE(test_version)
{
    reactive::http::message message;

    message.setVersion("1.1");

    BOOST_CHECK_EQUAL(message.getVersion(), "1.1");
}

BOOST_AUTO_TEST_CASE(test_content)
{
    reactive::http::message message;

    message.setContent("bar");

    BOOST_CHECK_EQUAL(message.getContent(), "bar");
}

BOOST_AUTO_TEST_CASE(test_headers)
{
    reactive::http::message message;

    BOOST_CHECK_EQUAL(message.getHeaders().size(), 0u);

    message.addHeader("Server", "Reactive");

    BOOST_CHECK_EQUAL(message.getHeaders().size(), 1u);
}

BOOST_AUTO_TEST_SUITE_END()
