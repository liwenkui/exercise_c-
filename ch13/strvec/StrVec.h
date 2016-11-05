#ifndef STRVEC_H
#define STRVEC_H
#include <initializer_list>
#include <string>
#include <memory>
#include <utility>
class StrVec
{
  public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    StrVec(std::initializer_list<std::string>);
    ~StrVec();
    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, const std::string &);

  private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc()
    {
	if (size() == capacity())
	    reallocate();
    }
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();
    void reallocate();
    std::string *cap;
    std::string *elements;
    std::string *first_free;
};

inline std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
inline void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}
// inline void StrVec::free()
// {
//     if (elements)
//     {
// 	for (auto p = first_free; p != elements;)
// 	    alloc.destroy(--p);
// 	alloc.deallocate(elements, cap - elements);
//     }
// }
inline void StrVec::free()
{
    for_each(elements, first_free, [this](std::string &rhs) { alloc.destroy(&rhs); })
}
inline StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
inline StrVec::~StrVec() { free(); }
inline StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
inline void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
	alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}
inline void StrVec::reserve(size_t new_cap)
{
    if (new_cap <= capacity())
	return;
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
	alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}
inline void StrVec::resize(size_t count, const std::string &s)
{
    if (count <= size())
    {
	//auto pcount=elements+count;
	//for(;first_free!=pcount;first_free--)
	//alloc.destroy(first_free);
	while (first_free != elements + count)
	    alloc.destroy(--first_free);
    }
    else
    {
	if (count > capacity())
	    reserve(count * 2);
	for (size_t i = size(); i != count; i++)
	    alloc.construct(first_free++, s);
    }
}
inline void StrVec::resize(size_t count)
{
    resize(count, std::string());
}
inline StrVec::StrVec(std::initializer_list<std::string> s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
#endif
