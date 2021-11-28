#ifndef SDDS_SONG_COLLECTION_H
#define SDDS_SONG_COLLECTION_H
#include<string>
#include<vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <cstring>
namespace sdds
{
	struct Song
	{
		std::string artist;
		std::string title;
		std::string album;
		double m_price;
		size_t releaseYear;
		size_t lengthOfSong;
	};
	class SongCollection
	{
	public:
		SongCollection();
		SongCollection(const char* filename);
		~SongCollection();
		void display(std::ostream& out) const;
		void sort(const char * target);
		void cleanAlbum();
		bool inCollection(const char* artist) const;
		std::list<Song> getSongsForArtist(const char* artist) const;
	private:
		std::vector<Song*> m_songs;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONG_COLLECTION_H
