struct monotonic_queue
{
  deque<int> dq;
  void insert(int x)
  {
    while (!dq.empty() and dq.back() > x) dq.pop_back();
    dq.push_back(x);
  }
  void remove (int x)
  {
    if (!dq.empty() and dq.front() == x) dq.pop_front();
  }
  int get_min()
  {
    if (!dq.empty()) return dq.front();
    return 0;
  }
};
