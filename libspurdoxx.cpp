/* libspurdoxx by Pr0Wolf29 */

/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int random_int(const int &max, const int &min)
{
	return rand() % max + min;
}

std::vector<std::string> ebinfaces = {":D", ":DD", ":DDD", ":-D", "XD", "XXD", "XDD", "XXDD"};

std::string GetEbinFace(void)
{
	std::string s = " ";
	s += ebinfaces[random_int(ebinfaces.size(),0)];
	return s;
}

bool find_replace_all(std::string &s, const std::string &find, const std::string &replace)
{
	bool rval = false;

	size_t i = 0;
	while((i = s.find(find, i)) != std::string::npos)
	{
		s.replace(i, find.length(), replace);
		i += replace.length();
		rval = true;
	}
	return rval;
}

std::vector<std::pair<std::string,std::string>> replacements = {
	{"wh", "w"},
	{"th", "d"},
	{"af", "ab"},
	{"ap", "ab"},
	{"ca", "ga"},
	{"ck", "gg"},
	{"co", "go"},
	{"ev", "eb"},
	{"ex", "egz"},
	{"et", "ed"},
	{"iv", "ib"},
	{"it", "id"},
	{"ke", "ge"},
	{"nt", "nd"},
	{"op", "ob"},
	{"ot", "od"},
	{"po", "bo"},
	{"pe", "be"},
	{"pi", "bi"},
	{"up", "ub"},
	{"va", "ba"},
	{"ck", "gg"},
	{"cr", "gr"},
	{"kn", "gn"},
	{"lt", "ld"},
	{"mm", "m"},
	{"nt", "dn"},
	{"pr", "br"},
	{"ts", "dz"},
	{"tr", "dr"},
	{"bs", "bz"},
	{"ds", "dz"},
	{"es", "es"},
	{"fs", "fz"},
	{"gs", "gz"},
	{" is", " iz"},
	{"ls", "lz"},
	{"ms", "mz"},
	{"ns", "nz"},
	{"rs", "rz"},
	{"ss", "sz"},
	{"ts", "tz"},
	{"us", "uz"},
	{"ws", "wz"},
	{"ys", "yz"},
	{"alk", "olk"},
	{"ing", "ign"},
	{"ic", "ig"},
	{"ng", "nk"},
	{"kek", "geg"},
	{"epic", "ebin"},
	{"some", "sum"},
	{"meme", "maymay"}
};

std::string to_spurdo(std::string input)
{
	//Make string lowercase.
	std::transform(input.begin(), input.end(),input.begin(), ::tolower);

	//Iterate replacements.
	for(const auto &it : replacements)
	{
		find_replace_all(input, it.first, it.second);
	}

	bool EbinFaceFound = false;
	std::vector<std::string> temp_cp = {",", "."};
	for(const std::string &it_cp : temp_cp)
	{
		srand(time(NULL));
		if(find_replace_all(input, it_cp, GetEbinFace()))
		{
			EbinFaceFound = true;
		}
	}

	if(!EbinFaceFound)
	{
		input += GetEbinFace();
	}

	return input;
}
