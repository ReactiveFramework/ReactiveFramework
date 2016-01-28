/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <boost/test/unit_test.hpp>
#include <reactive/crypto/crc32.hpp>

BOOST_AUTO_TEST_SUITE(reactive_crypto_crc32)

BOOST_AUTO_TEST_CASE(test_crc32)
{
    BOOST_CHECK_EQUAL(reactive::crypto::crc32("hello world"), 222957957u);
}

BOOST_AUTO_TEST_SUITE_END()
