// Copyright (C) 2013-2015 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#error "Only <CommonAPI/CommonAPI.hpp> can be included directly, this file may disappear or change contents."
#endif

#ifndef COMMONAPI_DBUS_DBUS_HELPER_HPP_
#define COMMONAPI_DBUS_DBUS_HELPER_HPP_

#include <unordered_map>
#include <vector>

namespace CommonAPI {
namespace DBus {

template <int ...>
struct index_sequence {};


template <int N, int ...S>
struct make_sequence : make_sequence<N-1, N-1, S...> {};

template <int ...S>
struct make_sequence<0, S...> {
    typedef index_sequence<S...> type;
};


template <int N, int _Offset, int ...S>
struct make_sequence_range : make_sequence_range<N-1, _Offset, N-1+_Offset, S...> {};

template <int _Offset, int ...S>
struct make_sequence_range<0, _Offset, S...> {
    typedef index_sequence<S...> type;
};

template<typename _Type>
struct is_std_vector { static const bool value = false; };

template<typename _Type>
struct is_std_vector<std::vector<_Type> > { static const bool value = true; };

template<typename _Type>
struct is_std_unordered_map { static const bool value = false; };

template<typename _Key, typename _Value, typename _Hash>
struct is_std_unordered_map<std::unordered_map<_Key, _Value, _Hash>> { static const bool value = true; };

} // namespace DBus
} // namespace CommonAPI

#endif // COMMONAPI_DBUS_DBUS_HELPER_HPP_