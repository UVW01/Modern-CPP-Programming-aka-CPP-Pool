
#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

/* ************************************************************************** */
/* ******************************  LIBRARIES  ******************************* */
/* ************************************************************************** */

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>

/* ************************************************************************** */
/* ******************************  PROTOTYPES  ****************************** */
/* ************************************************************************** */

std::map<std::string, std::string>*     init_db_from_file( void );
int     read_input_file( std::string file_name, \
    std::map<std::string, std::string>* data_map );

#endif