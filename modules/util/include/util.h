/***************************************************************************
 *   Copyright (C) 2016 by Carreta Furacao
 *
 *   João Pessoa - PB - Brasil
 *
 *   \file util.h
 *   \author Ícaro Lima Magalhães <icaro.lmag@gmail.com>
 *   \date 01/05/2016
 *
 ***************************************************************************/

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>

namespace compendium
{

    /**
     * \brief This class helps other classes offering frequently used functions
     */
    class Util
    {

	public:

		/**
         * \brief default constructor
         */
	 	Util();

		/**
         * \brief default destructor
         */
	 	~Util();

		/**
         * \brief executes a command and pipes the executes command to the calling program
         */
		static std::string hello();

	};

}

#endif // UTIL_H
