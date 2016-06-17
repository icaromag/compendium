#include <strings.h>
#include <string>
#include <vector>

#include <iostream>

#define S_ED_SCORE(a, b) (a == b ? 2 : -1)
#define S_MAX(a, b) (a >= b ? a : b)
#define S_MIN(a, b) (a < b ? a : b)

namespace compendium {

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
		int* preffixLengths = Strings::generatePreffixLengths(text);
		std::size_t periodicLength = text.length() - preffixLengths[text.length()];

		return text.length() % periodicLength == 0 ? periodicLength : text.length();
	}

	int Strings::editDistance(const std::string& from, const std::string& to)
	{
		int dp[from.length() + 1][to.length() + 1];

		for (std::size_t i = 0; i <= from.length(); i++)
		{
			for (std::size_t j = 0; j <= to.length(); j++)
			{
				if (i == 0)
					dp[i][j] = j;

				else if (j == 0)
					dp[i][j] = i;

				else if (from[i - 1] == to[j - 1])
					dp[i][j] = dp[i - 1][j - 1];

				else {
					dp[i][j] = S_MIN(dp[i][j - 1], dp[i - 1][j]);

					if (dp[i - 1][j - 1] < dp[i][j])
						dp[i][j] = dp[i - 1][j - 1];

					dp[i][j]++;
				}
			}
		}

		return dp[from.length()][to.length()];
	}

	std::pair<int, int>** Strings::editDistancePath(const std::string& from, const std::string& to)
	{
		std::pair<int, int>** dp = new std::pair<int, int>*[from.length() + 1];

		for (std::size_t i = 0; i <= from.length(); i++)
			dp[i] = new std::pair<int, int>[to.length()];

		for (std::size_t i = 0; i <= from.length(); i++)
		{
			for (std::size_t j = 0; j <= to.length(); j++)
			{
				if (i == 0)
					dp[i][j] = std::make_pair(j, -1);

				else if (j == 0)
					dp[i][j] = std::make_pair(i, -1);

				else if (from[i - 1] == to[j - 1]) // match
					dp[i][j] = std::make_pair(dp[i - 1][j - 1].first, 1);

				else {
					if (dp[i][j - 1] < dp[i - 1][j]) // insertion
						dp[i][j] = std::make_pair(dp[i][j - 1].first + 1, 2);

					else if (dp[i - 1][j] < dp[i - 1][j - 1]) // remove
						dp[i][j] = std::make_pair(dp[i - 1][j].first + 1, 3);

					else // replace
						dp[i][j] = std::make_pair(dp[i - 1][j - 1].first + 1, 4);
				}
			}
		}

		return dp;
	}

}
