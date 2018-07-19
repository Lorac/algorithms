template <class InputIterator>
typename std::iterator_traits<InputIterator>::value_type
secondLowest(InputIterator begin, InputIterator end)
{
    using Type = typename std::iterator_traits<InputIterator>::value_type;
    const Type maxElement = *std::max_element(begin, end);
 
    std::pair<Type, Type> lowest{maxElement, maxElement};
 
    for (; begin != end; ++begin)
    {
        if (*begin < lowest.first)
            lowest.first = *begin;
        else if (*begin < lowest.second)
            lowest.second = *begin;
    }
 
    return lowest.second;
}

template <class InputIterator, class Comparator>
typename std::iterator_traits<InputIterator>::value_type
secondLowest(InputIterator begin, InputIterator end, Comparator comp)
{
    using Type = typename std::iterator_traits<InputIterator>::value_type;
    const Type maxElement = *std::max_element(begin, end, comp);
 
    std::pair<Type, Type> lowest{maxElement, maxElement};
 
    for (; begin != end; ++begin)
    {
        if (comp(*begin, lowest.first))
            lowest.first = *begin;
        else if (comp(*begin, lowest.second))
            lowest.second = *begin;
    }
 
    return lowest.second;
}
