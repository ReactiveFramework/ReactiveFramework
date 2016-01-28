/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#pragma once

#include <functional>

// @see http://blog.korfuri.fr/post/go-defer-in-cpp/
namespace reactive {

    class DeferredAction {
    public:
        ~DeferredAction()
        {
            if (m_f) {
                m_f();
            }
        }

        DeferredAction(DeferredAction&& l) : m_f(std::forward<std::function<void()>>(l.m_f))
        {
            // This code uses 0 instead of nullptr to cope with g++4.4 not
            // having this keyword
            l.m_f = 0;
        }

        DeferredAction(DeferredAction const& l) = delete;
        DeferredAction& operator=(DeferredAction const&) = delete;
        DeferredAction& operator=(DeferredAction&&) = delete;

    private:
        template<typename... Tpack>
        DeferredAction(Tpack&&... p) : m_f(std::bind(std::forward<Tpack>(p)...)) {}

        std::function<void()> m_f;

        template<typename... Tpack>
        friend DeferredAction defer(Tpack&&... p);
    };
} // end of reactive namespace

template<typename... Tpack>
DeferredAction defer(Tpack&&... p) {
    return reactive::DeferredAction(std::forward<Tpack>(p)...);
}
