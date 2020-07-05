#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Endpoint
{
    int value;
    bool isStart;

    Endpoint(int value, bool isStart)
        : value(value), isStart(isStart)
    {
    }

    Endpoint(const Endpoint &that)
        : value(that.value), isStart(that.isStart)
    {
    }

    bool operator<(const Endpoint &that) const { return value < that.value; };
};

struct Event
{
    int start, end;

    Event(int start, int end)
        : start(start), end(end)
    {
    }
};

int XAxisHeight(vector<Event> events)
{
    vector<Endpoint> endpoints{};

    for (const Event &e : events)
    {
        endpoints.push_back(Endpoint{e.start, true});
        endpoints.push_back(Endpoint{e.end, false});
    }

    sort(endpoints.begin(), endpoints.end());

    int height = 0;
    int sub_height = 0;

    for (const Endpoint &e : endpoints)
    {
        cout << "endpoint: " << e.value << '\n';
        if (e.isStart)
            sub_height++;
        else
            sub_height--;

        if (sub_height > height)
            height = sub_height;
    }

    return height;
}

int main()
{
    vector<Event> events = {Event{1, 5}, Event{2, 7}, Event{4, 5}, Event{6, 10}, Event{8, 9}, Event{9, 17}, Event{11, 13}, Event{12, 15}, Event{14, 15}};

    cout << XAxisHeight(events);
}