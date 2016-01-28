/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#pragma once

namespace reactive {
namespace web {
namespace middleware {

    class middleware
    {
    public:
        virtual ~middleware() {}

        virtual void beforeRun();

        virtual void invoke();
    };

} // end of middleware namespace
} // end of web namespace
} // end of reactive namespace


