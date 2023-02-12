//
// Created by qicosmos on 2/13/19.
//

#ifndef CINATRA_CINATRA_HPP
#define CINATRA_CINATRA_HPP

#ifdef _MSC_VER
#define ssize_t cinatra_ssize_t
#endif

#include "cinatra/http_server.hpp"
#include "cinatra/client_factory.hpp"

#ifdef _MSC_VER
#undef ssize_t
#endif

#endif //CINATRA_CINATRA_HPP
