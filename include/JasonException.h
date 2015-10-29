////////////////////////////////////////////////////////////////////////////////
/// @brief Library to build up Jason documents.
///
/// DISCLAIMER
///
/// Copyright 2015 ArangoDB GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Max Neunhoeffer
/// @author Jan Steemann
/// @author Copyright 2015, ArangoDB GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef JASON_EXCEPTION_H
#define JASON_EXCEPTION_H 1

#include <exception>
#include <string>

namespace arangodb {
  namespace jason {

    // base exception class
    struct JasonException : std::exception {
      public:
        enum JasonExceptionType {
          InternalError,
          NotImplemented,
          NumberOutOfRange,
          DuplicateAttributeName,
          BuilderObjectNotSealed,
          BuilderNeedOpenObject,
          BuilderUnexpectedType,
          BuilderUnexpectedValue,

          UnknownError
        };
      private:
        JasonExceptionType _type;
        std::string _msg;
      public:

        JasonException (JasonExceptionType type, std::string const& msg) : _type(type), _msg(msg) {
        }
        
        explicit JasonException (JasonExceptionType type) : JasonException(type, message(type)) {
        }

        char const* what() const noexcept {
          return _msg.c_str();
        }

        static char const* message (JasonExceptionType type) noexcept {
          switch (type) {
            case InternalError:
              return "Internal error";
            case NotImplemented:
              return "Not implemented";
            case DuplicateAttributeName:
              return "Duplicate attribute name";
            case NumberOutOfRange:
              return "Number out of range";
            case BuilderObjectNotSealed:
              return "Object not sealed";
            case BuilderNeedOpenObject:
              return "Need open array or object for close() call";
            case BuilderUnexpectedType:
              return "Unexpected type";
            case BuilderUnexpectedValue:
              return "Unexpected value";

            case UnknownError:
            default:
              return "Unknown error";
          }
        }

    };

  }  // namespace arangodb::jason
}  // namespace arangodb

#endif