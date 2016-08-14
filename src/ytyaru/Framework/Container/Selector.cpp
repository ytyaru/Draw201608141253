#pragma once
#include "Selector.h"
#include <type_traits>
#include <limits.h>
#include <assert.h>

namespace ytyaru {
namespace Framework {
namespace Container {
template <typename T> Selector<T>::Selector(void) { m_selected = NULL; }
template <typename T> Selector<T>::~Selector(void) {}
template <typename T>
bool Selector<T>::Add(const std::basic_string<TCHAR>& key, T value)
{
	if (IsContain(key)) { return false; }
	else { m_map[key] = value; return true; }
}
template <typename T>
bool Selector<T>::Remove(const std::basic_string<TCHAR>& key)
{
	for(std::map<std::basic_string<TCHAR>, T>::iterator it = m_map.begin(); it != m_map.end();) {
		if (it->first == key) {
			//// íœğŒ‚É‡‚¤—v‘f‚ªŒ©‚Â‚©‚Á‚½
			//cout << "key " << it->first << " is deleted." << endl;
			m_map.erase(it++);
			return true;
		} else{ ++it; }
	}
	return false;
	//if (IsContain(key)) { return m_map.erase(m_map.begin()); false; }
	//else { m_map[key] = value; return true; }
}
template <typename T>
void Selector<T>::Clear()
{
	m_map.clear();
}
template <typename T>
bool Selector<T>::IsContain(const std::basic_string<TCHAR>& key)
{
	if (0 < m_map.count(key)) { return true; }
	else { return false; }
}
template <typename T>
void Selector<T>::Select(const std::basic_string<TCHAR>& key)
{
	if (IsContain(key)) { m_selected = m_map[key]; }
}
template <typename T>
T Selector<T>::GetSelected()
{
	return m_selected;
}
template <typename T>
T Selector<T>::Get(const std::basic_string<TCHAR>& key)
{
	if (IsContain(key)) { return m_map[key]; }
	else { return 0; }
}
//template class Selector<int>;
}
}
}
