#ifndef COLLECTION_H_
#define COLLECTION_H_
#include <string>
#include <iostream>
#include <stdexcept> 
namespace sdds
{
	template<typename T>
	class Collection
	{
	public:
		Collection();
		~Collection();
		Collection(const std::string& name);
		Collection(Collection&) = delete;
		Collection& operator = (Collection&) = delete;
		Collection(Collection&&) = delete;
		Collection& operator = (Collection&&) = delete;
		const std::string& name() const;
		size_t size() const;
		void setObserver(void (*observer)(const Collection<T>&, const T&));
		Collection<T>& operator+=(const T& item);
		T& operator[](size_t idx) const;
		T* operator[](const std::string& title) const;
	private:
		T* m_array = nullptr;
		std::string m_colName;
		size_t m_size = 0;
		void (*m_observer)(const Collection<T>&, const T&) = nullptr;

	};
	template<typename T>
	inline Collection<T>::Collection()
	{
	}
	template<typename T>
	inline Collection<T>::~Collection()
	{
		delete[] m_array;
	}
	template<typename T>
	inline Collection<T>::Collection(const std::string& name)
	{
		m_colName = name;
	}
	template<typename T>
	inline const std::string& Collection<T>::name() const
	{
		return m_colName;
	}
	template<typename T>
	inline size_t Collection<T>::size() const
	{
		return m_size;
	}
	template<typename T>
	inline void Collection<T>::setObserver(void(*observer)(const Collection<T>&, const T&))
	{
		m_observer = *observer;
	}
	template<typename T>
	inline Collection<T>& Collection<T>::operator+=(const T& item)
	{
		T* temp = nullptr;
		bool check = true;
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_array[i].title() == item.title())
			{
				check = false;
			}
		}
		if (check)
		{
			if (m_size == 0)
			{
				m_array = new T[1];
				m_array[0] = item;
				m_size++;
			}
			else
			{
				temp = new T[m_size + 1];
				for (size_t i = 0; i < m_size; i++)
				{
					temp[i] = m_array[i];
				}
				temp[m_size] = item;
				m_size++;
				delete[] m_array;
				m_array = temp;
				temp = nullptr;
			}
			if (m_observer)
			{
				m_observer(*this, item);
			}
		}
		return *this;
	}
	template<typename T>
	inline T& Collection<T>::operator[](size_t idx) const
	{
		if (idx > m_size - 1 || idx < 0)
		{
			std::string msg = "Bad index [" + std::to_string(idx);
			msg += "]. Collection has [";
			msg += std::to_string(m_size) + "] items.";
			std::out_of_range e(msg);
			throw e;
		}
		else
		{
			return m_array[idx];
		}
	}
	template<typename T>
	inline T* Collection<T>::operator[](const std::string& title) const
	{
		bool check = false;
		size_t target = 0;
		T* res = nullptr;
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_array[i].title() == title)
			{
				check = true;
				target = i;
			}
		}
		if (check)
		{
			res = &m_array[target];
		}
		return res;
	}
	template<typename T>
	std::ostream& operator<<(std::ostream& ostr, Collection<T>& obj)
	{
		for (size_t i = 0; i < obj.size(); i++)
		{
			ostr << obj[i];
		}
		return ostr;
	}
}
#endif // !COLLECTION_H_

