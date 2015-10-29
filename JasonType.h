////////////////////////////////////////////////////////////////////////////////
/// @brief Library to build up Jason documents.
///
/// @file JasonBuilder.h
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

#ifndef JASON_TYPE_H
#define JASON_TYPE_H

#include <string>
#include <exception>

namespace arangodb {
  namespace jason {

    struct JasonTypeError : std::exception {
      private:
        std::string _msg;
      public:
        JasonTypeError (std::string const& msg) : _msg(msg) {
        }
        char const* what() const noexcept {
          return _msg.c_str();
        }
    };
    
    enum JasonType {
      None,           // not yet initialized
      Null,           // JSON null
      Bool,
      Array,
      Object,
      Double,
      UTCDate,
      External,
      MinKey,
      MaxKey,
      Int,
      UInt,
      SmallInt,
      String,
      Binary,
      BCD,
      Custom
    };

    char const* JasonTypeName (JasonType);

  }  // namespace arangodb::jason
}  // namespace arangodb

#endif
