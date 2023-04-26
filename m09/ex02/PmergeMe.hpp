#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

/* ************************************************************************** */
/* ******************************  LIBRARIES  ******************************* */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>

/* ************************************************************************** */
/* ******************************  PROTOTYPES  ****************************** */
/* ************************************************************************** */

bool    string_has_only_positive_integers(std::string str);
void    apply_insertion_merge_sort_algo(int argc, char *argv[]);

#endif

