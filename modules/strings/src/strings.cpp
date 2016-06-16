#include <strings.h>
#include <string>
#include <vector>

namespace compendium
{

	std::string Strings::hello_strings()
	{
		return "module strings test";
	}

	int* Strings::generatePreffixLengths(const std::string& text)
	{
		int* occurr = new int[text.length() + 1];
		occurr[0] = -1;

		int k = -1;

		for (std::size_t i = 1; i <= text.length(); i++)
		{
			while (k >= 0 && text[k] != text[i - 1])
				k = occurr[k];

			occurr[i] = ++k;
		}

		return occurr;
	}

	int kmp(const std::string& text, const std::string& pattern, int* occurr, size_t& i, int& k)
	{
		for (; i <= text.length(); i++)
		{
			while (k >= 0 && pattern[k] != text[i - 1])
				k = occurr[k];

			if (++k == (int) pattern.length())
			{
				int iText = i - k;
				k = occurr[k];
				return iText;
			}
		}

		return -1;
	}

	int Strings::kmp_find(const std::string& text, const std::string& pattern)
	{
		std::size_t i = 0;
		int k = 0;
		return kmp(text, pattern, Strings::generatePreffixLengths(pattern), i, k) >= 0;
	}

	int Strings::kmp_findFrom(const std::string& text, const std::string& pattern, std::size_t startIndex)
	{
		int k = 0;
		return kmp(text, pattern, Strings::generatePreffixLengths(pattern), startIndex, k);
	}

	std::size_t Strings::kmp_findAll(const std::string& text, const std::string& pattern, std::vector<std::size_t>& positions)
	{
		std::size_t i = 0;
		int k = 0, pos;

		while ((pos = kmp(text, pattern, Strings::generatePreffixLengths(pattern), i, k)) >= 0)
			positions.push_back(pos);

		return positions.size();
	}

	std::size_t Strings::kmp_count(const std::string& text, const std::string& pattern)
	{
		std::size_t i = 0, count = 0;
		int k = 0;

		while (kmp(text, pattern, Strings::generatePreffixLengths(pattern), i, k) > 0)
			count++;

		return count;
	}

	std::size_t Strings::countPeriodicSubstring(const std::string& text)
	{
		int* occurr = new int[text.length() + 1];
		occurr[0] = -1;

		int k = -1;

		for (std::size_t i = 1; i <= text.length(); i++)
		{
			while (k >= 0 && text[k] != text[i - 1])
				k = occurr[k];

			occurr[i] = ++k;
		}

		return occurr;

		// int* preffixLengths = Strings::generatePreffixLengths(text);
		// std::size_t i = text.length();

		// while (preffixLengths[i] > 0)
		// 	i = preffixLengths[i];

		// return i;
	}

}
