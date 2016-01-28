/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <boost/test/unit_test.hpp>
#include <reactive/string.hpp>

BOOST_AUTO_TEST_SUITE(reactive_string_tests)

BOOST_AUTO_TEST_CASE(test_split_as_vector)
{
    std::string str_in = "foo,bar;what";

    std::vector<std::string> vstr_out;

    reactive::string::split(";", str_in, vstr_out);

    BOOST_REQUIRE_EQUAL(vstr_out.size(), 2U);

    BOOST_CHECK_EQUAL(vstr_out[0], "foo,bar");
    BOOST_CHECK_EQUAL(vstr_out[1], "what");
}

BOOST_AUTO_TEST_CASE(test_to_number)
{
    char test[] = "123";
    BOOST_CHECK_EQUAL(reactive::string::to_number<int>(test), 123);
    BOOST_CHECK_EQUAL(reactive::string::to_number<int>("123"), 123);
    BOOST_CHECK_EQUAL(reactive::string::to_number<double>("123.34"), 123.34);
    BOOST_CHECK_EQUAL(reactive::string::to_number<long>("12346456"), 12346456);
    BOOST_CHECK_EQUAL(reactive::string::to_number<int>("-1234"), -1234);
    BOOST_CHECK_EQUAL(reactive::string::to_number<int>("a"), 0);
}


BOOST_AUTO_TEST_SUITE_END()
