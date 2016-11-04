#include <set>
#include <string>
#include <algorithm>
class Floder;
class Message
{
    friend class Flolder;

  public:
    explicit Message(const std::string &str = " ") : contents(str) {}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();
    void save(Floder &);
    void remove(Floder &);
    void swap(Message &lhs, Message &rhs);
    
  private:
    std::string contents;
    std::set<Floder *> floders;
    void add_to_Floders(const Message &);
    void remove_from_Floders();
};
class Floder
{
    friend class Message;

  public:
    Floder() = default;
    Floder(const Floder &);
    Floder &operator=(const Floder &);
    ~Floder() {}
  private:
    std::set<Message *> mes;
    void addMsg(Message *m) { mes.insert(m); }
    void remMsg(Message *m) { mes.erase(m); }
  private:
};
void Message::swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.floders)
        f->remMsg(&lhs);
    for (auto f : rhs.floders)
        f->remMsg(&rhs);
    swap(lhs.floders, rhs.floders)
        swap(lhs.contents, rhs.contents) for (auto f : lhs.floders)
            f->addMsg(&lhs);
    for (auto f : rhs.floders)
        f->addMsg(&rhs);
}
void Message::save(Floder &f)
{
    floders.insert(&f);
    f.addMsg(this);
}
void Message::remove(Floder &f)
{
    floders.erase(&f);
    f.remMsg(this);
}
void Message::add_to_Floders(const Message &m)
{
    for (auto f : m.floders)
        f->addMsg(this);
}
Message::Message(const Message &m) : contents(m.contents), floders(m.floders)
{
    add_to_Floders(m);
}
void Message::remove_from_Floders()
{
    for (auto f : floders)
        f->remMsg(this);
}
Message::~Message()
{
    remove_from_Floders();
}
Message &Message::operator=(const Message &rhs)
{
    remove_from_Floders();
    contents = rhs.contents;
    floders = rhs.floders;
    add_to_Floders(rhs);
    return *this;
}
int main()
{
    return 0;
}