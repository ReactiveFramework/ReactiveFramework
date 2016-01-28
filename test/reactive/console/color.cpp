/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <boost/test/unit_test.hpp>
#include <reactive/console/color.hpp>

BOOST_AUTO_TEST_SUITE(reactive_console_color)

BOOST_AUTO_TEST_CASE(test_color)
{
    BOOST_CHECK_EQUAL(reactive::console::color::Red, "\033[31m");
}

BOOST_AUTO_TEST_SUITE_END()
