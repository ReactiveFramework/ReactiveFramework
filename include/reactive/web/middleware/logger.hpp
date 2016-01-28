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
#include <reactive/console/color.hpp>
#include <reactive/web/middleware/middleware.hpp>
#include <reactive/defer.hpp>

using reactive::console::color;

namespace reactive {
namespace web {
namespace middleware {

    class logger : public middleware
    {
    public:
        logger() {}
        ~logger() {}

        void beforeRun()
        {
            std::cout
                << color.ResetAll
                << color.Reverse
                << " Server running on "
                << color.ResetAll
                << color.BackgroundMagenta
                << color.White
                << " "
                << "127.0.0.1"
                << " "
                << color.ResetAll
                << std::endl
                << std::endl;
        }

        void invoke()
        {
            // init date start
            defer([this]() {
                // log.Printf("  %s   %s   %s  %s", fmtDuration(start), fmtStatus(c), fmtMethod(c), fmtPath(path))

                std::cout
                    << "  "
                    << duration(start)
                    << "   "
                    << status(c)
                    << "   "
                    << method(c)
                    << "  "
                    << path(path)
                ;
            });
        }

        std::string duration()
        {
            /*
            return fmt.Sprintf("%s%s%13s%s", colors.ResetAll, colors.Dim, time.Since(start), colors.ResetAll)
             */
            return color.ResetAll + color.Dim + "123ms" + color.ResetAll;
        }

        std::string status()
        {
            int code = 200;
            std::string c = color.BackgroundGreen;
            /*
            code := httputil.ResponseStatus(c.ResponseWriter)

            color := colors.White

            switch {
            case code >= 200 && code <= 299:
                color += colors.BackgroundGreen
            case code >= 300 && code <= 399:
                color += colors.BackgroundCyan
            case code >= 400 && code <= 499:
                color += colors.BackgroundYellow
            default:
                color += colors.BackgroundRed
            }

            return fmt.Sprintf("%s%s %3d %s", colors.ResetAll, color, code, colors.ResetAll)
             */
            return color.ResetAll + c + " " + std::to_string(code) + " " + color.ResetAll;
        }

        std::string method()
        {
            std::string c = color.Green;

            /*var color string

            switch c.Request.Method {
            case "GET":
                color += colors.Green
            case "POST":
                color += colors.Cyan
            case "PUT", "PATCH":
                color += colors.Blue
            case "DELETE":
                color += colors.Red
            }

            return fmt.Sprintf("%s%s%s%s", colors.ResetAll, color, c.Request.Method, colors.ResetAll)
            */
           return color.ResetAll + c + "GET" + color.ResetAll;
        }

        std::string path(std::string& path)
        {
            //return fmt.Sprintf("%s%s%s%s", colors.ResetAll, colors.Dim, path, colors.ResetAll)
            return color.ResetAll + color.Dim + path + color.ResetAll;
        }
    };

} // end of middleware namespace
} // end of web namespace
} // end of reactive namespace


