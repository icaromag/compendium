/***************************************************************************
 *   Copyright (C) 2016 by Ícaro Magalhães and Mateus Pires Lustosa
 *
 *   João Pessoa - PB - Brasil
 *
 *   \file strings.h
 *   \author Ícaro Lima Magalhães <icaro.lmag@gmail.com>
 *   \author Mateus Pires Lustosa <mateusplpl@gmail.com>
 *   \date 02/06/2016
 *
 ***************************************************************************/

#ifndef STRINGS_H
#define STRINGS_H

#include <string>
#include <vector>

namespace compendium
{

	/**
	 * \brief Class string test
	 */
	class Strings {

	public:

		/**
		 * \brief Returns the list of preffix lengths in each position
		 * \return array of preffix lengths
		 */
		static int* generatePreffixLengths(const std::string& text);

		/**
		 * \brief Returns the index of the first occurrence of pattern in text
		 * \param text - string to search in
		 * \param pattern - string to search for
		 * \return index of the first occurrence or -1 if has no occurrence
		 */
		static int kmp_find(const std::string& text, const std::string& pattern);

		/**
		 * \brief Returns the index of the first occurrence of pattern in text starting from an initial position
		 * \param text - string to search in
		 * \param pattern - string to search for
		 * \param startIndex - initial position
		 * \return index of the first occurrence or -1 if has no occurrence
		 */
		static int kmp_findFrom(const std::string& text, const std::string& pattern, std::size_t startIndex);

		/**
		 * \brief Returns a list with all the index of the occurrences of pattern in text
		 * \param text - string to search in
		 * \param pattern - string to search for
		 * \return vector with indexes
		 */
		static std::size_t kmp_findAll(const std::string& text, const std::string& pattern, std::vector<std::size_t>& occurr);

		/**
		 * \brief Returns the number of ocurrences of pattern in text
		 * \param text - string to search in
		 * \param pattern - string to search for
		 * \return number of occurences
		 */
		static std::size_t kmp_count(const std::string& text, const std::string& pattern);

		/**
		 * \brief Returns the length of the smallest substring that forms the text by concatenation
		 * \return substring length
		 */
		static std::size_t countPeriodicSubstring(const std::string& text);

		/**
		 * \brief Returns the edition distance
		 * \return number os editions
		 */
		static int editDistance(const std::string& from, const std::string& to);

		/**
		 * \brief Returns the edition distance and operation matrix
		 * \return matrix of edition distance and operation (0: match, 1: insertion, 2: remove, 3: replace)
		 */
		static std::pair<int, int>** editDistancePath(const std::string& from, const std::string& to);

	};

}

#endif // STRINGS_H
