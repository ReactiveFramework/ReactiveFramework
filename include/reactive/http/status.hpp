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
namespace http {
namespace status {

    enum STATUS_CODE {
        // 1XX
        CONTINUE                        = 100,
        SWITCHING_PROTOCOLS             = 101,
        PROCESSING                      = 102,

        // 2XX
        OK                              = 200,
        CREATED                         = 201,
        ACCEPTED                        = 202,
        NON_AUTHORITATIVE_INFORMATION   = 203,
        NO_CONTENT                      = 204,
        RESET_CONTENT                   = 205,
        PARTIAL_CONTENT                 = 206,
        MULTI_STATUS                    = 207,
        ALREADY_REPORTED                = 208,
        IM_USED                         = 226,

        MULTIPLE_CHOICES                = 300,
        MOVED_PERMANENTLY               = 301,
        FOUND                           = 302,
        SEE_OTHER                       = 303,
        NOT_MODIFIED                    = 304,
        USE_PROXY                       = 305,
        //RESERVED                        = 306,
        TEMPORARY_REDIRECT              = 307,
        PERMANENT_REDIRECT              = 308,
        TOO_MANY_REDIRECT               = 310,

        // 4XX
        BAD_REQUEST                     = 400,
        UNAUTHORIZED                    = 401,
        PAYMENT_REQUIRED                = 402,
        FORBIDDEN                       = 403,
        NOT_FOUND                       = 404,
        METHOD_NOT_ALLOWED              = 405,
        NOT_ACCEPTABLE                  = 406,
        PROXY_AUTHENTICATION_REQUIRED   = 407,
        REQUEST_TIME_OUT                = 408,
        CONFLICT                        = 409,
        GONE                            = 410,
        LENGTH_REQUIRED                 = 411,
        PRECONDITION_FAILED             = 412,
        REQUEST_ENTITY_TOO_LARGE        = 413,
        REQUEST_URI_TOO_LARGE           = 414,
        UNSUPPORTED_MEDIA_TYPE          = 415,
        REQUESTED_RANGE_NOT_SATISFIABLE = 416,
        EXPECTATION_FAILED              = 417,
        IM_A_TEAPOT                     = 418, // :)
        UNPROCESSABLE_ENTITY            = 422,
        LOCKED                          = 423,
        FAILED_DEPENDENCY               = 424,
        UPGRADE_REQUIRED                = 426,
        PRECONDITION_REQUIRED           = 428,
        TOO_MANY_REQUESTS               = 429,
        REQUEST_HEADER_FIELDS_TOO_LARGE = 431,

        // 5XX
        INTERNAL_SERVER_ERROR           = 500,
        NOT_IMPLEMENTED                 = 501,
        BAD_GATEWAY                     = 502,
        SERVICE_UNAVAILABLE             = 503,
        GATEWAY_TIME_OUT                = 504,
        HTTP_VERSION_NOT_SUPPORTED      = 505,
        INSUFFICIENT_STORAGE            = 507,
        LOOP_DETECTED                   = 508,
        NOT_EXTENDED                    = 510,
        NETWORK_AUTHENTICATION_REQUIRED = 511,
        UNKNOWN                         = 520
    };


} // end of status namespace

    typedef enum status::STATUS_CODE status_t;


namespace status {

    /**
     * Get string reason of http status code
     *
     * @param  code_ The http status code
     * @return       The string of reason
     */
    std::string to_string(const reactive::http::status_t& code_);

} // end of status namespace
} // end of http namespace
} // end of reactive namespace
