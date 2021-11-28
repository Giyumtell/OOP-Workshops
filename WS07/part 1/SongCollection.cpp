#include "SongCollection.h"
namespace sdds
{
	const std::string WHITESPACE = " \n\r\t\f\v";
	std::string ltrim(const std::string& s)
	{
		size_t start = s.find_first_not_of(WHITESPACE);
		return (start == std::string::npos) ? "" : s.substr(start);
	}

	std::string rtrim(const std::string& s)
	{
		size_t end = s.find_last_not_of(WHITESPACE);
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}

	std::string trim(const std::string& s)
	{
		return rtrim(ltrim(s));
	}
    SongCollection::SongCollection()
    {
    }
    SongCollection::~SongCollection()
    {
		for (auto itr = m_songs.begin(); itr != m_songs.end(); itr++)
		{
			delete (*itr);
		}
    }
    SongCollection::SongCollection(const char* filename)
    {
		std::ifstream file(filename);
		if (!file)
		{
			throw "ERROR: Cannot open file";
		}
		while (file)
		{
			std::string temp;
			Song* stemp = new Song;
			char a;
			for (size_t i = 0; i < 3; i++)
			{
				for (size_t i = 0; i < 25; i++)
				{
					file.get(a);
					if (a!='\n')
					{
						temp += a;
					}
					
				}
				i == 0 ? stemp->title = trim(temp) : i == 1 ? stemp->artist = trim(temp) : stemp->album = trim(temp);
				temp = "";
			}
			for (size_t i = 0; i < 3; i++)
			{
				bool emptyflag = true;
				for (size_t i = 0; i < 5; i++)
				{
					file.get(a);
					if (a!=' ')
					{
						emptyflag = false;
					}
					if (a != '\n')
					{
						temp += a;
					}
				}
				if (!emptyflag)
				{
					i == 0 ? stemp->releaseYear = std::stoi(trim(temp)) : i == 1 ? stemp->lengthOfSong = std::stoi(trim(temp)) : stemp->m_price = std::stod(trim(temp));
				}
				else
				{
					stemp->releaseYear = 0;
				}
				temp = "";
			}
			m_songs.push_back(stemp);
			file.get(a);
		}
    }
	void SongCollection::display(std::ostream& out) const
	{
		size_t total = 0;
		for (auto itr = m_songs.begin(); itr != m_songs.end(); itr++)
		{
			out << **itr << std::endl;
			total += (**itr).lengthOfSong;
		}
		out << "----------------------------------------------------------------------------------------\n" << "|                                                        Total Listening Time: " << total / 3600 << ":" << (total / 60) % 60 << ":" << total % 3600 %60 << " |\n";
	}
	void SongCollection::sort(const char* target)
	{
		std::sort(m_songs.begin(), m_songs.end(), [=](const Song* lhs, const Song* rhs)
		{
			return (strcmp(target, "title") == 0) ? lhs->title < rhs->title : (strcmp(target ,"album") == 0) ? lhs->album < rhs->album : lhs->lengthOfSong < rhs->lengthOfSong;
		});
	}
	void SongCollection::cleanAlbum()
	{
		for (auto& i : m_songs)
		{
			if (i->album == "[None]")
			{
				i->album = " ";
			}
		}
	}
	bool SongCollection::inCollection(const char* target) const
	{
		bool res = false;
		for (auto& i : m_songs)
		{
			if (i->artist == target)
			{
				res = true;
			}
		}
		return res;
	}
	std::list<Song> SongCollection::getSongsForArtist(const char* artist) const
	{
		std::list<Song> res;
		for (auto& i : m_songs)
		{
			if (i->artist == artist)
			{
				res.push_back(*i);
			}
		}
		return res;
	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		out << "| " << std::setw(20) << std::left << theSong.title << " | " << std::setw(15) << std::left << theSong.artist << " | " << std::setw(20) << std::left << theSong.album << " | ";
		if (theSong.releaseYear == 0)
		{
			out << std::setw(6)  << " " << " | ";
		}
		else
		{
			out << std::setw(6) << std::right << theSong.releaseYear << " | ";
		}
		out << theSong.lengthOfSong/60<<":" <<std::setfill('0')<<std::setw(2)<< theSong.lengthOfSong%60 << std::setfill(' ') << " | " << theSong.m_price << " |";
		return out;
	}
}