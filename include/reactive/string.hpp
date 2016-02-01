/**
 * Reactive
 *
 * (c) 2015-2016 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
#pragma once

#include <sstream>
#include <vector>

namespace reactive {

    class string
    {
    private:

        /**
         * A private constructor prevents from instantiation
         */
        string() {}

    public:

        /** Split a string a let the slice in order as they were found
         *
         * @param delimiter_  Delimiting string between which the input string will be split
         * @param content_    Input string to split
         * @param parts_      Output set of strings that will contain the results of the split search
         */
        static void split(const std::string& delimiter_, const std::string& content_, std::vector<std::string>& parts_)
        {
            // These have to be in size_t type to avoid bad assignements
            std::size_t match_index = 0, pos = 0;

            //--- Scanning the rest of the string
            while (match_index != std::string::npos) {
                // If content_ is empty or delimiter is not present in the content string
                // Then match_index will be at npos
                match_index = content_.find(delimiter_, pos);

                // Extracting the string from the last position 'pos' to the found
                // length (match_index-pos)
                if (match_index != std::string::npos) {
                    parts_.push_back(content_.substr(pos, match_index-pos));
                    pos = match_index + delimiter_.size();
                } else {
                    parts_.push_back(content_.substr(pos));
                }
            }
        }

        /**
         * Convert string to NumberType
         *
         * @param value_    The string number
         * @return          The number
         */
        template<typename NumberType, typename SourceType>
        static NumberType to_number(const SourceType& value_)
        {
            std::stringstream iss(value_);
            NumberType x;

            if (!(iss >> x)) {
                return (NumberType)0;
            }

            return x;
        }

        template <typename T>
        static std::string stringify(T t)
        {
            std::ostringstream out;
            out << t;
            if (!out.good()) {
                //ABORT("Failed to stringify!");
            }
            return out.str();
        }
    }; // end of string class
} // end of reactive namespace
