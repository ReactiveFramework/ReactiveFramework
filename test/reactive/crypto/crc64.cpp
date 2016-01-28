/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <boost/test/unit_test.hpp>
#include <reactive/crypto/crc64.hpp>

BOOST_AUTO_TEST_SUITE(reactive_crypto_crc64)

BOOST_AUTO_TEST_CASE(test_crc64)
{
    BOOST_CHECK_EQUAL(reactive::crypto::crc64("hello world"), 5826792889407104536U);
}

BOOST_AUTO_TEST_SUITE_END()
